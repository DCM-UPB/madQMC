#ifndef CONSTANTS
#define CONSTANTS


#include <string>


namespace user_input
{
   const std::string filename_physical_system="system.xml";
   const std::string keyname_physical_system="PhysicalSystem";
   const std::string keyname_particle_set="ParticleSet";
   
   const std::string filename_simulation_box="simulation_box.xml";
   const std::string keyname_simulation_box="SimulationBox";
}

namespace code_behaviour
{
   const bool EXIT_ON_ERROR=true;
}

namespace constants
{
   const double EPS=0.1e-10;
}

#endif
