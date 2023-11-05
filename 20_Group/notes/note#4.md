<span style="color:red; background-color:gray"> .dwdw </span>  
<font color="red">빨간색</font>

# 정리노트

## 프렌드

- 클래스의 멤버가 아니지만 클래스의 속성, 함수(private, protected)에 접근할 때 사용함
- 프렌드 함수의 종류 3가지
  - 전역 함수 : 클래스 외부에 선언된 전역 함수
  - 다른 클래스의 멤버 함수 : 다른 클래스의 특정 멤버 함수
  - 다른 클래스의 전체 : 다른 클래스의 모든 멤버 함수
- 선언 방식

```c++
// 외부 함수 equals()를 Rect 클래스에 프렌드로 선언
class Rect;
bool equals(Rect r, Rect s);

class Rect {
    int width, height;
public:
    Rect(int width, int height) {
        this->width = width;
        this->height = height;
    }
    friend bool equals(Rect r, Rect s);
};

bool equals(Rect r, Rect s) {
    if(r.width == s.width && r.height == s.height) return true;
    else return false;
}

// RectManager 클래스의 equals() 멤버 함수를 Rect 클래스에 프렌드로 선언
class Rect;
class RectManager {
public:
    bool equals(Rect r, Rect s);
};

class Rect {
    int width, height;
public:
    Rect(int width, int height) {
        this->width = width;
        this->height = height;
    }
    friend bool RectManager::equals(Rect r, Rect s);
};

bool RectManager::equals(Rect r, Rect s) {
    if(r.width == s.width && r.height == s.height) return true;
    else return false;
}

//RectManager 클래스의 모든 멤버 함수를 Rect 클래스에 프렌드로 선언
class Rect;
class RectManager {
public:
    bool equals(Rect r, Rect s);
    void copy(Rect& dest, Rect& src);
};

class Rect {
    int width, height;
public:
    Rect(int width, int height) {
        this->width = width;
        this->height = height;
    }
    friend RectManager;
};

bool RectManager::equals(Rect r, Rect s) {
    if(r.width == s.width && r.height == s.height) return true;
    else return false;
}

void RectManager::copy(Rect& dest, Rect& src) {
    dest.width = src.width;
    dest.height = src.height;
}
```

## 연산자 중복

- C++ 언어에 본래 있는 연산자만 중복 가능
    - 3%%5, 6##7 → 컴파일 오류
- 연산자는 함수 형태로 구현 → 연산자 함수
- 반드시 클래스와 관계를 가짐
- 피연산자의 개수를 바꿀 수 없음
- 연산의 우선 순위 변경 안됨
- 모든 연산자가 중복 가능하지 않음
> 중복 불가능한 연산자 : ., .*, ::, ? :

- 연산자 함수 구현 방법 2가지
  - 클래스의 멤버 함수로 구현
  - 외부 함수로 구현하고 클래스에 프렌드 함수로 선언


## 단항 연산자 중복



## 프렌드를 이용한 연산자 중복



# Pair Programming

```C++
Power& ret_This() {
	return *this;
}

Power ret_This() {
	return *this;
}

Power& ret_This() {
	return this;
}

Power * ret_This() {
	return this;
}

Power ret_This() {
	return this;
}
```
