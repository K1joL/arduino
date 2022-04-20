#include <Adafruit_NeoPixel.h>
#define PIN 6
#define count_led 64
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(count_led, PIN, NEO_GRB + NEO_KHZ800);colors
void setup() {
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  for (int k=0;k<count_led;k++)
  	pixels.setPixelColor(k,pixels.Color(0,0,0));
  pixels.show();
  delay(1000);
  
  int arr[8][8] = {
  {0,1,1,0,0,1,1,0},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0}
};
  int temp = 0;
  for (int i=0; i<8;i++){
    if (!(i%2)) continue;
    for (int j=0; j<4;j++){
      temp = arr[i][7-j];
      arr[i][7-j] = arr[i][j];
      arr[i][j] = temp;
    }
  }
  int k = 0;
  while (k < count_led){
 	  for (int i=0;i<8;i++){
      for (int j=0; j<8; j++){
    	if (arr[i][j]) pixels.setPixelColor(k,pixels.Color(255,0,0));
     	k++;
      }
	  }
  }
     pixels.show();
 	 delay(1000);
}
