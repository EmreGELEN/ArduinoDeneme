int kirmiziPin = 5;

int yesilPin = 10;

int maviPin = 11;

#define trigPin 9

#define echoPin 8

void setup()

{
  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(kirmiziPin, OUTPUT);

  pinMode(yesilPin, OUTPUT);

  pinMode(maviPin, OUTPUT);

}

void loop()

{
  long sure, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  distance = (sure / 2) / 29.1;


  if (distance >= 0 && distance < 30) {
    changeColour (255, 0, 0);  // kirmizi
  }
  if (distance >= 30 && distance < 60) {
    changeColour (255, 255, 0);  // sarı
  }
  if (distance >= 60 && distance < 100) {
    changeColour (0, 100, 0);  // yeşil
  }
  if (distance >= 100 && distance < 150) {
    changeColour (0, 0, 255);  // mavi
  }
  if (distance >= 150 && distance < 180) {
    changeColour (139, 0, 139);  // mor
  }
  Serial.println(distance);
  delay(100);

}

void changeColour(int kirmizi, int yesil, int mavi)

{

  kirmizi = 255 - kirmizi;

  yesil = 255 - yesil;

  mavi = 255 - mavi;

  analogWrite(kirmiziPin, kirmizi);

  analogWrite(yesilPin, yesil);

  analogWrite(maviPin, mavi);

}
