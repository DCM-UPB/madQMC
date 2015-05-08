#include "ParticleSet.h"


ParticleSet::ParticleSet(rapidxml::xml_node<> *node)
{
   using namespace std;
   
   _name = string(node->name());
   cout << "[ParticleSet] > " << "Load Particle Set \"" << _name << "\"... ";
   CatchXmlSubNodeValue(node,"NPart",_n_part);
   cout << "NPart = " << _n_part << "; ";
   CatchXmlSubNodeValue(node,"NHalfSpin",_n_half_spin);
   cout << "NHalfSpin = " << _n_half_spin << ". " << endl;
}