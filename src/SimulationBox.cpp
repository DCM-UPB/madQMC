#include "SimulationBox.h"


bool SimulationBox::verbosity = 1;


SimulationBox::SimulationBox(PhysicalSystem *ps, const char *filename) throw(std::exception)
{
   using namespace rapidxml;
   using namespace std;
   using namespace xml;
   
   // Store the pointer to the physical system
   _physical_system=ps;

   // Get the root node from the file
   if (verbosity) cout << "[SimulationBox] >   " << "Load information about the simulation box from the file " << filename << " ..." << endl;
   xml_node<> *root_xmlnode = CatchFirstNodeFromFile(filename,user_input::keyname_simulation_box.c_str());
   
   // Get from the input file the periodic boundary conditions flag
   CatchFirstAttributeValue(root_xmlnode,"PBC",_pbc);
   if (verbosity) cout << "[SimulationBox] >   " <<"PBC = " << _pbc << ";   ";
   
   if (_pbc)
   {
      // Get the ratio from the input file the ratio between the sides
      double *ratio = new double[_physical_system->getNDim()];
      xml_node<> *sides_ratio = root_xmlnode->first_node("SidesRatio");
      CatchAllSubnodesValues(sides_ratio,"Ratio",ratio);
      for (int i1=0; i1<_physical_system->getNDim(); ++i1)
      {
         if (verbosity) cout << "Ratio[" << i1 << "] = " << ratio[i1] << ";   ";
      }
      if (verbosity) cout << endl;
   
      //Check the ratio
      this->checkRatio(ratio);
   
      // Allocate L
      _L=new double[_physical_system->getNDim()];
   
      // Calculate the box side assuming that each side is equal
      double box_side = pow( double(_physical_system->getNPartTot())/_physical_system->getRho() , 1./double(_physical_system->getNDim()) );
   
      // Set the box sides
      if (verbosity) cout << "[SimulationBox] >   ";
      for (int i1=0; i1<_physical_system->getNDim(); ++i1)
      {
         _L[i1]=box_side*ratio[i1];
         if (verbosity) cout << "L[" << i1 << "] = " << _L[i1] << ";   ";
      }
      if (verbosity) cout << endl;
   }
   else
   {
      if (verbosity) cout << endl << "[SimulationBox] >   Since Periodic Boundary Conditions do not apply, the sides of the box are irrelevant. The walkers will be free." << endl;
   }
   
}


void SimulationBox::checkRatio(const double *ratio)
{
   double actual_ratio = ratio[0];
   for (int i1=1; i1<_physical_system->getNDim(); ++i1)
   {
      actual_ratio*=ratio[i1];
   }
   if ( !AlmostEqualDouble(actual_ratio,1.) )
   {
      std::stringstream error_message;
      error_message << "ERROR: SimulationBox::SimulationBox - The provided ratio was not acceptable, since the product of the ratio elements was " << actual_ratio << ", and not 1, as expected.";
      throw err::MyException(error_message.str().c_str(),std::strlen(error_message.str().c_str()));
   }
}


double SimulationBox::getL(const unsigned short int &i) throw(std::exception)
{
   if ( (i >= _physical_system->getNDim()) || (i < 0) )
   {
      std::string error_message="ERROR: SimulationBox::GetL - Index out of boundaries";
      throw err::MyException(error_message.c_str(),std::strlen(error_message.c_str()));
   }
   return _L[i];
}


void SimulationBox::setL(const double &l, const unsigned short int &i)
{
   if ( (i >= _physical_system->getNDim()) || (i < 0) )
   {
      std::string error_message="ERROR: SimulationBox::SetL - Index out of boundaries";
      throw err::MyException(error_message.c_str(),std::strlen(error_message.c_str()));
   }
   _L[i]=l;
}
