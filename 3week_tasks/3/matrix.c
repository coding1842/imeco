/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
 * 기능 : 메인
 * 설명 : 2D인 MATRIX 두개 곱하는 프로그램
 * 입력 매개변수 : int argc, char** argv 
 * 출력 매개변수: 
 * 반환값 : SUCCESS - 0(FOK)
 * FAIL - 0 없음(FERR)
 *-------------------------------------- -------------------*/

int main(int argc, char** argv)
{
	if (argc == 4)
	{
		int i, j;

		int matrix1[3][3] = { 0, };
		int matrix2[3][3] = { 0, };
		int matrix3[3][3] = { 0, };

		FILE* fp1 = fopen(argv[1], "r");
		FILE* fp2 = fopen(argv[2], "r");
		FILE* fp3 = fopen(argv[3], "w");

		if (sizeof(matrix1) != sizeof(matrix2) || sizeof(matrix1[0]) != sizeof(matrix2[0]))
		{
			printf("두개의 배열의 길이가 달라 곱셈을 할 수 없습니다.\n");
			exit(1);
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				fscanf(fp1, "%d", &matrix1[i][j]);
				printf("%d ", matrix1[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				fscanf(fp2, "%d", &matrix2[i][j]);
				printf("%d ", matrix2[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				matrix3[i][j] = matrix1[i][j] * matrix2[i][j];
				fprintf(stdout, "%d ", matrix3[i][j]);

			}
			printf("\n");
		}
		printf("\n");

		for (i = 0, j = 0; i < 3; i++)
		{
			fprintf(fp3, "%d %d %d\n", matrix3[i][j], matrix3[i][j + 1], matrix3[i][j + 2]);
		}

		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
	}

	return 0;
}/* 메인 끝 */
