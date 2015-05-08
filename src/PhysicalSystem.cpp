#include "PhysicalSystem.h"


PhysicalSystem::PhysicalSystem(const char *filename)
{
   using namespace rapidxml;
   using namespace std;

   //Open the file that contains the informations
   cout << "[PhysicalSystem] > " << "Load information about the physical system from the file " << filename << " ..." << endl;
   ifstream inputfile(filename);
   
   // Read the xml file into a vector
   vector<char> buffer((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
   buffer.push_back('\0');
   
   // Parse the buffer using the xml file parsing library into doc
   xml_document<> xmldoc;
   xmldoc.parse<0>(&buffer[0]);
   
   // Find the root node
   xml_node<> *root_xmlnode = xmldoc.first_node(inputfile::keyname_physical_system.c_str());
   
   // Get Ndim
   CatchXmlSubNodeValue(root_xmlnode,"NDim",_n_dim);
   cout << "[PhysicalSystem] > " <<"Ndim = " << _n_dim << "; ";
   // Get Rho
   CatchXmlSubNodeValue(root_xmlnode,"Rho",_rho);
   cout << "Rho = " << _rho << "; " << endl;
   
   // Get the node that contains all the particles set
   xml_node<> *particleset_xmlnode = root_xmlnode->first_node(inputfile::keyname_particle_set.c_str());
   //Iterate through all the particle sets and count them
   _n_kind_part=0;
   for (xml_node<> *child = particleset_xmlnode->first_node(); child!=0; child=child->next_sibling() )
   {
      _n_kind_part++;
   }
   cout << "[PhysicalSystem] > " << "Number of Different Kinds of Particles = " << _n_kind_part << endl;
   
   //Allocate the array of particle set
   _part_set=new ParticleSet[_n_kind_part];
   //Iterate through all the particle sets and initialize them
   int i=0;
   for (xml_node<> *child = particleset_xmlnode->first_node(); child!=0; child = child->next_sibling())
   {
      _part_set[i]=ParticleSet(child);
      i++;
   }
   //Compute and store the total number of particles
   _n_part_tot=0;
   for (int i1=0; i1<_n_kind_part; ++i1)
   {
      _n_part_tot+=_part_set[i1].GetNPart();
   }
   cout << "[PhysicalSystem] > " << "Total Number of Particles in the System = " << _n_part_tot << "." << endl;
}


