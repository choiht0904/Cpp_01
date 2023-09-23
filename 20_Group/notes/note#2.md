# 문제1
![Untitled](https://github.com/choiht0904/Cpp_01/assets/77330457/6f00aa11-7389-4e25-b3ae-b58cd81a9a69)<br>
정확한 암호(C++) 입력시에 종료되는 프로그램

입력받은 암호가 맞으면 프로그램이 종료되게끔 하기 위해서 먼저 무한반복문 안에 입력을 받아야 한다. 그리고 입력받은 암호가 맞는지를 검사하기 위해서 정답을 변수에 저장하여 비교하는 방식으로 구성한다. 하지만 반복문 내에서 정답을 선언할 경우 계속 생성이 되기 때문에 반복문 밖에서 먼저 정답을 선언한다.
```c++
#include <iostream>
using namespace std;

int main() {
    char answer[20] = "C++";
    char password[20];
    while(true) {
        cin >> password;
    }
    return 0;
}
```
그리고 입력받은 암호가 정답과 같지 않을 경우 틀린 암호를 입력했다고 사용자에게 알리기 위해서 암호가 잘못됐다고 출력을 해야 한다. 그리고 입력받은 암호가 정답과 같은 경우 프로그램을 종료시키기 위해 조건문을 사용하여 입력받은 암호와 정답을 비교한다.
```c++
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char answer[20] = "C++";
    char password[20];
    while(true) {
        cin >> password;
        if(strcmp(password, answer)) {
            cout << "입력하신 암호가 틀렸습니다." << endl;
        } else {
            cout << "정답입니다." << endl;
            break;
        }
    }
    return 0;
}
```
테스트 결과 맞는 암호를 입력할 때까지 계속 반복되는 프로그램을 구현하는데 성공하였다.
![Untitled (1)](https://github.com/choiht0904/Cpp_01/assets/77330457/807b0966-478d-48f3-a505-56e200b86c9f)<br>

# 문제2
![Untitled (2)](https://github.com/choiht0904/Cpp_01/assets/77330457/76d155ec-23f9-438b-a23e-92990136f45d)<br>
한 라인에 ‘;’으로 5개의 이름을 구분하여 입력받아, 각 이름을 끊어내어 화면에 출력하고 가장 긴 이름을 판별하라.

먼저 문자열을 입력받아서 이름을 구분해야 하므로 변수를 선언하여 문자열을 입력받는다. 그리고 총 5개의 이름을 구분해야 하므로 반복문을 사용하고 ‘;’를 사용해서 구분하기 위해 cin.getline() 함수를 사용한다.
```c++
#include <iostream>
using namespace std;

int main() {
    char str[100];
    for(int i = 0; i < 5; i++) {
        cin.getline(str, 100, ';');
    }
    return 0;
}
```
그리고 구분된 이름들을 저장하는 변수인 names를 선언하고 이를 출력하기 위해서 다시 한번 반복문을 사용하여 출력한다.
```c++
#include <iostream>
using namespace std;

int main() {
    char str[100];
    string names[5];
    for(int i = 0; i < 5; i++) {
        cin.getline(str, 100, ';');
        names[i] = str;
    }
    for(int i = 0; i < 5; i++) {
        cout << i + 1 << " : " << names[i] << endl;
    }
    return 0;
}
```
마지막으로 가장 긴 이름을 구하기 위해서 string.length()를 사용해서 길이를 구하고 가장 긴 길이를 가진 이름과 길이를 비교하여 현재 이름이 더 긴 경우에 index를 현재 이름이 저장된 위치로 바꾼다.
```c++
#include <iostream>
using namespace std;

int main() {
    char str[100];
    string names[5];
    int maxIndex = 0;
    int maxLength = 0;
    for(int i = 0; i < 5; i++) {
        cin.getline(str, 100, ';');
        names[i] = str;
    }
    for(int i = 0; i < 5; i++) {
        cout << i + 1 << " : " << names[i] << endl;
        if(names[i].length() > maxLength) {
            maxIndex = i;
            maxLength = names[i].length();
        }
    }
    cout << "가장 긴 이름은 " << names[maxIndex];
    return 0;
}
```
테스트 결과 문자열에서 이름을 구분하는 것과 가장 긴 이름을 구분하는 것을 프로그램을 구현하였다.<br>
![Untitled (5)](https://github.com/choiht0904/Cpp_01/assets/77330457/5b9da131-89d3-455c-9e0a-3c0c40935de4)<br>
![Untitled (4)](https://github.com/choiht0904/Cpp_01/assets/77330457/1d367da3-f2b3-4af0-882c-8a55313b94b2)<br>
![Untitled (3)](https://github.com/choiht0904/Cpp_01/assets/77330457/8cee9d50-ee57-4574-b518-19a5922b342d)<br>


