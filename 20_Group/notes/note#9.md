# 정리노트#9

# C++ 파일 입출력

## 텍스트 파일과 바이너리 파일

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/bc283a7c-7d3d-41c8-a0e9-571ef7093075)

### 텍스트 파일

- 사람들이 사용하는 글자 혹은 문자들로만 구성되는 파일
    - 알파벳, 한글 숫자, `% # @ < ?` 등의 기호 문자
- `\n` , `\t` 등의 특수 문자도 포함
- 각 문자마다 문자 코드(이진수) 할당
    - ASCII 코드, 유니코드
- 텍스트 파일의 종류
    - txt 파일, HTML 파일, XML 파일, C++ 소스 파일, C 소스 파일, 자바 소스 파일

### 텍스트 파일과 `Enter` 키

- `Enter` 키를 입력하면 텍스트 파일에는 `\n`, `\t`의 두 코드가 기록됨

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/0d201b1c-0049-4bae-b8ab-7af8a810daa5)

### 텍스트 파일의 내부

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/6a0f8fd9-1f91-4434-b135-2f72de889c92)

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/57c12f38-afe7-462d-9eec-37843f2a0899)

### 바이너리 파일

- 바이너리 파일이란?
    - 문자로 표현되지 않는 바이너리 데이터가 기록된 파일
        - 이미지, 오디오, 그래픽, 컴파일된 코드는 문자로 표현되지 않음
    - 텍스트 파일의 각 바이트 → 문자로 해석
    - 바이너리 파일의 각 바이트 → 문자로 해석되지 않는 것도 있음
        - 각 바이트의 의미는 파일을 만든 응용프로그램만이 해석 가능
- 바이너리 파일의 종류
    - jpeg, bmp 등의 이미지 파일
    - mp3 등의 오디오 파일
    - hwp, doc, ppt 등의 확장자를 가진 멀티미디어 문서 파일
    - obj, exe 등의 확장자를 가진 컴파일된 코드나 실행 파일

### 바이너리 파일의 내부

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/88e27551-03f4-4ef9-ad58-5c38b8f8477e)

### hwp 파일은 텍스트 파일인가 바이너리 파일인가

- hwp 파일은 바이너리 파일이다.
    - 텍스트 정보 포함
        - 한글이나 영어 문자 포함
    - 바이너리 정보 포함
        - 글자 색이나 서체 등의 문자 포맷 정보
        - 비트맵 이미지
        - 표
        - 선, 원 등의 그래픽 정보
        - 왼쪽 마진, 오른쪽 마진 등 문서 포맷 정보

## 파일 입출력 개요

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/d354db42-e06f-416c-8b5e-d43de9d6e75e)

C++ 표준 파일 입출력 라이브러리

### 템플릿에 `char` 타입으로 구체화한 클래스들

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/550daec0-bb51-4a87-8754-1c3f99ee0f3f)

### 파일 입출력 스트림은 파일을 프로그램과 연결

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/a3375aca-8431-415c-a359-7b3f389852a3)

- `>>` 연산자와 istream의 get, read 함수
    - 연결된 장치로부터 읽는 함수
    - 키보드에 연결되면 키 입력을, 파일에 연결되면 파일에서 입력
- `<<` 연산자와 ostream의 put, write 함수
    - 연결된 장치에 쓰는 함수
    - 스크린에 연결되면 화면에, 파일에 연결되면 파일에 출력

### 헤더 파일과 namespace

- C++ 파일 입출력 라이브러리 사용
    - <fstream> 헤더 파일과 std 이름 공간의 선언 필요

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/5a3b41a3-fbbb-423b-968c-f8631ac09eb6)

### 파일 입출력 모드 : 텍스트 I/O와 바이너리 I/O

- 파일 입출력 방식
    - 텍스트 I/O와 바이너리 I/O의 두 방식
        - C++ 파일 입출력 클래스는 두 방식 지원
- 텍스트 I/O
    - 문자 단위로 파일에 쓰기, 파일에서 읽기
        - 문자를 기록하고 읽은 바이트를 문자로 해석
    - 텍스트 파일에만 적용
- 바이너리 I/O
    - 바이트 단위로 파일에 쓰기, 파일에서 읽기
        - 데이터를 문자로 해석하지 않고 있는 그대로 기록하거나 읽음
    - 텍스트 파일과 바이너리 파일 모두 입출력 가능
- 텍스트 I/O와 바이너리 I/O 입출력 시 차이점
    - 개형 문자(`\n`)를 다루는 데 있음

### `<<` 연산자를 이용한 간단한 파일 출력

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/cd13104a-a3cd-409e-b17f-fc106cbe67c6)

### 파일 모드

- 파일 모드란?
    - 파일 입출력에 대한 구체적인 작업 형태에 대한 지정
    - 사례)
        - 파일에서 읽을 작업을 할 것인지, 쓰기 작업을 할 것인지
        - 기존파일의 데이터를 모두 지우고 쓸 것인지, 파일의 끝 부분에 쓸 것인지
        - 텍스트 I/O 방식인지 바이너리 I/O 방식인지
- 파일 모드 지정 - 파일 열 때
    - open(”파일이름”, 파일모드)
    - ifstream(”파일이름”, 파일모드)
    - ofstream(”파일이름”, 파일모드)
    
    ![image](https://github.com/choiht0904/Cpp_01/assets/77330457/71518618-30e7-4bab-8723-d550efa0101e)


### 파일 모드 설정

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/0abf1c64-78eb-4151-8435-0376b491ab49)

### get()과 EOF

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/4f72a6db-c0f6-4997-8477-80931140e25b)

### get()으로 파일의 끝을 인지하는 방법

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/b612cbac-e5a6-4c45-992a-1326a8dcdfb7)

### 파일의 끝을 잘못 인지하는 코드

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/c60e1531-33a9-4d31-9a57-39f48a92dd99)

### 텍스트 파일의 라인 단위 읽기

- 2가지 방법
    - istream의 getline(char* line, int n) 함수 이용
    - getline(ifstream& fin, string& line) 함수 이용

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/348d6bf4-b281-4b26-a291-483f08649952)

### 바이너리 I/O

- 바이너리 I/O 방식
    - 데이터의 바이너리 값을 그대로 파일에 저장하거나 파일의 바이너리값을 그대로 읽어서 변수나 버퍼에 저장하는 방식
    - 텍스트 파일이든 바이너리 파일이든 바이너리 I/O로 입출력 가능
- 바이너리 I/O 모드 열기
    - ios::binary 모드 속성 사용
        - ios::binary가 설정되지 않으면 디폴트가 텍스트 I/O
        
        ![image](https://github.com/choiht0904/Cpp_01/assets/77330457/13105988-c6fb-4c34-ab07-d6ccf73fb48f)


### read()/write()로 블록 단위 파일 입출력

- get()/put()
    - 문자 혹은 바이트 단위로 파일 입출력
- read()/write()
    - 블록 단위로 파일 입출력

 ![image](https://github.com/choiht0904/Cpp_01/assets/77330457/d852a158-2f65-494b-91ce-10adee25d082)

# 예외 처리와 C언어와의 링크 지정

## 실행오류와 오류 처리

### 오류

- 컴파일 오류
    - 문법에 맞지 않는 구문으로 인한 오류
- 실행 오류
    - 개발자의 논리 오류
    - 예외적으로 발생하는 입력이나 상황에 대한 대처가 없을 때 발생하는 오류
    - 실행 오류의 결과

## 예외와 예외 처리

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/7efe270a-2787-46c6-a840-f26ffa37502d)

## C++ 예외 처리 기본 형식

### try-throw-catch

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/9dfa27db-21f8-4616-ba10-ce528011e61b)

### throw와 catch

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/a29b26ef-b67e-43b2-b107-201ae8cf304a)

### try-throw-catch의 예외 처리 과정

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/b2432cd3-c08c-4006-bae6-524708af7cba)

### throw와 catch의 예

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/e1f033c5-3d09-47e9-b54b-d683eb90d1d9)

### 예외를 발생시키는 함수의 선언

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/6ae10120-a800-47ba-9e0b-3ad9b9bf950d)

### 다중 try {} 블록

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/0b623e3e-5cfc-42a0-99d6-227c2e4d649e)

## 예외 클래스 만들기

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/43d507c3-0f9d-4f64-9f1c-6603d129d8a4)

## C++ 코드에서 C 코드의 링킹

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/24a37d29-fca8-44f0-bf2e-4779cb1e83c3)

### C 프로그램의 컴파일과 링킹

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/1a742499-45cc-4066-b260-83b846aaf8ea)

### C++ 소스의 컴파일과 링킹

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/2a6e7152-9c1f-45c9-8385-b7ef2a336e8a)

### C++에서 C 함수 호출 시 링크 오류 발생

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/8472c93b-1197-45a4-b9b1-0014fa2f9fbf)

### 비주얼 C++에서의 링크 오류 메시지

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/9e342d15-4a46-450a-872f-48efb72ba533)

### extern “C”

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/c1642a58-eb97-4cc9-836a-5ea37d7e4d83)
