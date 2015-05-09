#ifndef PARTICLE_SET
#define PARTICLE_SET


#include "FileUtilities.h"
#include "PhysicalSystem.h"

#include <string>


class PhysicalSystem;
class Walker;


class ParticleSet
{
   protected:
      
      //Parameters
      std::string _name;
      unsigned short int _n_part;
      unsigned short int _n_half_spin;
      
      //Pointers to related informations
      PhysicalSystem *_physical_system;
      Walker *_walker;
      
      
   public:
      
      //Class parameters
      static bool verbosity;
      
      //Constructors
      ParticleSet(): _name(""), _n_part(0), _n_half_spin(0) {}
      ParticleSet(PhysicalSystem *, rapidxml::xml_node<> *);
      
      //Destructors
      ~ParticleSet() { _name=""; _n_part=0; _n_half_spin=0;}
      
      //Getter
      std::string getName() {return _name;}
      unsigned short int getNPart() {return _n_part;}
      unsigned short int getNHalfSpin() {return _n_half_spin;}
      PhysicalSystem * getPhysicalSystem() {return _physical_system;}
      
      //Setter
      void setVerbosity(bool v) {verbosity=v;}
};


#endif