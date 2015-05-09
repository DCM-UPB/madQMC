#ifndef SIMULATION_BOX
#define SIMULATION_BOX


#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <sstream>

#include "PhysicalSystem.h"
#include "NumericalUtilities.h"


class SimulationBox
{
   protected:
      
      //Parameters
      double *_L;
      bool _pbc;
      
      //Pointers to related informations
      PhysicalSystem *_physical_system;


   public:
      
      //Class parameters
      static bool verbosity;
      
      //   Constructor:
      SimulationBox(PhysicalSystem *, const char *) throw(std::exception);

      //   Destructor:
      ~SimulationBox(){_L=0; _physical_system=0;}
      
      //Checks
      void checkRatio(const double *);
      
      //   Getter:
      double getL(const unsigned short int &) throw(std::exception);
      PhysicalSystem * getPhysicalSystem() {return _physical_system;}

      //   Setter:
      void setL(const double &, const unsigned short int &);

      
};



#endif
