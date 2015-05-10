CC=g++-mp-5
OPTFLAG=-O3
CFLAGS=-std=c++11 -I../rapidxml $(OPTFLAG)
EXECUTABLE=madQMC

SOURCES=Jastrow2.cpp WalkerTracker.cpp WaveFunctionComponent.cpp WaveFunction.cpp ParticleSet.cpp FileUtilities.cpp Walker.cpp SimulationBox.cpp PhysicalSystem.cpp NumericalUtilities.cpp ErrorHandling.cpp Constants.cpp

HEAD=$(SOURCES:.cpp=.h)
OBJECTS=$(SOURCES:.cpp=.o) main.o

all: $(EXECUTABLE) $(OBJECTS) $(HEAD) 
	cp $(EXECUTABLE) ../

clean:
	\rm -f *.o $(EXECUTABLE)

print:
	echo "OBJECTS = " $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(HEAD) $(SOURCES)

.cpp.o: $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

