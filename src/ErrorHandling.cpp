#include "ErrorHandling.h"

namespace err
{
   void Stop(const char *message) throw()
   {
      std::cout << std::endl << " > > > " << message << " < < <" << std::endl << std::endl;
      exit(EXIT_FAILURE);
   }
}
