#include "FileUtilities.h"

namespace xml
{
   
   rapidxml::xml_node<> * CatchFirstNodeFromFile(const char *filename, const char *nodename)
   {
      using namespace std;
      using namespace rapidxml;
   
      // Open the file
      ifstream inputfile(filename);
   
      // Read the xml file into a vector
      vector<char> buffer((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
      buffer.push_back('\0');
   
      // Parse the buffer using the xml file parsing library into doc
      xml_document<> xmldoc;
      xmldoc.parse<0>(&buffer[0]);
   
      // Find the root node and return it
      return xmldoc.first_node(nodename);
   
      // Close the file
      inputfile.close();
   }
   
}

