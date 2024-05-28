/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : 메인
* 설명 : shared memory 사용하여 Quick Sort 하기
* 입력 매개변수 : int arr[], int left, int right 
* 출력 매개변수: 
* 반환값 : SUCCESS - 0(FOK)
* FAIL - 0 없음(FERR)
*-------------------------------------- -------------------*/

void quicksort(int arr[], int left, int right)
{
    if (left < right)
	{
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) 
		{
            if (arr[j] < pivot) 
			{
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;
        int partition_index = i + 1;

        // 분할된 부분을 다시 분할 정복
        quicksort(arr, left, partition_index - 1);
        quicksort(arr, partition_index + 1, right);
    }
}

int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
	{
        scanf("%d", &arr[i]);
    }

    // Quick Sort 수행
    quicksort(arr, 0, size - 1);

    // 정렬된 데이터 출력
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
} /* 메인 끝 */

