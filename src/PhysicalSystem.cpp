#include "PhysicalSystem.h"


bool PhysicalSystem::verbosity = 1;


PhysicalSystem::PhysicalSystem(const char *filename)
{
   using namespace rapidxml;
   using namespace std;
   using namespace xml;

   // Get the root node from the file
   if (verbosity) cout << "[PhysicalSystem] >   " << "Load information about the physical system from the file " << filename << " ..." << endl;
   xml_node<> *root_xmlnode = CatchFirstNodeFromFile(filename,user_input::keyname_physical_system.c_str());
   
   // Get Ndim
   CatchFirstAttributeValue(root_xmlnode,"NDim",_n_dim);
   if (verbosity) cout << "[PhysicalSystem] >   " << "NDim = " << _n_dim << ";   ";
   
   // Get Rho
   CatchFirstAttributeValue(root_xmlnode,"Rho",_rho);
   if (verbosity) cout << "Rho = " << _rho << ";   " << endl;
   
   // Get the node that contains all the particles set
   xml_node<> *particleset_xmlnode = root_xmlnode->first_node(user_input::keyname_particle_set.c_str());
   //Iterate through all the particle sets and count them
   _n_kind_part=0;
   for (xml_node<> *child = particleset_xmlnode->first_node(); child!=0; child=child->next_sibling() )
   {
      _n_kind_part++;
   }
   if (verbosity) cout << "[PhysicalSystem] >   " << "Number of Different Kinds of Particles = " << _n_kind_part << endl;
   
   //Allocate the array of particle set
   _part_set = new ParticleSet[_n_kind_part];
   //Iterate through all the particle sets and initialize them
   int i=0;
   for (xml_node<> *child = particleset_xmlnode->first_node(); child!=0; child = child->next_sibling())
   {
      _part_set[i] = ParticleSet(this,child);      
      i++;
   }
   //Compute and store the total number of particles
   _n_part_tot=0;
   for (int i1=0; i1<_n_kind_part; ++i1)
   {
      _n_part_tot+=_part_set[i1].getNPart();
   }
   if (verbosity) cout << "[PhysicalSystem] >   " << "Total Number of Particles in the System = " << _n_part_tot << "." << endl;
}


