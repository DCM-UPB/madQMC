#include "WalkerTracker.h"


WalkerTracker::WalkerTracker(Walker *w)
{
   //Store the pointer to the walker to be tracked
   _walker = w;
   
   //Instantiate the matrix _changed_elements
   _moved_particle = new bool[_walker->getParticleSet()->getNPart()];
   for (int i1=0; i1<_walker->getParticleSet()->getNPart(); ++i1)
   {
      _moved_particle[i1] = 0;
   }
}


bool WalkerTracker::pullAllParticleMovement()
{
   bool moved=0;
   int i1=0;
   while (   ( moved==0 ) && ( i1<_walker->getParticleSet()->getNPart() )   )
   {
      moved = moved || _moved_particle[i1];
      i1++;
   }
   return moved;
}


bool WalkerTracker::popParticleMovement(const unsigned short int &part)
{
   bool result = _moved_particle[part];
   _moved_particle[part] = 0;
   return result;
}