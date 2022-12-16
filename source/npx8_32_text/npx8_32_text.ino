/*  PROJECT : Neopixel pannel 8X32
 *  STEP / TOPIC : ninguno
 *  MCU tested: ALL
 *  Start day : 
 *  TARGET : Limpiar skech con BLINK y debug a 9600
 *  AUTHOT : J.C. SANTAMARIA POZA
 *  LICENSE : CC-BY-NC-SA
 *   Conections :
 */

#define PROJECT "Neopixel pannel 8X32 (npx8_32)" // chnage with the name of prject
#define PSTART_DATE "15-12-2022" // Change with proejct start date
#define VERSION "0.2" // version major, minor
#define VER_TXT_M "Neopixel 5vol 8x32 pannel-test texto"
#define VER_TXT_MI " corregido ciclado de color 0 a 7"


// comment bellow line to NO-DEBUG, un comment to DEBUG
#define DEBUG
#ifdef DEBUG
 #define DEBUG_PRINT(x)       Serial.print(x)
 #define DEBUG_PRINTDEC(x)    Serial.print(x, DEC)
 #define DEBUG_PRINTLN(x)     Serial.println(x)
 #define NODEBUG_SERIALEND
#else
 #define DEBUG_PRINT(x)
 #define DEBUG_PRINTDEC(x)
 #define DEBUG_PRINTLN(x)
 #define NODEBUG_SERIALEND    Serial.end()
#endif

// ************** INCLUDES ****************
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

// ************** DEFINES ****************
// #define PIN LED_BUILTIN // usa led "L" u tro a elegir
#define PIN 6
#define MAXLUZ 255

// ********************* CONSTRUCTORES ***************
// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_BOTTOM    + NEO_MATRIX_RIGHT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
  
// ********************* GLOBAL VARIABLES ***************
const uint16_t colors[] = {
  matrix.Color(MAXLUZ, 0, 0), // index = 0 -> red
  matrix.Color(0, MAXLUZ, 0), // green
  matrix.Color(MAXLUZ, MAXLUZ, 0), // yellow = red + green
  matrix.Color(0, 0, MAXLUZ), // blue
  matrix.Color(MAXLUZ, 0, MAXLUZ), // index = 4 -> pink = red + blue
  matrix.Color(0, MAXLUZ, MAXLUZ), // index = 5 --> green + blue 
  matrix.Color(MAXLUZ, MAXLUZ, MAXLUZ)}; // index 6 --> red + green + blue

  int coor_x    = matrix.width(); // start writtin in last horizontal led
  int color_index = 0; // color pass starts with "red"
  
// ********************* SET UP CODE it runs once ***************
void setup() 
  {
  // ********************* Generic JCSP debug code ***************
    // Enable serial
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
                  }           
  #ifdef DEBUG
    Serial.println("");
    Serial.println("===========================================================");
    Serial.print(F(" Proyecto "));  Serial.print(PROJECT); Serial.print(F(" Start Date: "));  Serial.println(PSTART_DATE);
    Serial.print(F("Skecht :"));
    Serial.print(__FILE__);  Serial.print("\t"); Serial.print(__DATE__);  Serial.print("\t"); Serial.println(__TIME__); 
    Serial.print(F(" Version "));  Serial.println(VERSION);
    Serial.print(F("Paso: "));  Serial.print(VER_TXT_M);   Serial.println(VER_TXT_MI);
    
    // Print some ESP ONLY version info
    // Serial.printf("ESP ONLY : setup: core=%s, sdk=%s, freq=%d\n",ESP.getCoreVersion().c_str(),ESP.getSdkVersion(),ESP.getCpuFreqMHz() );
    // Serial.printf("ESP ONLY : setup: sdk=%s, freq=%d\n",ESP.getSdkVersion(),ESP.getCpuFreqMHz() );
    
    Serial.println("===========================================================");
  #endif   // *********************END Generic JCSP debug code ***************
  
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(25);
  matrix.setTextColor(colors[0]);

 }

// ********************* LOOP CODE it runs over and over again forever ***************
void loop() {
  matrix.fillScreen(0);    //Turn off all the LEDs
  matrix.setCursor(coor_x, 0);
  matrix.print(F("Sofia Ines"));
  DEBUG_PRINT("Color index "); DEBUG_PRINTDEC(color_index); DEBUG_PRINT(" Coor X "); DEBUG_PRINTLN(coor_x);

  if( --coor_x < -30 ) {
    coor_x = matrix.width();

    if(++color_index >= 7) color_index = 0;
    matrix.setTextColor(colors[color_index]);
  }
  matrix.show();
  delay(120);
}
