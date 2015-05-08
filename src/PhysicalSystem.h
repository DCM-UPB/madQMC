#include <iostream> //possible to remove after debugging
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#include "../rapidxml/rapidxml.hpp"
#include "FileUtilities.h"
#include "Constants.h"
#include "ParticleSet.h"

#ifndef PHYSICAL_SYSTEM
#define PHYSICAL_SYSTEM

class PhysicalSystem
{
   protected:
      
      //Parameters
      unsigned short int _n_dim;
      unsigned short int _n_kind_part;
      unsigned short int _n_part_tot;
      double _rho;
      ParticleSet *_part_set;


   public:
      
      //Constructor
      PhysicalSystem() {_n_dim=0; _n_kind_part=0; _n_part_tot=0; _rho=0.;}
      PhysicalSystem(const char *);
      
      //Destructor
      ~PhysicalSystem() {_n_dim=0; _n_kind_part=0; _n_part_tot=0; _rho=0.;}

      //Getter
      unsigned short int GetNdim() {return _n_dim;}
      unsigned short int GetNkindpart() {return _n_kind_part;}
      unsigned short int GetNparttot() {return _n_part_tot;}
      double GetRho() {return _rho;}

      //Setter
      void SetNdim(const unsigned short int &n) {_n_dim=n;}
      void SetNkindpart(const unsigned short int &n) {_n_kind_part=n;}
      void SetNparttot(const unsigned short int &n) {_n_part_tot=n;}
      void SetRho(const double r) {_rho=r;}
      
      //Friends
      friend class SimulationBox;
};

#endif
