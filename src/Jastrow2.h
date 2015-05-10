#ifndef JASTROW_2
#define JASTROW_2


#include "WaveFunctionComponent.h"


// 2-body Jastrow, has the form exp(U), where U=sum(u(i,j)) with u(i,j) a function of the distance between particle i and j
template <class T>
class Jastrow2: public WaveFunctionComponent<T>
{
   protected:
      // Jastrow psuedo-potential values
      T _U;
      T **_u;
      
      // Jastrow psuedo-potential function
      
      
   
   public:
      // Wave Function Component Values
      T getValue()=0;
      T getFirstDerivative(const unsigned short int &particle_index, const unsigned short int &axis_index);
      T getSecondDerivative(const unsigned short int &particle_index, const unsigned short int &axis_index);
      
      // Variational derivatives
      T getVarationalFirstDerivative(const unsigned int &parameter_index);
      T getVarationalSecondDerivative(const unsigned int &parameter_index);
      
      // Update
      virtual void syncWithWalkers();
};


#endif