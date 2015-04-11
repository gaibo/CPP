CPP=g++

# Compile on MAC
#GSL_DIR=/opt/local

# Compile on linux, where GSL is in /usr/...
GSL_DIR=/usr/local
GSL_LIB=$(GSL_DIR)/lib
GSL_INCLUDE=$(GSL_DIR)/include

CFLAGS=-O2 -Wall -I$(GSL_INCLUDE)
LIBS=-L$(GSL_LIB) -lgsl -lgslcblas -lm

all: simulator binner binner-v-2d sim-v-1d sim-v-2d sim-v-2d-rng sim-v-2d-betad sim-v-2d-updated final-sim-v-2d final-binner-v-2d
	cp simulator binner binner-v-2d sim-v-1d sim-v-2d sim-v-2d-rng sim-v-2d-betad sim-v-2d-updated final-sim-v-2d final-binner-v-2d ../bin

simulator: main-simulator.cc
	$(CPP) -o simulator main-simulator.cc \
		$(CFLAGS) $(LIBS)

sim-v-1d: main-simulator-v-1d.cc
	$(CPP) -o sim-v-1d main-simulator-v-1d.cc \
		$(CFLAGS) $(LIBS)

sim-v-2d: main-simulator-v-2d.cc
	$(CPP) -o sim-v-2d main-simulator-v-2d.cc \
		$(CFLAGS) $(LIBS)

sim-v-2d-rng: main-simulator-v-2d-rng.cc
	$(CPP) -o sim-v-2d-rng main-simulator-v-2d-rng.cc \
		$(CFLAGS) $(LIBS)

sim-v-2d-betad: main-simulator-v-2d-rng-betad.cc
	$(CPP) -o sim-v-2d-betad main-simulator-v-2d-rng-betad.cc \
		$(CFLAGS) $(LIBS)

sim-v-2d-updated: main-updated-simulator-v-2d.cc
	$(CPP) -o sim-v-2d-updated main-updated-simulator-v-2d.cc \
		$(CFLAGS) $(LIBS)

binner: main-binner.cc
	$(CPP) -o binner main-binner.cc $(CFLAGS) $(LIBS)
	
binner-v-2d: main-binner-v-2d.cc
	$(CPP) -o binner-v-2d main-binner-v-2d.cc $(CFLAGS) $(LIBS)
	
final-sim-v-2d: final-main-simulator-v-2d.cc
	$(CPP) -o final-sim-v-2d final-main-simulator-v-2d.cc \
		$(CFLAGS) $(LIBS)
		
final-binner-v-2d: final-main-binner-v-2d.cc
	$(CPP) -o final-binner-v-2d final-main-binner-v-2d.cc \
		$(CFLAGS) $(LIBS)

#fitter: main-fitter.cc models.h model-asymmetric-resonant.h model-asymmetric-resonant.cc model-symmetric-nonresonant.h model-symmetric-nonresonant.cc model-symmetric-resonant.h model-symmetric-resonant.cc
#	$(CPP) -o fitter main-fitter.cc model-asymmetric-resonant.cc model-symmetric-nonresonant.cc model-symmetric-resonant.cc $(CFLAGS) $(LIBS)

clean:
	rm -f *.o simulator binner fitter

distclean:
	rm -f *.o simulator binner fitter ../bin/simulator ../bin/binner ../bin/fitter
