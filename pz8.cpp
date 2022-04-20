#include <Adafruit_NeoPixel.h>
#define PIN 6
#define count_led 64
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(count_led, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  for (int k=0;k<count_led;k++)
 	 pixels.setPixelColor(k,pixels.Color(0,0,0));
  pixels.show();
  delay(1000);
  
  int arr[64]/*={
  0,0,0,0,0,0,0,0,
  0,1,0,0,0,0,1,0,
  0,1,1,0,0,1,1,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,1,0,0,1,0,0,
  0,1,0,1,1,0,1,0,
  0,0,0,0,0,0,0,0
};*/;
  for (int k = 0; k<64; k++)
   arr[k] = rand()%2;
    for (int i=0;i<64;i++){
    		if (arr[i])
              pixels.setPixelColor(i,pixels.Color(255,0,0));
    }
    
  pixels.show();
  delay(1000);
  
  
}
