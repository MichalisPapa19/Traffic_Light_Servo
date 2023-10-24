#include <Servo.h>
Servo serv1;
int buttonPin = 3; // ορίζουμε το pin που συνδέει το κουμπί
int red1Pin = 7; // ορίζουμε το pin του κόκκινου LED των αυτοκινήτων
int yellow1Pin = 4; // ορίζουμε το pin του κίτρινου LED των αυτοκινήτων
int green1Pin = 2; // ορίζουμε το pin του πράσινου LED των αυτοκινήτων
int red2Pin = 13; // ορίζουμε το pin του κόκκινου LED των πεζών
int green2Pin = 12; // ορίζουμε το pin του πράσινου LED των πεζών

int buttonState = 0; // αρχική κατάσταση του κουμπιού

void setup() {
  pinMode(buttonPin, INPUT); // ρυθμίζουμε το κουμπί ως είσοδο
  pinMode(red1Pin, OUTPUT); // ρυθμίζουμε τα LED ως έξοδο
  pinMode(yellow1Pin, OUTPUT);
  pinMode(green1Pin, OUTPUT);
  pinMode(red2Pin, OUTPUT);
  pinMode(green2Pin, OUTPUT);
  serv1.attach(5);
}

void loop() {
  buttonState = digitalRead(buttonPin); // διαβάζουμε την κατάσταση του κουμπιού
  
  if (buttonState == HIGH) { // αν το κουμπί πατηθεί
    
    digitalWrite(red1Pin, LOW); // κόκκινο φανάρι αυτοκινήτων
    digitalWrite(yellow1Pin, LOW); // κίτρινο φανάρι αυτοκινήτων
    digitalWrite(green1Pin, HIGH); // πράσινο φανάρι αυτοκινήτων
    digitalWrite(red2Pin, HIGH); // κόκκινο φανάρι πεζών
    digitalWrite(green2Pin, LOW); // πράσινο φανάρι πεζών
    delay(3000); // περιμένουμε 3 δευτερόλεπτα
    digitalWrite(yellow1Pin, HIGH); // κίτρινο φανάρι αυτοκινήτων
    digitalWrite(green1Pin, LOW); // πράσινο φανάρι αυτοκινήτων
    delay(1000); // περιμένουμε 1 δευτερόλεπτο
    digitalWrite(red1Pin, HIGH); // κόκκινο φανάρι αυτοκινήτων
    digitalWrite(yellow1Pin, LOW); // κίτρινο φανάρι αυτοκινήτων
    delay(1000); // περιμένουμε 1 δευτερόλεπτο
    digitalWrite(red2Pin, LOW); // κόκκινο φανάρι πεζών
    digitalWrite(green2Pin, HIGH); // πράσινο φανάρι πεζών
    delay(2000); // περιμένουμε 5 δευτερόλεπτα
    
    serv1.write(0);
    delay(7000);
    serv1.write(90);
    delay(3000);
    
    digitalWrite(green2Pin, LOW); // πράσινο φανάρι πεζών
    digitalWrite(red2Pin, HIGH); // κόκκινο φανάρι πεζών

    
    
} else { // αν το κουμπί δεν πατηθεί
    digitalWrite(red1Pin,LOW ); // κόκκινο φανάρι αυτοκινήτων
    digitalWrite(yellow1Pin, LOW); // κίτρινο φανάρι αυτοκινήτων
    digitalWrite(green1Pin, HIGH); // πράσινο φανάρι αυτοκινήτων
	digitalWrite(red2Pin, HIGH);
}
}
