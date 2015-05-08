#include <string>
#include "../rapidxml/rapidxml.hpp"

#include "FileUtilities.h"


#ifndef PARTICLE_SET
#define PARTICLE_SET

class ParticleSet
{
   protected:
      std::string _name;
      unsigned short int _n_part;
      unsigned short int _n_half_spin;
      
      
   public:
      //Constructors
      ParticleSet(){ _name=""; _n_part=0; _n_half_spin=0; }
      ParticleSet(rapidxml::xml_node<> *);
      
      //Destructors
      ~ParticleSet(){ _name=""; _n_part=0; _n_half_spin=0; }
      
      //Getter
      std::string GetName() {return _name;}
      unsigned short int GetNPart() {return _n_part;}
      unsigned short int GetNHalfSpin() {return _n_half_spin;}
};

#endif