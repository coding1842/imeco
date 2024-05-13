/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : 메인
* 설명 : dup(), dup2() 함수 사용하는 프로그램
* 입력 매개변수 : int liFd, int liNew_fd, int liFd2
* 출력 매개변수: 
* 반환값 : SUCCESS - 0(FOK)
* FAIL - 0 없음(FERR)
*-------------------------------------- -------------------*/
int main() {
	int liFd;

	liFd = open("original.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (liFd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	int liNew_fd = dup(liFd);
	if (liNew_fd == -1) {
		perror("dup");
		exit(EXIT_FAILURE);
	}

	printf("Original file descriptor: %d\n", liFd);
	printf("Duplicate file descriptor: %d\n", liNew_fd);

	close(liFd);
	close(liNew_fd);

	int liFd1 = open("dup1.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (liFd1 == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	int liFd2 = open("dup2.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (liFd2 == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	if (dup2(liFd1, liFd2) == -1) {
		perror("dup2");
		exit(EXIT_FAILURE);
	}

	printf("Original file descriptor: %d\n", liFd1);
	printf("Duplicate file descriptor: %d\n", liFd2);

	close(liFd1);
	close(liFd2);

	return 0;
}  /* 메인 끝 */

