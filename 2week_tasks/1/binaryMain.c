#include <stdio.h>
   #include "binaryToAscii.h"

char gInputFileName[BUFF_SIZE];
char gOutputFileName[BUFF_SIZE];

   void binaryToAscii();
   
   int main()
   {
       printf("읽어올 파일명을 입력하세요: ");
       scanf("%s", gInputFileName);
  
      printf("저장할 파일명을 입력하세요: ");
      scanf("%s", gOutputFileName);
  
      binaryToAscii();
  
      printf("이진 파일을 아스키 코드로 변환하여 %s 파일에 저장했습니다.\n", gOutputFileName);
  
     return 0;
  }
