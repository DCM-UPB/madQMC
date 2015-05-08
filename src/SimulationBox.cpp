#include "SimulationBox.h"


SimulationBox::SimulationBox(const PhysicalSystem *ps) throw(std::exception)
{
   _L=new double[ps->_n_dim];
   //calculate the box side assuming that each side is equal
   double box_side = pow( double(ps->_n_part_tot)/ps->_rho , 1./double(ps->_n_dim) );
   //set the box sides
   for (int i1=0; i1<ps->_n_dim; ++i1)
   {
      _L[i1]=box_side;
   }
   _phys_syst=ps;
}


SimulationBox::SimulationBox(const PhysicalSystem *ps, const double *ratio) throw(std::exception)
{   
   _L=new double[ps->_n_dim];
   //calculate the box side assuming that each side is equal
   double box_side = pow( double(ps->_n_part_tot)/ps->_rho , 1./double(ps->_n_dim) );
   //check if the provided ratio is correct
   double actual_ratio=ratio[0];
   for (int i1=1; i1<ps->_n_dim; ++i1)
   {
      actual_ratio*=ratio[i1];
   }
   if ( !AlmostEqualDouble(actual_ratio,1.) )
   {
      std::stringstream error_message;
      error_message << "ERROR: SimulationBox::SimulationBox - The product of the ratio elements was not equal to 1, as expected, but " << actual_ratio << ".";
      throw err::MyException(error_message.str().c_str(),std::strlen(error_message.str().c_str()));
   }
   //set the box sides
   for (int i1=0; i1<ps->_n_dim; ++i1)
   {
      _L[i1]=box_side*ratio[i1];
   }
   _phys_syst=ps;
}


double SimulationBox::GetL(const unsigned short int &i) throw(std::exception)
{
   if ( (i >= _phys_syst->_n_dim) || (i < 0) )
   {
      std::string error_message="ERROR: SimulationBox::GetL - Index out of boundaries";
      throw err::MyException(error_message.c_str(),std::strlen(error_message.c_str()));
   }
   return _L[i];
}


void SimulationBox::SetL(const double &l, const unsigned short int &i)
{
   if ( (i >= _phys_syst->_n_dim) || (i < 0) )
   {
      std::string error_message="ERROR: SimulationBox::SetL - Index out of boundaries";
      throw err::MyException(error_message.c_str(),std::strlen(error_message.c_str()));
   }
   _L[i]=l;
}
