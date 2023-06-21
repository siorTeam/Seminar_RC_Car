int motor_A_1A = 6; //A-1A 핀을 6번 핀에 연결함
int motor_A_1B = 5; //A-1B 핀을 5번 핀에 연결함
int motor_B_1A = 10; //B-1A 핀을 10번 핀에 연결함
int motor_B_1B = 9; //B-1B 핀을 9번 핀에 연결함
//A-1A 말고 6을 써도 상관 없으나 헷갈리지 않도록 변수 선언을 함

void setup() {
  //void: 조건 없이(즉 공허, void)에서 시작합니다
  // 준비 코드
  pinMode(motor_A_1A, OUTPUT); //A-1A 핀(아두이노 6번 핀)을 출력용으로 사용함
  pinMode(motor_A_1B, OUTPUT); //A-1B 핀(아두이노 5번 핀)을 출력용으로 사용함
  pinMode(motor_B_1A, OUTPUT); //B-1A 핀(아두이노 10번 핀)을 출력용으로 사용함
  pinMode(motor_B_1B, OUTPUT); //A-1B 핀(아두이노 9번 핀)을 출력용으로 사용함
}

void loop() { 
  //void: 조건 없이(즉 공허, void)에서 시작합니다
  //loop: 아래 문장을 계속 반복합니다.
  //analogWrite와 digitalWrite에 대한 설명은 다음 세미나에 하겠습니다. 궁금하시면 질문 주세요!
  delay(2000); //2000ms (2초) 후에 시작합니다.
  analogWrite(motor_A_1A, 255/3); //A-1A 핀(아두이노 6번 핀)의 255/3의 값으로 출력
  digitalWrite(motor_A_1B, 0); //A-1b 핀(아두이노 5번 핀)의 0의 값으로
  analogWrite(motor_B_1A, 255/3); 
  digitalWrite(motor_B_1B, 0); 

  delay(2000);
  analogWrite(motor_A_1A, 255*2/3);
  digitalWrite(motor_A_1B, 0);
  analogWrite(motor_B_1A, 255*2/3);
  digitalWrite(motor_B_1B, 0);

  delay(2000);
  analogWrite(motor_A_1A, 255);
  digitalWrite(motor_A_1B, 0);
  analogWrite(motor_B_1A, 255);
  digitalWrite(motor_B_1B, 0);
}
