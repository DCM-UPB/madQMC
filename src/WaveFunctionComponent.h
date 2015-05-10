#ifndef WAVE_FUNCTION_COMPONENT
#define WAVE_FUNCTION_COMPONENT


#include "Walker.h"
#include "WalkerTracker.h"

#include "../rapidxml/rapidxml.hpp"


template <class T>
class WaveFunctionComponent
{
   protected:
      
      // Array of pointers to the walkers which provide the input for the wave function
      Walker **_walker;
      // Array of pointers to the corresponding walker trackers
      WalkerTracker **_walker_tracker;
      
      
   public:
            
      // Wave Function Component Values
      virtual T getValue()=0;
      virtual T getFirstDerivative(const unsigned short int &particle_index, const unsigned short int &axis_index)=0;
      virtual T getSecondDerivative(const unsigned short int &particle_index, const unsigned short int &axis_index)=0;
      
      // Variational derivatives
      virtual T getVarationalFirstDerivative(const unsigned int &parameter_index)=0;
      virtual T getVarationalSecondDerivative(const unsigned int &parameter_index)=0;
      
      // Update
      virtual void syncWithWalkers()=0;
};


#endif