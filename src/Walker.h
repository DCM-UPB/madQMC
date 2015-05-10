#ifndef WALKER
#define WALKER


#include "ParticleSet.h"
#include "WalkerTracker.h"

#include <string>
#include <iostream>
#include <vector>


class ParticleSet;
class WalkerTracker;


class Walker
{
   protected:
      
      //Parameters
      double **_r;
      
      //Pointers to related informations
      ParticleSet *_particle_set;
      std::vector<WalkerTracker> *_trackers;
      
      
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
      
      //Getters
      ParticleSet * getParticleSet() {return _particle_set;}
      
      //Notify changes to the wave functions components
      void notifyChanges(const unsigned short int &, const unsigned short int &);
      
};


#endif
