#include "Airport7.cpp"

class TravelNetwork {
 private:
   // Create the Data Members for the Travel Network here
   Airport* airArr;
   MyList* filenames;
   int sizeArr;

   bool bfs(int b, MyList *AirportQueue) {
     while(AirportQueue->isEmpty() == false) {
        int a = AirportQueue->popFront();
        for(int i=1; i<=sizeArr; i++) {
            if(airArr[a].contains(i) == true) {
                if(airArr[i].getPrev() == -1) {
                    airArr[i].setPrev(a);
                    if(i == b)
                        return true;
                    AirportQueue->push(i);
                }
            }
        }
     }
     return false;
   }

 public:
   // Use a constructor to initialize the Data Members for Travel Network
   TravelNetwork() {
     sizeArr = 11;                     //make size 11 to use spots 1-10
     airArr = new Airport[sizeArr];
     filenames = new MyList();         //allocate memory for filenames list
   }

   //clear travel network and reset with new size
   void reset(int x){
     delete airArr;                 //delete current airport list
     sizeArr = x + 1;
     airArr = new Airport[sizeArr] ;
   }

   MyList* breadthFirstSearch(int x, int y) {
     //mark all airports as unvisited
     for(int i=1; i<=sizeArr; i++)
         airArr[i].setPrev(-1);
     MyList *AirportQueue = new MyList();
     AirportQueue->push(x);
     if(bfs(y, AirportQueue) == false) {
        printf("You can NOT get from airport %d to airport %d in one or more flights\n", x, y);
        return AirportQueue;
     }
     else {
        printf("You can get from airport %d to airport %d in one or more flights\n", x, y);
        MyList *pathList = new MyList();
        int currAir = y;
        pathList->pushFront(currAir);
        do {
            currAir = airArr[currAir].getPrev();
            pathList->pushFront(currAir);
        } while(currAir != x);
        return pathList;
     }
   }


 // The main loop for reading in input
 void processCommandLoop (FILE* inFile)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input

  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions
    char* command;
    command = strtok (input , " \n\t");

    printf ("*%s*\n", command);

    if ( command == NULL )
      printf ("Blank Line\n");

    else if ( strcmp (command, "q") == 0)
      exit(1);

    else if ( strcmp (command, "?") == 0)
      showCommands();

    else if ( strcmp (command, "s") == 0)
      doShortestPath();

    else if ( strcmp (command, "t") == 0)
      doTravel();

    else if ( strcmp (command, "r") == 0)
      doResize();

    else if ( strcmp (command, "i") == 0)
      doInsert();

    else if ( strcmp (command, "d") == 0)
      doDelete();

    else if ( strcmp (command, "l") == 0)
      doList();

    else if ( strcmp (command, "f") == 0)
      doFile();

    else if ( strcmp (command, "#") == 0)
      ;

    else
      printf ("Command is not known: %s\n", command);

    input = fgets ( buffer, 300, inFile );   // get the next line of input

  }
 }

 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  s <int1> <int2> \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }

 void doShortestPath()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }


   printf ("Performing the Shortest Path Command from %d to %d\n",
            val1, val2);

   if(val1<=sizeArr && val2<=sizeArr) {
     MyList *path = breadthFirstSearch(val1,val2);
     if(path->isEmpty() == false) {
         printf("Here is the shortest path: ");
         path->print2();
         printf("\n");
     }
   }
   else
     printf("Airport number is out of bounds!\n");
 }

 void doTravel()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }


   printf ("Performing the Travel Command from %d to %d\n",
            val1, val2);

   if(val1<=sizeArr && val2<=sizeArr)
     breadthFirstSearch(val1,val2);
   else
     printf("Airport number is out of bounds!\n");
 }

 void doResize()
 {
   int val1 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   printf ("Performing the Resize Command with %d\n", val1 );

   reset(val1);
 }

 void doInsert()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }


   printf ("Performing the Insert Command from %d to %d\n",
            val1, val2);

   if(val1<=sizeArr && val2<=sizeArr)
     airArr[val1].insert1(val2);
   else
     printf("Airport number is out of bounds!\n");
 }

 void doDelete()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }


   printf ("Performing the Delete Command from %d to %d\n",
            val1, val2);

   airArr[val1].remove1(val2);
 }

 void doList()
 {
     for(int i=1; i<sizeArr; i++) {
        printf("\nAirports reachable from airport #%d: ", i);
        airArr[i].print1();
     }
     printf("\n");
 }

 void doFile()
 {
   // get a filename from the input
   char* fname = strtok (NULL, " \n\t");
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }

   printf ("Performing the File command with file: %s\n", fname);

   // next steps:  (if any step fails: print an error message and return )
   //  1. verify the file name is not currently in use
   if(filenames->containsName(fname) == true){
        printf("ERROR: File is already in use!\n");
        return;
   }
   //  2. open the file using fopen creating a new instance of FILE*
   FILE* newFile;
   newFile = fopen(fname, "r");
   if(newFile == NULL){
        printf("ERROR: Can't open input file!\n");
        return;
   }
   filenames->addName(fname);
   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
   this->processCommandLoop(newFile);
   //  4. close the file when processCommandLoop() returns
   fclose(newFile);
   filenames->removeName(fname);
 }
};
