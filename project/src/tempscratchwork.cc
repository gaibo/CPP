trans = eta * transmission(gamma1, (EF+eta*e*V), epsilon) + (1-eta) * transmission(gamma1, (EF+(eta-1)*e*V), epsilon)

double transmission(double gamma, double E, double epsilon)
{
	return (		4 * gamma*gamma /
				((E - epsilon)*(E - epsilon) + gamma*gamma)		);
}
