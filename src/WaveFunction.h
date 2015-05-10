#ifndef WAVE_FUNCTION
#define WAVE_FUNCTION


#include "../rapidxml/rapidxml.hpp"

#include "WaveFunctionComponent.h"


template <class T>
class WaveFunction
{
   protected:
      
      //List of components: The wave function is a product of them
      WaveFunctionComponent<T> *wf_comp;
      
      
   public:
      
      //Constructors
      WaveFunction(rapidxml::xml_node<> *);
      WaveFunction(const char *);
      
      //Destructors
      ~WaveFunction() {}
         
      //Getters
      T getValue();
      T getFirstDerivative();
      T getSecondDerivative();
      
};


#endif