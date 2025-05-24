int main() {
    char input[101];         // 식 전체를 저장할 문자열 (최대 100자)
    double numbers[100];     // 숫자 저장용 배열
    char cal[100];           // 연산자 저장용 배열 (+, -, *, /)
    int num_i = 0;           // numbers 배열에 숫자 저장 위치
    int cal_i = 0;           // cal 배열에 연산자 저장 위치

    gets(input);             //수식 입력 받기 (엔터 칠 때까지 입력 받음)

    for (int i = 0; input[i] != '\0'; ) // 수식을 숫자와 연산자로 분리
    {
        if (input[i] == ' ') // 공백은 무시
        {
            i++; //다음 원소로
            continue; //다음 반복으로
        }

        if (input[i] >= '0' && input[i] <= '9') // 숫자만 추출
        {
            int num = 0; //숫자를 입력 받을 변수
            while (input[i] >= '0' && input[i] <= '9') // 숫자일 때
            { 
                num = num * 10 + (input[i] - '0');  // 자리수 이동 후 덧셈
                i++;
            }
            numbers[num_i++] = num;  // 숫자 저장
        }

        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') // 연산자 추출
        {
            cal[cal_i++] = input[i++];  // 연산자 저장 후 다음 문자로
        }
    }

    for (int i = 0; i < cal_i; i++) // *, / 연산 먼저 수행 
    {
        if (cal[i] == '*' || cal[i] == '/') // *, / 연산 먼저 수행 
        {
            double temp = (cal[i] == '*') ? numbers[i] * numbers[i + 1] : numbers[i] / numbers[i + 1]; //계산
            numbers[i] = temp;  // 계산 결과를 앞 숫자 위치에 덮어쓰기

            for (int j = i + 1; j < num_i - 1; j++) //숫자 배열에서 사용한 숫자 제거
                numbers[j] = numbers[j + 1]; // 앞으로 한 칸씩 당기기
            for (int j = i; j < cal_i - 1; j++) // 연산자 배열에서 사용한 연산자 제거
                cal[j] = cal[j + 1]; // 앞으로 한 칸씩 당기기

            num_i--; // 숫자 당기기
            cal_i--; // 연산자 당기기
            i--;  // 같은 인덱스에서 다시 검사
        }
    }

    // +, - 연산 차례대로 수행
    double result = numbers[0]; //결과를 저장할 문자열 선언 (식의 첫번째 수로 저장)
    for (int i = 0; i < cal_i; i++) { //남은 연산자 개수 만큼
        if (cal[i] == '+') result += numbers[i + 1]; // 더하기 진행
        else if (cal[i] == '-') result -= numbers[i + 1]; // 빼기 진행
    }

    printf("%.6lf\n", result); // 최종 결과 출력
    return 0; // 프로그램 종료
}
