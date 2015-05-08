#include "SimulationBox.h"

#ifndef PARTICLE
#define PARTICLE

class Particle
{
   protected:
      double mass;
      short int spin;
      double *position;
   public:
      //Constructor
      Particle(){mass=0; spin=0; position=0;}
      Particle(const double &, const short int &, const short int &, const double *);
      Particle(const SimulationBox &);
      //Destructor
      ~Particle(){mass=0; spin=0; position=0;}
};

#endif
