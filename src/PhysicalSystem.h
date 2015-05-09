#ifndef PHYSICAL_SYSTEM
#define PHYSICAL_SYSTEM


#include <iostream> //possible to remove after debugging
#include <sstream>
#include <string>
#include <exception>
#include "../rapidxml/rapidxml.hpp"

#include "Walker.h"
#include "ParticleSet.h"

class ParticleSet;


class PhysicalSystem
{
   protected:
      
      //Parameters
      unsigned short int _n_dim;
      unsigned short int _n_kind_part;
      unsigned short int _n_part_tot;
      double _rho;
      
      //Pointers to related informations
      ParticleSet *_part_set;


   public:
      
      //Class parameters
      static bool verbosity;
      
      //Constructor
      PhysicalSystem(): _n_dim(0), _n_kind_part(0), _n_part_tot(0), _rho(0) {}
      PhysicalSystem(const char *);
      
      //Destructor
      ~PhysicalSystem() {_n_dim=0; _n_kind_part=0; _n_part_tot=0; _rho=0.;}

      //Getter
      unsigned short int getNDim() {return _n_dim;}
      unsigned short int getNKindPart() {return _n_kind_part;}
      unsigned short int getNPartTot() {return _n_part_tot;}
      double getRho() {return _rho;}

      //Setter
      void setNDim(const unsigned short int &n) {_n_dim=n;}
      void setNKindPart(const unsigned short int &n) {_n_kind_part=n;}
      void setNPartTot(const unsigned short int &n) {_n_part_tot=n;}
      void setRho(const double r) {_rho=r;}
      
};

#endif
