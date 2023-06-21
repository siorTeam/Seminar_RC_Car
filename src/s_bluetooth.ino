#include <SoftwareSerial.h> 
//SoftwareSerial 라이브러리 추가
//SoftwareSerial 라이브러리 사용하여 HC-06 블루투스 모듈과 아두이노 연결
 
 // 블루투스 모듈과 아두이노가 서로 '출력 <-> 입력'한다.
 // RX와 TX라는 두 개의 정수 변수를 정의하는 것으로 시작합니다. 
int RX=4; // (아두이노 기준) 입력 핀을 4번 핀에 연결 (블루투스 모듈을 기준으로는 TXD: 4번출력핀이다.)
int TX=3; // (아두이노 기준) 출력 핀을 3번 핀에 연결 (블루투스 모듈을 기준으로는 RXD: 3번 입력핀이다.)
SoftwareSerial bluetooth(RX, TX); // "블루투스"라는 새로운 소프트웨어 직렬 개체를 만듦
 


void setup(){
  Serial.begin(9600); //시리얼 통속도 9600
  bluetooth.begin(9600); //블루투스 통신속도 9600
  //이름.begin(통신속도)
}


    //이름.available: 이름에서 읽을 수 있는 데이터가 있는지 확인
    //이름.read() 데이터의 다음 바이트를 읽음
void loop(){ //조건 없이 시작하여(void) 다음 문장을 무한히 반복(loop(){...}})
  if (bluetooth.available()) { //bluetooth.available() 함수를 사용하여 블루투스 모듈에 사용 가능한 데이터가 있는지 지속적으로 확인
    Serial.write(bluetooth.read()); // bluetooth.read()를 사용하여 읽은 다음 Serial.write()를 사용하여 Arduino의 하드웨어 직렬 포트(Serial)에 즉시 씀

  }
  if (Serial.available()) { //Serial.available()을 사용하여 Arduino의 하드웨어 직렬 포트(Serial)에 사용 가능한 데이터가 있는지 확인함
    bluetooth.write(Serial.read()); //데이터가 있으면 Serial.read()를 사용하여 읽음
  }
}
