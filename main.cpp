// 10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
#include <iostream>
using namespace std;

int d(int n) { // 양의 정수에 각 자리수를 더하는 함수
    int result = n, rest; // 매개 변수의 값을 result에 대입(만약 n이 12라면 12+1+2 즉 15를 리턴해야 하므로 우선 result에 12를 대입하고 각 자리수는 가산해주도록 한다.). rest는 나머지를 나타내는 변수.
    while(true) {
        rest = n % 10; // n을 10으로 나눈 나머지를 rest에 대입한다.
        result += rest; // result에 rest를 더해준다.
        n = n / 10; // 나머지 자리수를 더하기 위해 n을 n / 10으로 초기화한다.
        if (n == 0) break; // 만약 n이 0이라면 더 이상 자리수는 존재하지 않기 때문에 break.
    }
    return result; // 양의 정수에 각 자리수를 더한 값 리턴
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    bool check = 1; // 셀프넘버인지 아닌지 구분하기 위한 bool형 변수. true로 초기화
    for (int i=1; i<10000; i++) { // 10000보다 작은 숫자에 대하여
        for (int j=1; j<i; j++) { // i마다 셀프넘버인지 아닌지 확인하기 위한 반복
            if (d(j) == i) { // i가 셀프넘버가 아니라면
                check = 0; // check는 false
                break; // break로 반복문 탈출
            }
        }
        if (check) cout << i << '\n'; // check가 true이면 i 출력
        check = 1; // check를 다시 true로 초기화
    }
}