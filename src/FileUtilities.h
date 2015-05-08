#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <exception>
#include "../rapidxml/rapidxml.hpp"

#include "ErrorHandling.h"

#ifndef FILE_UTILITIES
#define FILE_UTILITIES

//Catch the value of a xml subnode with specified variable_name
template <class T>
void CatchXmlSubNodeValue(const rapidxml::xml_node<> *root_node, const char *variable_name, T &variable_container)
{
   using namespace std;

   // Get the node to the variable_name
   rapidxml::xml_node<> * node = root_node->first_node(variable_name);
   // If the variable is missing, throw an exception
   if ( node == 0 )
   {
      stringstream error_message;
      error_message << "ERROR: CatchXmlNodeValue - Parameter " << variable_name << " is missing from the xml input file.";
      throw err::MyException(error_message.str().c_str(),strlen(error_message.str().c_str()));
   }
   //extract and store the variable into the variable_container
   stringstream ss;
   ss << node->value();
   ss >> variable_container;
}



#endif
