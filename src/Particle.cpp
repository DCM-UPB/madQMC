#include "Particle.h"


Particle::Particle(const double &m, const short int &s, const short int &ndim, const double *v)
{
   mass=m; spin=s; position=new double[ndim]; 
   for (int i=0; i<ndim; ++i)
   {
      position[i]=v[i];
   }
}


Particle::Particle(const SimulationBox &)
{
   
}
