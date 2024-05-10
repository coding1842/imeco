 #include <stdio.h>
  #include <stdlib.h>
  #include "binaryToAscii.h"
   
   void binaryToAscii()
   {
       FILE *inputFile = fopen(gInputFileName, "r");
       FILE *outputFile = fopen(gOutputFileName, "w");
   
     char binary[9];
  
      while (fscanf(inputFile, "%8s", binary) == 1)
      {
          int ascii = strtol(binary, NULL, 2);
          fprintf(outputFile, "%c", ascii);
      }
      fclose(inputFile);
      fclose(outputFile);
  }
