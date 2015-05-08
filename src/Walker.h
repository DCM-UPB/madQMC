#include "Particle.h"

#ifndef WALKER
#define WALKER

class Walker
{
   protected:
      Particle* part;
   public:
      //Constructor
      Walker(const unsigned int Npart){part=new Particle[Npart];}
      //Destructor
      ~Walker(){delete[] part;}
};

#endif
