/*
This work is licensed under the Creative Commons Attribution 3.0 United States
License. To view a copy of this license, visit
http://creativecommons.org/licenses/by/3.0/us/ or send a letter to Creative
Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.

Copyright (C) 2013 Oak Ridge National Laboratory
*/
/**
 * \file main-simulator.cc
 * \brief Main function for simulating conductance data using Landauer theory.
 *
 * Statistical parameters (for example, the average level energy) are provided
 * on the command-line and used to simulate conductance data. This data can
 * subsequently be binned into a histogram to test the fitting procedures.
 *
 * Two models are presently implemented:
 *    - Symmetric couplings (same coupling used for the left and right leads).
 *    - Asymmetric couplings (different couplings for the two leads).
 *
 * There are seven or eight required command-line arguments, depending on the
 * model:
 *    -# The model to use (`s' for symmetric, `a' for asymmetric).
 *    -# The number of conductance data points to simulate.
 *    -# The Fermi level of the system (eV)
 *    -# The standard deviation in site level energy (eV)
 *    -# The average site level energy (eV)
 *    -# The standard deviation in electrode-channel coupling (eV)
 *    -# The average coupling to one electrode (asymmetric model) or to both
 *       electrodes (symmetric model), in eV.
 *    -# The average coupling to the other electrode (eV). Only required if the
 *       asymmetric model is used.
 *
 * \author Patrick D.\ Williams and Matthew G.\ Reuter
 * \date July 2012, May 2013
 */

#include <cstdio>
#include <cstdlib>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

/**
 * \brief Samples from a normal distribution with the given mean and standard
 *        deviation.
 *
 * \param[in] mean The distribution's average.
 * \param[in] stdev The distribution's standard deviation.
 * \param[in] r The internal workspace for GSL's random number generation.
 * \return The random number.
 */
double normal_random_variable(double mean, double stdev, gsl_rng *r);

/**
 * \brief Evalutates the transmission (Landauer theory) using the specified
 *        physical parameters.
 * 
 * \param[in] gamma1 One channel-lead coupling.
 * \param[in] gamma2 The other channel-lead coupling.
 * \param[in] epsilon The channel's level energy.
 * \param[in] EF The Fermi level.
 * \return The transmission.
 */
double transmission(double gamma, double epsilon, double E);

/**
 * \brief Main function for simulating a histogram.
 *
 * Parses the input parameters and outputs randomly-generated conductance
 * data.
 *
 * \param[in] argc The number of command-line arguments.
 * \param[in] argv The command-line arguments.
 * \return Exit status; 0 for normal.
 */
int main(int argc, char **argv) {
	const gsl_rng_type *T;
	gsl_rng *r;
     
	int i, n;
	double EF;
	double depsilon;
	double epsilon0;
	double dgamma;
	double gamma0;
	double Vmin, Vmax;
	double eta_alpha, eta_beta;
	double gamma, epsilon, V, eta, trans;

	if (argc != 11) {
		fprintf(stderr,
			"Usage error: ./sim-v-2d-betad n EF depsilon epsilon0 dgamma \n" \
			"                 gamma0 Vmin Vmax eta_alpha eta_beta\n" \
			"   n is the number of trials\n" \
			"   EF is the Fermi level (eV)\n" \
			"   depsilon is the standard deviation in site level energy (eV)\n" \
			"   epsilon0 is the average site level energy (eV)\n" \
			"   dgamma is the standard deviation in the coupling (eV)\n" \
			"   gamma0 is the average coupling for one electrode (eV)\n" \
			"   Vmin is the lower bound of the applied bias range (V)\n" \
			"   Vmax is the upper bound of the applied bias range (V)\n" \
			"   eta_alpha and eta_beta are the parameters of the beta distribution\n" \
			"      here varying eta, the relative voltage drop for one electrode\n\n" \
			"NOTE: symmetric model is assumed - coupling is the same for both electrodes.\n");
		return 0;
	}

	n = atoi(argv[1]);
	EF = atof(argv[2]);
	depsilon = atof(argv[3]);
	epsilon0 = atof(argv[4]);
	dgamma = atof(argv[5]);
	gamma0 = atof(argv[6]);
	Vmin = atof(argv[7]);
	Vmax = atof(argv[8]);
	eta_alpha = atof(argv[9]);
	eta_beta = atof(argv[10]);

	if (depsilon <= 0.0 || dgamma <= 0.0) {
		fprintf(stderr, "Error: standard deviations must be positive.\n");
		return 0;
	}

	if (gamma0 <= 0.0) {
		fprintf(stderr, "Error: gamma0 must be positive.\n");
		return 0;
	}

	if (n <= 0) {
		fprintf(stderr, "Error: There must be at least one trial.\n");
		return 0;
	}

	if (gamma0 / dgamma < 4.0) {
		fprintf(stderr, "Warning: The model assumes gamma0 / dgamma >> 0; " \
			"bigger than 4, in practice.\n");
	}
	
	if (Vmin > Vmax) {
		fprintf(stderr, "Error: Vmin is lower bound, Vmax is upper bound; " \
			"Vmax > Vmin.\n");
		return 0;
	}

	if (eta_alpha <= 1.0 || eta_beta <= 1.0) {
		fprintf(stderr, "Warning: Model assumes beta distribution is unimodal; " \
			"eta_alpha, eta_beta > 1.\n");
	}

	// Setup the GSL random number generator
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc(T);

	// Seed the generator
	gsl_rng_set(r, 0xFEEDFACE);

	// Get the requested number of voltage-transmission sets
	for (i = 0; i < n; ++i) {
		epsilon = normal_random_variable(epsilon0, depsilon, r);
		gamma = normal_random_variable(gamma0, dgamma, r);
		V = Vmin + gsl_rng_uniform(r) * (Vmax - Vmin);
		eta = gsl_ran_beta(r, eta_alpha, eta_beta);

		trans = eta * transmission(gamma, epsilon, (EF+eta*V)) 
			+ (1.0-eta) * transmission(gamma, epsilon, (EF+(eta-1.0)*V));

		printf("%.6f %.6f\n", V, trans);
	}

	gsl_rng_free(r);
	return 0;
}

double normal_random_variable(double mean, double stdev, gsl_rng *r) {
	return gsl_ran_gaussian(r, stdev) + mean;
}

double transmission(double gamma, double epsilon, double E) {		// E here is energy of the electron
	return gamma*gamma / 
		((E-epsilon)*(E-epsilon) + gamma*gamma);
}
