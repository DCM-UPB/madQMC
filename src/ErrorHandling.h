#ifndef ERROR_HANDLING
#define ERROR_HANDLING


#include <exception>
#include <iostream>
#include "Constants.h"


namespace err
{
   //Exit on error
   void Stop(const char *) throw();

   //Exception class which might stop the execution of the code (according to cnst::EXIT_ON_ERROR)
   class MyException: public std::exception
   {
      private:
         char *message;
      public:
         //Constructor
         MyException(const char * m, const int &n):
            exception()
         {
            message=new char[n];
            for (int i1=0; i1<n; ++i1)
            {
               message[i1]=m[i1];
            }
            if (code_behaviour::EXIT_ON_ERROR) Stop(message);
         }
         //Destructor
         ~MyException(){delete[] message;}
         //what virtual function
         virtual const char * what() const throw() {return message;}
   };

}

#endif
