#ifndef WALKER_TRACKER
#define WALKER_TRACKER


#include "Walker.h"

class Walker;


class WalkerTracker
{
   protected:
      
      //Pointer to the walker tracked
      Walker *_walker;
      
      //Array of the particle in _walker->_r that have been moved since last sync (1=moved, 0=not moved)
      bool *_moved_particle;
      
      
   public:
      
      //Constructor
      WalkerTracker(Walker *);
      
      //Destructor
      ~WalkerTracker() {delete[] _moved_particle;};
      
      //Getters
      bool pullParticleMovement(const unsigned short int &i) {return _moved_particle[i];}
      bool pullAllParticleMovement();
         
      //Setters
      void pushParticleMovement(const bool &flag, const unsigned short int &part) {_moved_particle[part] = flag;}
      
      //Getter and Setter to 0
      bool popParticleMovement(const unsigned short int &);
      
};


#endif