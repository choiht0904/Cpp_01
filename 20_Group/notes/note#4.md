# 정리노트#4

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
> 중복 불가능한 연산자 : [.], [.*], [::], [? :]
- 연산자 함수 구현 방법 2가지
  - 클래스의 멤버 함수로 구현
  - 외부 함수로 구현하고 클래스에 프렌드 함수로 선언
- 연산자 함수 형식
> {리턴타입} operator{연산자}(매개변수리스트);
- 예제

```c++
// 외부 함수로 구현되고 클래스에 프렌드로 선언되는 경우 
Color operator+ (Color op1, Color op2); // 외부 함수
bool operator== (Color op1, Color op2); // 외부 함수

class Color {
	friend Color operator+ (Color op1, Color op2);
	friend bool operator== (Color op1, Color op2);
};

// 클래스의 멤버 함수로 작성되는 경우
class Color {
	Color operator+ (Color op2);
	bool operator== (Color op2);
}
```


## 단항 연산자 중복

- 피연산자가 하나 뿐인 연산자
- 단항 연산자 종류
    - 전위 연산자 : ++a, --a
    - 후위 연산자 : a++, a--
- 특성
    - 전위(++a) 증가 연산자를 중복 정의할 때 리턴 타입에 참조(&)를 사용하면 객체를 참조로 반환하여 해당 객체의 직접 수정을 허용하게 됩니다.
    - 후위(a++) 증가 연산자를 중복 정의할 때는 리턴 타입에 참조(&)를 사용하지 않고 객체를 값으로 반환합니다.
- 예제

```c++
class Power {
	int kick;
	int punch;
public:
	Power(int kick=0, int punch=0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power& operator++ (); // 전위 ++ 연산자 함수 선언
	Power operator++ (int x); // 후위 ++ 연산자 함수 선언
};

void Power::show() {
	cout << "kick=" << kick << ','
	<< "punch=" << punch << endl;
}

Power& Power::operator++() {
	kick++;
	punch++;
	return *this; // 변경된 객체 자신(객체 a)의 참조 리턴
}

Power Power::operator++(int x) {
	Power tmp = *this; // 증가 이전 객체 상태를 저장
	kick++;
	punch++;
	return tmp; // 증가 이전 객체 상태 리턴
}
```

# Pair Programming

```C++
// 이 중에서 에러가 나지 않는 것을 고르시오.
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

> 1번의 경우 반환 유형이 Power&이고 *this를 반환하므로 객체에 대한 참조를 반환합니다.
> 
> 2번의 경우 반환 유형이 Power이고 *this를 반환하므로 객체를 복사하여 반환합니다.
> 
> 3번의 경우 this는 포인터 형식이므로 Power&를 반환하는 함수에서 this를 반환하는 것은 일치하지 않습니다.
> 
> 4번의 경우 반환 유형이 Power *이고 this를 반환하므로 객체의 포인터를 반환합니다.
> 
> 5번의 경우 반환 유형이 Power이지만 this는 포인터 형식이므로 일치하지 않습니다.
