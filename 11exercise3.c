#include <stdio.h>   // 표준 입출력 함수 사용

int max(int a, int b, int c); // 세 개의 수 중 최댓값을 반환하는 함수 max 선언
int min(int a, int b, int c); // 세 개의 수 중 최솟값을 반환하는 함수 min 선언
int make_max_array(int arr[], int size, int result[]); // 배열을 3개씩 묶어 최댓값 배열을 만들고 새 배열의 크기 반환하는 함수 선언(다음 배열의 길이를 알기 위해서)
int make_min_array(int arr[], int size, int result[]); // 배열을 3개씩 묶어 최솟값 배열을 만들고 새 배열의 크기를 반환하는 함수 선언
void print_array(int arr[], int size); // 배열을 전부 출력하는 함수 선언(배열이랑 배열 길이 입력받음)

int main()
{
    int n; // 배열 크기를 저장하는 변수
    scanf("%d", &n); // 배열 크기 입력 받기
    int arr[100]; // 배열 선언

    for (int i = 0; i < n; i++) // 0부터 n-1까지 반복하면서
    {
        scanf("%d", &arr[i]); // 배열에 값 입력 받음
    }

    printf("역순 : "); // 역순 출력 안내 메시지 출력
    for (int i = 0; i < n; i++) // 0부터 n-1까지 반복하면서
    {
        printf("%d ", arr[n - i - 1]); // 배열을 뒤에서부터 출력 (역순)
    }
    printf("\n"); // 줄바꿈

    int max_array[100], min_array[100]; // 최댓값 배열과 최솟값 배열 저장 공간
    int max_count, min_count; // 각각 배열 크기 저장 변수

    max_count = make_max_array(arr, n, max_array); // 처음 입력받은 배열로부터 3개씩 묶어 최댓값 배열 만들고 크기 저장(길이를 반환, 함수 내에서 최댓값 배열 max_array 채워 넣음)
    print_array(max_array, max_count); // 최댓값 배열 출력

    
    min_count = make_min_array(arr, n, min_array); // 처음 입력받은 배열로부터 3개씩 묶어 최솟값 배열 만들고 크기 반환
    print_array(min_array, min_count); // 최솟값 배열 출력

    int temp_max[100], temp_min[100]; // 이후 과정에서 계속 사용할 임시 배열과 크기 변수 초기화
    int temp_max_count = max_count; //최댓값 배열 크기 이동
    int temp_min_count = min_count; //최솟값 배열 크기 이동
    

    for (int i = 0; i < max_count; i++) //최댓값 배열 원소 이동
    {
        temp_max[i] = max_array[i]; //temp_max로 이동(다음에 max_array에 최댓값 배열을 입력받아야 하므로 현재 최댓값 배열을 이동시킴)
    }

    for (int i = 0; i < min_count; i++) //최솟값 배열 원소 이동
    {
        temp_min[i] = min_array[i]; //temp_min로 이동(다음에 min_array에 최솟값 배열을 입력받아야 하므로 현재 최솟값 배열을 이동시킴)
    }

    while (temp_max_count > 1 || temp_min_count > 1) // 둘 중 하나라도 2개 이상이면 반복
    {
        if (temp_max_count > 1) // 최댓값 배열 크기가 1보다 크면
        {
            temp_max_count = make_max_array(temp_max, temp_max_count, temp_max); // 자기 자신을 갱신
            print_array(temp_max, temp_max_count); // 출력
        }

        if (temp_min_count > 1) // 최솟값 배열 크기가 1보다 크면
        {
            temp_min_count = make_min_array(temp_min, temp_min_count, temp_min); // 자기 자신을 갱신
            print_array(temp_min, temp_min_count); // 출력
        }
    }
    
    return 0; // 프로그램 종료
}

int max(int a, int b, int c) // 최댓값 반환 함수

{
    int maximum = a; // 먼저 a를 최댓값 변수에 넣음
    if (b > maximum) // 그리고 그 값이 b보다 작으면
    {
        maximum = b; // 최댓값은 b가 됨
    }
    if (c > maximum) // c보다 작으면
    {
        maximum = c; // 최댓값은 c가 됨
    }
    return maximum; // 최댓값 반환
}

int min(int a, int b, int c) // 최솟값 반환 함수
{
    int minimum = a; // 먼저 a를 최댓값 변수에 넣음
    if (b < minimum) // b보다 크면
    {
        minimum = b; //최솟값은 b
    }
    if (c < minimum) // c보다 크면
    {
        minimum = c; // 최솟값은 c
    }
    return minimum; // 최솟값 반환
}

int make_max_array(int arr[], int size, int result[]) // 배열에서 3개씩 묶어 최댓값 배열 만드는 함수(만든 배열의 크기 반환)
{
    int count = 0; // 새 배열의 크기를 새는 변수

    for (int i = 0; i + 2 < size; i = i + 3) // 3개씩 묶어서 반복하기 위한 반복문
    {
        result[count] = max(arr[i], arr[i + 1], arr[i + 2]); // 최댓값들을 result에 입력(result 배열의 원소들은 max_array배열에 저장되어 main함수에서 사용됨)
        count = count + 1; //하나씩 적을때마다 길이 1개씩 추가
    }

    if (size % 3 == 1) // 남은 원소 처리 (1개)
    {
        result[count] = arr[size - 1]; // 그냥 넣음
        count = count + 1; //개수 하나 늘림
    }
    else if (size % 3 == 2) // 남은 원소 처리 (2개)
    {
        if (arr[size - 2] > arr[size - 1]) // 둘중 큰 값을 저장
        {
            result[count] = arr[size - 2]; //큰값 저장
        }
        else
        {
            result[count] = arr[size - 1]; //큰 값 저장
        }
        count = count + 1; //하나 세기
    }

    return count; //길이 반환
}

int make_min_array(int arr[], int size, int result[]) // 배열에서 3개씩 묶어 최솟값 배열 만드는 함수(만든 배열의 크기 반환)
{
    int count = 0; // 새 배열의 크기를 재는 함수

    for (int i = 0; i + 2 < size; i = i + 3) // 3개씩 묶어서 반복하기 위한 반복문
    {
        result[count] = min(arr[i], arr[i + 1], arr[i + 2]); // 최댓값들을 result에 입력 (result 배열의 원소들은 min_array배열에 저장되어 main함수에서 사용됨)
        count = count + 1; //길이 세기
    }

    if (size % 3 == 1) // 남은 원소 처리 (1개)
    {
        result[count] = arr[size - 1]; //그냥 바로 저장
        count = count + 1; //길이 세기
    }
    else if (size % 3 == 2) // 남은 원소 처리 (2개)
    {
        if (arr[size - 2] < arr[size - 1]) // 둘 중 작은 값을 저장
        {
            result[count] = arr[size - 2]; // 왼쪽이 작으면 왼쪽 저장
        }
        else
        {
            result[count] = arr[size - 1]; // 오른 쪽이 작으면 오른쪽 저장
        }
        count = count + 1; // 길이 세기
    }

    return count; //길이 반환
}

void print_array(int arr[], int size) // 배열 내용을 모두 한 줄에 출력하는 함수
{
    for (int i = 0; i < size; i++) //크기만큼 반복
    {
        printf("%d ", arr[i]); //배열 출력
    }
    printf("\n"); //전부 입력후 다음 줄로 넘어가기
}

