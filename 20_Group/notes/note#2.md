# 문제1
![Untitled](https://github.com/choiht0904/Cpp_01/assets/77330457/6f00aa11-7389-4e25-b3ae-b58cd81a9a69)<br>
정확한 암호(C++) 입력시에 종료되는 프로그램

먼저 정답을 저장하는 변수 answer와 입력받은 암호를 저장하는 변수 password를 선언하였습니다. 그리고 프로그램이 종료되기 전까지 계속 암호를 입력받아야 하기에 반복문을 사용해서 변수 password에 입력을 받을 수 있게 하였습니다.
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
그리고 입력받은 암호와 정답이 일치하는 지를 검사하기 위해서 if문을 사용하였고 입력받은 암호와 정답을 비교하기 위해서 cstring 라이브러리의 문자열 비교 함수인 strcmp()를 사용해서 두 변수를 비교했습니다.<br>
<br>
두 변수를 비교한 결과가 1인 경우 두 변수가 같지 않으므로 "입력하신 암호가 틀렸습니다."를 출력하고 다시 입력을 받도록 하였고 0인 경우 두 변수는 같으므로 "정답입니다."를 출력하고 프로그램이 종료되게끔 만들었습니다.
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
저희가 작성한 코드를 테스트해 본 결과 맞는 암호가 입력될 때까지 계속 반복되는 프로그램을 구현하는데 성공하였습니다.<br>
![Untitled (1)](https://github.com/choiht0904/Cpp_01/assets/77330457/807b0966-478d-48f3-a505-56e200b86c9f)<br>

# 문제2
![Untitled (2)](https://github.com/choiht0904/Cpp_01/assets/77330457/76d155ec-23f9-438b-a23e-92990136f45d)<br>
한 라인에 ‘;’으로 5개의 이름을 구분하여 입력받아, 각 이름을 끊어내어 화면에 출력하고 가장 긴 이름을 판별하라.

먼저 문자열 안에 ';'로 이름을 구분하기 때문에 문자열을 입력받기 위한 변수인 str을 선언했습니다. 그리고 총 5개의 이름을 구분해야 하므로 반복문을 사용하여 이름을 구분하도록 하였습니다. ‘;’를 구분하기 위해서 힌트에서 제공해준 함수인 cin.getline() 함수를 사용하였습니다.
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
그리고 ';'로 구분된 이름들을 저장하는 변수인 names를 선언하였고 반복문 내에 index가 i인 곳에 이를 저장하게끔 하였습니다. 또한 이름들을 출력하기 위해서 반복문을 다시 사용하여 출력하게끔 하였습니다.
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
마지막으로 가장 긴 이름을 구하기 위해서 이름들의 길이를 비교해서 가장 긴 이름을 구분하기로 결정했습니다. 그러기 위해 가장 긴 이름의 길이를 저장하는 변수인 maxLength와 가장 긴 이름의 index를 저장하는 maxIndex 변수를 선언하였습니다. 그리고 반복문 내에서 string.length()를 사용해서 i번째 이름의 길이와 maxLength를 비교해서 i번째 이름이 더 길 경우 maxIndex에 현재 index를 저장해서 가장 긴 이름을 가져올 수 있도록 하였습니다. 그래서 마지막에 가장 긴 이름을 출력할 때 maxIndex를 통해서 가장 긴 이름을 가져오도록 하였습니다.
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
저희가 작성한 코드를 테스트해 본 결과 문자열에서 ';'를 사용해서 이름을 구분하는 것과 가장 긴 이름을 구분하는 것을 프로그램을 구현하였습니다.<br>
![Untitled (5)](https://github.com/choiht0904/Cpp_01/assets/77330457/5b9da131-89d3-455c-9e0a-3c0c40935de4)<br>
![Untitled (4)](https://github.com/choiht0904/Cpp_01/assets/77330457/1d367da3-f2b3-4af0-882c-8a55313b94b2)<br>
![Untitled (3)](https://github.com/choiht0904/Cpp_01/assets/77330457/8cee9d50-ee57-4574-b518-19a5922b342d)<br>


