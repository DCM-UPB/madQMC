#include "ParticleSet.h"


bool ParticleSet::verbosity = 1;


ParticleSet::ParticleSet(PhysicalSystem *ps, rapidxml::xml_node<> *node)
{
   using namespace std;
   using namespace rapidxml;
   using namespace xml;
      
   //Store the address to the Physical System which provide the environment
   _physical_system = ps;
   
   //Get the Name of the Particle Set
   _name = string(node->name());
   if (verbosity) cout << "[ParticleSet] >   " << "Load Particle Set \"" << _name << "\"... ";
   
   //Get NPart
   CatchFirstAttributeValue(node,"NPart",_n_part);
   if (verbosity) cout << "NPart = " << _n_part << ";   ";
   
   //Get NHalfSpin
   CatchFirstAttributeValue(node,"NHalfSpin",_n_half_spin);
   if (verbosity) cout << "NHalfSpin = " << _n_half_spin << ". " << endl;
   
   //Instantiate the Walker
   _walker = new Walker(this,node);
}