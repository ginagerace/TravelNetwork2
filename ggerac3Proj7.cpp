#include "TravelNetwork.cpp"

int main (int argc, char** argv)
{
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the airport adjacency list
  TravelNetwork airportData;

  // call the method that reads and parses the input
  airportData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  airportData.processCommandLoop (inFile);

  printf ("Goodbye\n");
  return 1;
 }
