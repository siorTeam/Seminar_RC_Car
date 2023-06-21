#include <SoftwareSerial.h>
//SoftwareSerial 라이브러리 추가
//SoftwareSerial 라이브러리 사용하여 HC-06 블루투스 모듈과 아두이노 연결

int A_1A = 9;  //A-1A 핀을 6번 핀에 연결함
int A_1B = 10; //A-1B 핀을 5번 핀에 연결함
int B_1A = 6;  //B-1A 핀을 10번 핀에 연결함
int B_1B = 5;  //B-1B 핀을 9번 핀에 연결함
//A-1A 말고 6을 써도 상관 없으나 헷갈리지 않도록 변수 선언을 함

// 블루투스 모듈과 아두이노가 서로 '출력 <-> 입력'한다.
// RX와 TX라는 두 개의 정수 변수를 정의하는 것으로 시작합니다. 
int btRxPin = 4; //(아두이노 기준) 입력(RX) 핀을 4번 핀에 연결 (블루투스 모듈을 기준으로는 TXD: 4번출력핀이다.)
int btTxPin = 3; //(아두이노 기준) 출력(TX) 핀을 3번 핀에 연결 (블루투스 모듈을 기준으로는 RXD: 3번 입력핀이다.)
SoftwareSerial bluetoothSerial(btRxPin, btTxPin); // "블루투스"라는 새로운 소프트웨어 직렬 개체를 만듦
 

int speed = 255;
void setup() {
  //void: 조건 없이(즉 공허, void)에서 시작합니다.
  // 준비 코드
  bluetoothSerial.begin(9600);
  pinMode(A_1A, OUTPUT); //A-1A 핀(아두이노 6번 핀)을 출력용으로 사용함 (모터(드라이버)에 전기 신호를 넣어주는거니깐)
  pinMode(A_1B, OUTPUT); //A-1B 핀(아두이노 5번 핀)을 출력용으로 사용함
  pinMode(B_1A, OUTPUT); //B-1A 핀(아두이노 10번 핀)을 출력용으로 사용함
  pinMode(B_1B, OUTPUT); //A-1B 핀(아두이노 9번 핀)을 출력용으로 사용함
  digitalWrite(A_1A, LOW); //A-1A 핀(아두이노 5번 핀)에 LOW(=0) 값으로 출력
  digitalWrite(A_1B, LOW); //A-1B 핀(아두이노 5번 핀)에 LOW(=0) 값으로 출력
  digitalWrite(B_1A, LOW); //B-1A 핀(아두이노 5번 핀)에 LOW(=0) 값으로 출력
  digitalWrite(B_1B, LOW); //B-1B 핀(아두이노 5번 핀)에 LOW(=0) 값으로 출력
}


//모터(A:오른, B:왼)_방향(1A: 뒤, 1B: 앞)
void loop() {
  //loop: 아래 문장을 계속 반복합니다. 
  //analogWrite: PWM 신호를 이용하여 아날로그로 값을 출력하겠다. / digitalWrite: digital 신호를 이용하여 0 또는 1로 값을 출력하겠다.
  if (bluetoothSerial.available()>0){ //bluetooth.available() 함수를 사용하여 블루투스 모듈에 사용 가능한 데이터가 있다면
    char cmd = bluetoothSerial.read(); // cmd라는 변수에 bluetooth.read()를 사용하여 읽은 값을 할당함 (이때 바이트 단위로 읽으므로, 한 글자만 읽을 수 있다.)
    switch (cmd) { //cmd 의 값에 따라 다음 동작을 한다.
    default: // 초기 조건 
      analogWrite(A_1A, 0);
      analogWrite(A_1B, 0);
      analogWrite(B_1A, 0);
      analogWrite(B_1B, 0);
    case 'b': // b 입력 받았을 경우 (후진)
      analogWrite(A_1A, speed);
      analogWrite(A_1B, 0);
      analogWrite(B_1A, speed);
      analogWrite(B_1B, 0);
      break;
    case 'f': // f 입력 받았을 경우 (전진)
      analogWrite(A_1A, 0);
      analogWrite(A_1B, speed);
      analogWrite(B_1A, 0);
      analogWrite(B_1B, speed);
      break;
    case 'r': // r 입력 받았을 경우 (우회전)
      analogWrite(A_1A, 0);
      analogWrite(A_1B, speed*2/3);
      analogWrite(B_1A, 0);
      analogWrite(B_1B, speed);
      break;
    case 'l': // l 입력 받았을 경우 (좌회전)
      analogWrite(A_1A, 0);
      analogWrite(A_1B, speed);
      analogWrite(B_1A, 0);
      analogWrite(B_1B, speed*2/3);
      break; 
    case 'x': // x 입력 받았을 경우 (정지 시)
      analogWrite(A_1A, 0);
      analogWrite(A_1B, 0);
      analogWrite(B_1A, 0);
      analogWrite(B_1B, 0);
      break;
    }
  }
}
