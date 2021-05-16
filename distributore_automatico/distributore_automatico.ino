int red = 2;  //red, yellow, green and blue represent food
int yellow = 3;
int green = 4;
int blue = 5;
int white = 6;    //how much money does he lack

int button1 = 8;  //button1 to button4 represent the number of food 
int button2 = 9;
int button3 = 10;
int button4 = 11;

int money = 0;
String pressed;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("insert 10 at a time (max 0.90€)");
}

void allLow() {
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(white, LOW);
}

void moneyLess(int num) {
  int len = (num - money) / 10;
  for (int i = 0; i < len; i++) {
    digitalWrite(white, HIGH);
    delay(1000);
    digitalWrite(white, LOW);
    delay(1000);
  }
}

void printMoney() {
  Serial.print("you have: 0.");
  Serial.print(money);
  Serial.println("€");
}

void loop() {
  
  if (Serial.available() > 0 && money < 90) {
    pressed = Serial.read();
    if (pressed.equals("49") == true) {   //49 stand for 10
      money += 10;    //10 stand for 0.10€
      printMoney();
    }
  }

  if (digitalRead(button1) == LOW) {
    if (money >= 20) {
      allLow();
      digitalWrite(red, HIGH);
      money -= 20;
      Serial.println("purchase made successfully");
    }
    
    else {
      printMoney();
      moneyLess(20);
    }
  }

  if (digitalRead(button2) == LOW) {
    if (money >= 30) {
      allLow();
      digitalWrite(yellow, HIGH);
      money -= 30;
      Serial.println("purchase made successfully");
    }
    
    else {
      printMoney();
      moneyLess(30);
    }
  }

  if (digitalRead(button3) == LOW) {
    if (money >= 40) {
      allLow();
      digitalWrite(green, HIGH);
      money -= 40;
      Serial.println("purchase made successfully");
    }
    
    else {
      printMoney();
      moneyLess(40);
    }
  }

  if (digitalRead(button4) == LOW) {
    if (money >= 50) {
      allLow();
      digitalWrite(blue, HIGH);
      money -= 50;
      Serial.println("purchase made successfully");
    }
    
    else {
      printMoney();
      moneyLess(50);
    }
  }
}
