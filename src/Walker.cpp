#include "Walker.h"


bool Walker::verbosity = 1;


Walker::Walker(ParticleSet *p, rapidxml::xml_node<> *node)
{
   using namespace std;
   using namespace rapidxml;
   using namespace xml;
   
   //Store the address to the Particle Set which contains physical informations related to this walker
   _particle_set = p;
   
   //Get InitialPosition
   string initial_position;
   CatchFirstAttributeValue(node,"InitialPosition",initial_position);
   if (verbosity) cout << "\t\t\t -> InitialPosition = " << initial_position << ". " << endl;
   
   //Allocate the positions
   _r = new double*[this->_particle_set->getNPart()];
   for (int i1=0; i1<this->_particle_set->getNPart(); ++i1)
   {
      _r[i1] = new double[this->_particle_set->getPhysicalSystem()->getNDim()];
   }
   
   //Set the initial positions
   this->initializePosition(initial_position);
}


void Walker::initializePosition(const std::string &position)
{
   using namespace std;
      
   if (position=="origin")
   {
      for (int i1=0; i1<this->_particle_set->getNPart(); ++i1)
      {
         for (int i2=0; i2<this->_particle_set->getPhysicalSystem()->getNDim(); ++i2)
         {
            _r[i1][i2] = 0.;  
         }
      } 
   }
   else
   {
      stringstream error_message;
      error_message << "ERROR: Walker::InitializePosition - Poistion of the walkers \"" << position << "\" is not known.";
      throw err::MyException(error_message.str().c_str(),strlen(error_message.str().c_str()));
   }
}