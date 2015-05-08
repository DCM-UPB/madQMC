#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <sstream>
#include "Constants.h"
#include "PhysicalSystem.h"
#include "NumericalUtilities.h"
#include "ErrorHandling.h"

#ifndef SIMULATION_BOX
#define SIMULATION_BOX

class SimulationBox
{
   protected:
      double *_L;
      const PhysicalSystem *_phys_syst;

   public:
      //   Constructor:
      SimulationBox(const PhysicalSystem *ps) throw(std::exception);
      SimulationBox(const PhysicalSystem *ps, const double *ratio) throw(std::exception);

      //   Destructor:
      ~SimulationBox(){delete[] _L; _L=0; _phys_syst=0;}
      
      //   Getter:
      double GetL(const unsigned short int &) throw(std::exception);
      const PhysicalSystem * GetPhysicalSystem() {return _phys_syst;}

      //   Setter:
      void SetL(const double &, const unsigned short int &);

};



#endif
