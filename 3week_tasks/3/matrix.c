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
	else if (argc != 4)
	{
		printf("제대로 입력해주세요, 현재 상태론 행렬 곱셈이 안됩니다. 다시시도해 주세요.\n");
		exit(1);
	}

	return 0;
}/* 메인 끝 */
