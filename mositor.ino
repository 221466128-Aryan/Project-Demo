// This #include statement was automatically added by the Particle IDE.

#include <DHT.h>



#define DHTPIN D2

DHT dht(DHTPIN, DHT22);


double temp;
double hum;
int moisture;


void setup() {
    dht.begin();
    Serial.begin(9600);
    Particle.variable("temp", &temp, DOUBLE);
    Particle.variable("hum", &hum, DOUBLE);
    Particle.variable("moisture", &moisture, INT);
}

void loop() {
    
    temp = dht.readTemperature(); // Gets the values of the temperature
    hum = dht.readHumidity();
    moisture = analogRead(A4);
    
    if (moisture <= 500)
    {
        Particle.publish("beep");
    }
    Particle.publish("temp", String(temp), PRIVATE);
    Particle.publish("hum", String(hum), PRIVATE);
    Particle.publish("moisture", String(moisture), PRIVATE);
    delay(1000); 
}