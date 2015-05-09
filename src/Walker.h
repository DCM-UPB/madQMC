#ifndef WALKER
#define WALKER


#include "ParticleSet.h"

#include <string>
#include <iostream>


class ParticleSet;


class Walker
{
   protected:
      
      //Parameters
      double **_r;
      
      //Pointers to related informations
      ParticleSet *_particle_set;
      
      
   public:
      
      //Class parameters
      static bool verbosity;
      
      //Constructors
      Walker() {}
      Walker(ParticleSet *, rapidxml::xml_node<> *);
         
      //Destructors
      ~Walker() {}
      
      //Initialize position
      void initializePosition(const std::string &);
};


#endif
