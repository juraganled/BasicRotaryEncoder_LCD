#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <ESP32RotaryEncoder.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// Change these to the actual pin numbers that you've connected your rotary encoder to
const uint8_t DI_ENCODER_A   = 25;
const uint8_t DI_ENCODER_B   = 26;
const int8_t  DI_ENCODER_SW  = 27;
const int8_t  DO_ENCODER_VCC = 14;

RotaryEncoder rotaryEncoder( DI_ENCODER_A, DI_ENCODER_B, DI_ENCODER_SW, DO_ENCODER_VCC );

void knobCallback( long value )
{
  lcd.setCursor(8,1);         // set position to column 8, row 1
  lcd.print(value);           // print rotary value
  lcd.print(" ");
}

void buttonCallback( unsigned long duration )
{
	// do something
}

void setup()
{
  lcd.init();                       // initialize the lcd 
  lcd.init();
  lcd.clear();                      // make sure the LCD is clean
  lcd.backlight();                  // turn on LCD backlight
  lcd.setCursor(0,1);               // set position to column 0, row 1
  lcd.print("Value = ");       

	
	rotaryEncoder.setEncoderType( EncoderType::HAS_PULLUP );  // This tells the library that the encoder has its own pull-up resistors

	rotaryEncoder.setBoundaries( 1, 10, true ); // range minimum, maximum, wrap around

	rotaryEncoder.onTurned( &knobCallback );    // call this function everytime the know is turned

	rotaryEncoder.onPressed( &buttonCallback ); // if the button is pushed then this function is called

	rotaryEncoder.begin();
}

void loop()
{
	// Your stuff here
}
