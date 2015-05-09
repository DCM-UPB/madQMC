#include <iostream>
#include <exception>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

#include "Walker.h"
#include "PhysicalSystem.h"
#include "SimulationBox.h"
#include "../rapidxml/rapidxml.hpp"
#include "Constants.h"

int main(int argc, char* argv[])
{

   PhysicalSystem ps(user_input::filename_physical_system.c_str());
   SimulationBox box(&ps,user_input::filename_simulation_box.c_str());

   return 0;
}
