# 정리노트#8

## C++ 입출력 시스템

### C++ 입출력 기초 

#### 스트림(stream)

- 데이터의 흐름 혹은 데이터를 전송하는 소프트웨어 모듈
    - 흐르는 시내와 유사한 개념
- 스트림의 양 끝에는 프로그램과 장치 연결
    - 보낸 순서대로 데이터 전달
    - 입출력 기본 단위 : 바이트
 
#### C++ 스트림 종류

- 입력 스트림
    - 입력 장치, 네트워크, 파일로부터 데이터를 프로그램으로 전달하는 스트림
- 출력 스트림
    - 프로그램에서 출력되는 데이터를 출력 장치, 네트워크, 파일로 전달하는 스트림

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/f890b969-c715-4bb7-b5b2-2e1e7bda6206)

### C++ 입출력 스트림 버퍼

C++ 입출력 스트림은 버퍼를 가짐

#### 키 입력 스트림의 버퍼

- 목적
    - 입력 장치로부터 입력된 데이터를 프로그램으로 전달하기 전에 일시 저장
    - 키 입력 도중 수정 가능
        - `BackSpace` 키가 입력되면 이전에 입력된 키를 버퍼에서 지움
- C++ 응용 프로그램은 사용자의 키 입력이 끝난 시점에서 읽음
    - `Enter` 키 : 키 입력의 끝을 의미
    - `Enter` 키가 입력된 시점부터 키 입력 버퍼에서 프로그램이 읽기 시작

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/4e0b13e6-bcb0-4fb0-8011-92652a917cac)

#### 스크림 출력 스트림 버퍼

- 목적
    - 프로그램에서 출력된 데이터를 출력 장치로 보내기 전에 일시 저장
    - 출력 장치를 반복적으로 사용하는 비효율성 개선
- 버퍼가 꽉 차거나 강제 출력 명령 시에 출력 장치에 출력

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/a9354c87-283f-4991-aea4-3b743b8bdb1f)

### C++ 표준은 스트림 입출력만 지원

#### 입출력 방식 2가지

- 스트림 입출력 방식(stream I/O)
    - 스트림 버퍼를 이용한 입출력 방식
    - 입력된 키는 버퍼에 저장
        - `Enter` 키가 입력되면 프로그램이 버퍼에서 읽어가는 방식
    - 출력되는 데이터는 일차적으로 스트림 버퍼에 저장
        - 버퍼가 꽉 차거나 `\n` 을 만나거나 강제 출력 명령의 경우에만 버퍼가 출력 장치에 출력
- 저 수준 입출력 방식(raw level console I/O)
    - 키가 입력되는 즉시 프로그램에게 키 값 전달
        - `BackSpace` 키 그 자체도 프로그램에게 바로 전달
        - 게임 등 키 입력이 즉각적으로 필요한 곳에 사용
    - 프로그램이 출력하는 즉시 출력 장치에 출력
    - 컴파일러마다 다른 라이브러리나 API 지원
        - C++ 프로그램의 호환성 낮음

#### 2003년 이전의 C++ 입출력 라이브러리의 약점

- 대표적인 구 표준(C++03) 입출력 라이브러리 클래스
    - ios, istream, ostream, iostream, ifstream, ofstream, fstream
- 문자를 한 바이트의 `char` 로 처리
    - cin >>로 문자를 읽을 때 한글 문자 읽을 수 없음
        - 영어나 기호 : 1 바이트의 문자 코드
        - 한글 문자 : 2바이트의 문자 코드
        - ![image](https://github.com/choiht0904/Cpp_01/assets/77330457/ed66160a-8b19-4a00-9c59-5dfe157e582c)
- 지금도 마찬가지로 cin으로 한글을 문자 단위로는 읽을 수 없음

### 현재의 표준 C++ 입출력 라이브러리

- 다양한 크기의 다국어 문자를 수용하기 위해 입출력 라이브러리가 템플릿으로 작성됨

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/6aa3cb28-bf43-4784-9a8f-fddcf94efd99)

### C++ 표준 입출력 스트림 객체

#### C++ 프로그램이 실행될 때 자동으로 생겨나는 스트림

- cin
    - istream 타입의 스트림 객체로서 키보드 장치와 연결
- cout
    - ostream 타입의 스트림 객체로서 스크린 장치와 연결
- cerr
    - ostream 타입의 스트림 객체로서 스크린 장치와 연결
    - 오류 메시지를 출력할 목적
    - 스트림 내부 버퍼를 거치지 않고 출력
- clog
    - ostream 타입의 스트림 객체로서 스크린 장치와 연결
    - 오류 메시지를 출력할 목적
    - 스트림 내부 버퍼를 거쳐서 출력

#### iostream 헤더 파일에 선언된 스트림 객체들

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/4de6818e-a588-47b2-a85d-707da91b421d)

#### ostream의 멤버 함수를 이용한 문자 출력

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/dd309a70-12af-46b2-8d4d-806a567da944)

#### ch = cin.get()의 실행 사례

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/8f378b23-0a96-4ce6-aced-e3b0c498f3f3)

#### 문자열 입력

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/5a18480f-138b-47f6-be69-153509d65326)

```C++
char str[10];
cin.get(str, 10); // 최대 9개의 문자를 읽고 끝에 \0를 붙여 str 배열에 저장
cout << str; // str을 화면에 출력
```

#### get()이 읽는 도중 `Enter` 키(`\n` )를 만날 때

- 읽기를 중단하고 리턴
- `Enter` 키(`\n` )는 스트림 버퍼에 남아 있음
    - 다시 get()으로 문자열 읽기를 시도하면 입력 스트림에 남은 `\n` 키를 만나게 되기에 바로 리턴함. 프로그램은 무한 루프에 빠질 수 있음
    - 이때 이 문제를 해결하기 위해서는 cin.get()이나 cin.ignore(1)를 통해 문자 1개(`\n` )를 스트림에서 읽어버려야 함

#### 한 줄 읽기

```C++
istream& get(char* s, int n, char delim='\n')
// 입력 스트림으로부터 최대 n + 1개의 문자를 읽어 배열 s에 저장하고 마지막에 '\0' 문자 삽입 
// 도중 delim에 지정된 구분 문자를 만나면 지금까지 읽은 문자를 배열 s에 저장하고 리턴
istream& getLine(char* s, int n, char delim='\n')
// get()과 동일하지만 delim에 지정된 구분 문자를 스트림에서 제거
```

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/1a370cfa-ab9e-4a0d-8533-b27fa57592c7)

#### 입력 문자 건너띄기와 문자 개수 알아내기

```C++
istream& ignore(int n = 1, int delim = EOF)
// 입력 스트림에서 n개 문자 제거, 도중에 delim 문자를 만나면 delim 문자를 제거하고 리턴
int gcount()
// 최근에 입력 스트림에서 읽은 바이트 수(문자의 개수) 리턴
// Enter키도 개수에 포함
```

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/e8300b7d-cd34-4335-8d5b-e724abc8f4d3)

#### 포맷 입출력

- C++에서도 입출력시 포맷 지정 가능
    - C언어의 printf()와 유사
- 포맷 입출력 방법 3가지
    - 포맷 플래그
    - 포맷 함수
    - 조작자

#### 포맷 플래그

- 입출력 스트림에서 입출력 형식을 지정하기 위한 플래그

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/f40eefa1-5aef-44c4-a896-b8b2c3e419ad)

#### ios 클래스에 정의된 포맷 플래그

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/698bc0dc-e074-43d0-94b0-f8f0478b75b7)

#### 포맷 플래그를 세팅하는 멤버 함수

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/e85dba47-1faa-4c9e-aaa0-f076f120e78f)

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/74ead7eb-1e49-46e4-a7f7-c7bfddd12bf6)

#### 포맷 함수 활용

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/a63546e2-a4d2-4f30-9ee4-fc5a341cfc13)

#### 조작자

- manipulator, 스트림 조작자(stream manipulator)
- 조작자는 함수
    - C++ 표준 라이브러리에 구현된 조작자 : 입출력 포맷 지정 목적
    - 개발자만의 조자자 작성 가능 : 다양한 목적
    - 매개 변수 없는 조작자와 매개 변수를 가진 조작자로 구분
- 조작자는 함상 <<나 >> 연산자와 함께 사용됨

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/ad4d4359-36cc-4a57-8b34-c5426db0f4f8)

#### 삽입 연산자(<<)와 추출 연산자(>>)

- 삽입 연산자(<<)
    - insertion operator, 삽입자라고도 부름
        - << 연산자는 C++의 기본 연산자 : 정수 시프트 연산자
    - ostream 클래스에 중복 작성되어 있음
    
    ![image](https://github.com/choiht0904/Cpp_01/assets/77330457/49937b81-ab55-44f1-bf31-226bea367dd8)

- 추출 연산자(>>)
    - extraction operator
        - >> 연산자는 C++의 기본 연산자 : 정수 시프트 연산자
    - ostream 클래스에 중복 작성되어 있음
    
    ![image](https://github.com/choiht0904/Cpp_01/assets/77330457/9f9dbc83-e826-4582-b7a8-ed4fb480ec16)

    - 추출 연산자의 실행 과정
        - 삽입 연산자의 실행 과정과 유사함

#### 사용자 삽입 연산자 만들기

- 개발자가 작성한 클래스의 객체를 << 연산자로 출력

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/b8dec372-8b8b-4af8-afa2-ef198ad4da21)

- cout << p를 위한 << 연산자 만들기
    
![image](https://github.com/choiht0904/Cpp_01/assets/77330457/fd5ed2ce-b7e5-406d-8da0-b704b934dff6)


#### 사용자 추출 연산자 만들기

- 개발자가 작성한 클래스의 객체에 >> 연산자로 입력

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/b0ae8f13-148f-4181-b4ee-f3662ff7cb92)

- cin >> p를 위한 >> 연산자 만들기

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/2ad8f63c-3551-48d5-becf-efdf26d46fbb)

#### 사용자 조작자 만들기

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/89b0d30e-a21f-4634-94c6-144122a51fb4)

#### 사용자 정의 조작자 함수 원형

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/7d580b42-ac17-457b-8b97-abebb454a5d3)
