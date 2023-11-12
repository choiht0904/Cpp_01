# 정리노트#5

## 상속

### C++에서 상속이란?

- 기본 클래스의 속성과 기능을 파생 클래스에 물려주는 것
  - 기본 클래스(부모 클래스) - 상속해주는 클래스
  - 파생 클래스(자식 클래스) - 상속받는 클래스
- 기본 클래스에서 파생 클래스로 갈수록 클래스의 개념이 구체화
- 다중 상속을 통한 클래스의 재활용성 높임

### 상속의 목적 및 장점

- 간결한 클래스 작성 가능
- 클래스간의 계층적 분류 및 관리의 용이함
- 클래스 재사용과 확장을 통한 소프트웨어 생산성 향상

### 상속 선언 예시

```C++
// 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
class Point {
    int x, y; //한 점 (x,y) 좌표값
public:
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void showPoint() {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

// 2차원 평면에서 컬러점을 표현하는 클래스 ColorPoint. Point를 상속받음
class ColorPoint : public Point { 
    string color;// 점의 색 표현
public:
    void setColor(string color) {
        this->color = color;
    }
    void showColorPoint();
};

void ColorPoint::showColorPoint() {
    cout << color << ":";
    showPoint(); // Point의 showPoint() 호출
}
```

## 업 캐스팅과 다운 캐스팅

- 업 캐스팅
  - 파생 클래스의 포인터가 기본 클래스의 포인터에 치환되는 것
  - 업 캐스팅 예시

```C++
int main() {
	ColorPoint cp;
	ColorPoint *pDer = &cp;
	Point* pBase = pDer; // 업캐스팅
	pDer->set(3,4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColorPoint();
	pBase->showColorPoint(); // 컴파일 오류
}
```

- 다운 캐스팅
  - 기본 클래스의 포인터가 파생 클래스의 포인터에 치환되는 것
  - 업 캐스팅 예시

```C++
int main() {
	ColorPoint cp;
	ColorPoint *pDer;
	Point* pBase = &cp; // 업캐스팅
	pBase->set(3,4);
	pBase->showPoint();
	pDer = (ColorPoint *)pBase; // 다운캐스팅
	pDer->setColor("Red"); // 정상 컴파일
	pDer->showColorPoint(); // 정상 컴파일
}
```

## 접근 지정자

- private 멤버
  - 선언된 클래스 내에서만 접근 허용
  - 파생 클래스에서도 기본 클래스의 private 멤버에 직접 접근 불가
- public 멤버
  - 선언된 클래스나 외부 어떤 클래스, 모든 외부 함수에서 접근 허용
  - 파생 클래스에서도 기본 클래스의 public 멤버에 접근 가능
- protected
  - 선언된 클래스에서 접근이 가능하지만 파생 클래스가 아닌 클래스나 외부 함수에서 직접 접근 불가
  - 파생 클래스에서만 접근 허용

## 상속 지정

- 상속 선언 시 public, protected, private의 3가지 중 하나를 지정
- 기본 클래스의 멤버의 접근 속성을 어떻게 계승할지 지정
  - public - 기본 클래스의 protected, public 멤버 속성을 그대로 계승
  - protected - 기본 클래스의 protected, public 멤버 속성을 protected로 계승
  - private - 기본 클래스의 protected, public 멤버 속성을 private으로 계승

## 다중 상속

### 다중 상속의 문제점

- 기본 클래스 멤버의 중복 상속

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/1e786b14-d293-447b-a349-62f3b0bb17c0)

> Base의 멤버가 이중으로 객체에 삽입되는 문제점이 있음
> 
> 동일한 x를 접근하는 프로그램이 서로 다른 x에 접근하는 결과를 낳아 잘못된 실행 오류가 발생된다

## 가상 상속

- 다중 상속으로 인한 기본 클래스 멤버의 중복 상속 문제를 해결
- 파생 클래스의 선언문에서 기본 클래스 앞에 virtual로 선언
- 파생 클래스의 객체가 생성될 때 기본 클래스의 멤버는 오직 한 번만 생성

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/2bcd02ab-3d52-4490-a969-2f77d6ec1393)

# Pair Programming

![image](https://github.com/choiht0904/Cpp_01/assets/77330457/f7b552bc-14ce-4ac5-9c72-95ce82e164fc)

> 상속 관계로 본 클래스의 간결화 사례
>
> 말하기, 먹기, 걷기, 잠자기는 클래스의 기능이 중복되어 있기 때문에 이 4가지를 제외하고 보면 **공부하기 <- 일하기** | **연구하기 <- 가르치기**로 볼 수 있다.
> 일하기는 공부하기에 상속되고 가르치기는 연구하기에 상속되어, 결국 4개의 기능은 부모 클래스로 작성되어 자식 클래스가 가져다 사용하는 것으로, 상속 관계로 클래스의 간결화를 만들 수 있다고 조원과 대화를 통해 정리하였다.
