#ifndef FILE_UTILITIES
#define FILE_UTILITIES


#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <exception>
#include "../rapidxml/rapidxml.hpp"

#include "ErrorHandling.h"

namespace xml
{
   
   rapidxml::xml_node<> * CatchFirstNodeFromFile(const char *, const char *);


   template <class T>
   void CatchAllSubnodesValues(const rapidxml::xml_node<> *node, const char *variable_name, T *variable_container)
   {
      using namespace std;
      using namespace rapidxml;
      // Get the node to the first variable_name
      xml_node<> *first_child = node->first_node(variable_name);
      xml_node<> *child = first_child;
      // If the attribute is missing, throw an exception
      if ( child == 0 )
      {
         stringstream error_message;
         error_message << "ERROR: CatchAllSubnodesValues - Attribute " << variable_name << " is missing from the xml node.";
         throw err::MyException(error_message.str().c_str(),strlen(error_message.str().c_str()));
      }
      //iterate through all the nodes with the same name and extract and store its value
      stringstream ss;
      int i1=0;
      while (child!=0)
      {
         ss.str("");
         ss << child->value();
         ss >> variable_container[i1];
         i1++;
         child=child->next_sibling(variable_name);
      }
   }


   //Catch the value of a xml attribute value with specified variable_name
   template <class T>
   void CatchFirstAttributeValue(const rapidxml::xml_node<> *node, const char *attribute_name, T &attribute_container)
   {
      using namespace std;
      using namespace rapidxml;
      // Get the node to the first attribute_name
      xml_attribute<> *attribute = node->first_attribute(attribute_name);
      // If the attribute is missing, throw an exception
      if ( attribute == 0 )
      {
         stringstream error_message;
         error_message << "ERROR: CatchFirstAttributeValue - Attribute " << attribute_name << " is missing from the xml node.";
         throw err::MyException(error_message.str().c_str(),strlen(error_message.str().c_str()));
      }
      // Extract and store the attribute into the attribute_container
      stringstream ss;
      ss << attribute->value();
      ss >> attribute_container;
   }
}




#endif
