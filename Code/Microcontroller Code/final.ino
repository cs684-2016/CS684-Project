/*
* Author
* ------
* 
* Naman Rastogi (163050056)
* M.Tech Student, CSE
* IIT Bombay
*/

// ============================================================================
//
// Ports
//
// ============================================================================

/*
* Connections
* -----------
* 
* PA_2 - Connect Heater
* PA_3 - Connect Motor Fan
* PA_5 - Connect Water Motor Pump
* PA_6 - Connect LDR Light / Internal Light
* PE_1 - Connect LDR
* PE_2 - Connect YL69 (Soil Moisture Sensor)
* PE_3 - Connect LM35 (Temperature Sensor)
*/

#define LED1 RED_LED
#define LED2 GREEN_LED
#define LED3 BLUE_LED

int Relay1 = PA_2; // Heater
int Relay2 = PA_3; // Motor Fan
int Relay3 = PA_5; // Motor Pump
int Relay4 = PA_6; // LDR Light

int temperaturePort = A0; // PE_3
int moisturePort = A1; // PE_2
int lightPort = A2; // PE_1




// ============================================================================
//
// Global Variables
//
// ============================================================================

bool automaticTemperatureControl;
bool automaticMoistureControl;
int temperatureToMaintain;
int moistureToMaintain;
int temperatureTolerance;
float dataTemperature;
float dataMoisture;
int dataLight;

#define TEMPERATURE_COEFFICIENT 13.0
#define MOISTURE_COEFFICIENT 50.0

unsigned long currentTime;
unsigned long lastRelay3ChangeTime;
unsigned long intervalOnRelay3;
unsigned long intervalOffRelay3;
bool lastRelay3State;




// ============================================================================
//
// Initial Setup
//
// ============================================================================

void setup() {
  pinMode( temperaturePort, INPUT );
  pinMode( moisturePort, INPUT );
  pinMode( lightPort, INPUT );
  pinMode( LED1, OUTPUT );
  pinMode( LED2, OUTPUT );
  pinMode( LED3, OUTPUT );
  pinMode( Relay1, OUTPUT );
  pinMode( Relay2, OUTPUT );
  Serial.begin(9600);

  automaticTemperatureControl = false;
  automaticMoistureControl = false;
  temperatureTolerance = 5;

  lastRelay3ChangeTime = 0;
  intervalOnRelay3 = 5000;
  intervalOffRelay3 = 10000;
  lastRelay3State = LOW;
}




// ============================================================================
//
// This loop will run continuously
//
// ============================================================================

/*
* Options
* -------
* 
* T   - return Temperature from sensor
* M   - return Moisture from sensor
* a x - set LED1 to x
* b x - set LED2 to x
* c x - set LED3 to x
* d x - set Relay1 to x
* e x - set Relay2 to x
* t x - set Temperature to be maintained near x
* m x - set Moisture to be maintained near x
* R   - reset
*/

void loop() {

// Data read from sensors
  dataTemperature = analogRead( temperaturePort ) / TEMPERATURE_COEFFICIENT;
  dataMoisture = analogRead( moisturePort ) / MOISTURE_COEFFICIENT;
  dataLight = analogRead( lightPort );
  currentTime = millis();

  if ( Serial.available() > 0 ) {
    char device = Serial.read();
    
// Return Temperature sensor (LM35) data 
    if ( device == 'T' ) {
      Serial.println( dataTemperature );
    }

// Return Moisture sensor (YL69) data 
    else if ( device == 'M' ) {
      Serial.println( dataMoisture );
    }

// Return Light sensor (LDR) data
    else if ( device == 'L' ) {
      Serial.println( dataLight );
    }

// Red LED
    else if ( device == 'a' ) {
      while ( Serial.available() <= 0 );
      char state = Serial.read();
      if ( state == '1' )
        digitalWrite( LED1, HIGH );
      else if ( state == '0' )
        digitalWrite( LED1, LOW );
    }

// Green LED
    else if ( device == 'b' ) {
      while ( Serial.available() <= 0 );
      char state = Serial.read();
      if ( state == '1' )
        digitalWrite( LED2, HIGH );
      else if ( state == '0' )
        digitalWrite( LED2, LOW );
    }

// Blue LED
    else if ( device == 'c' ) {
      while ( Serial.available() <= 0 );
      char state = Serial.read();
      if ( state == '1' )
        digitalWrite( LED3, HIGH );
      else if ( state == '0' )
        digitalWrite( LED3, LOW );
    }
    
// Relay 1 - Light Bulb
    else if ( device == 'd' ) {
      while ( Serial.available() <= 0 );
      char state = Serial.read();
      if ( state == '1' )
        digitalWrite( Relay1, HIGH );
      else if ( state == '0' )
        digitalWrite( Relay1, LOW );
    }

// Relay 2 - Motor Fan
    else if ( device == 'e' ) {
      while ( Serial.available() <= 0 );
      char state = Serial.read();
      if ( state == '1' )
        digitalWrite( Relay2, HIGH );
      else if ( state == '0' )
        digitalWrite( Relay2, LOW );
    }

// Relay 3 - Motor Pump
    else if ( device == 'f' ) {
      while ( Serial.available() <= 0 );
      char state = Serial.read();
      if ( state == '1' )
        digitalWrite( Relay3, HIGH );
      else if ( state == '0' )
        digitalWrite( Relay3, LOW );
    }

// Relay 4 - LDR Light
    else if ( device == 'g' ) {
      while ( Serial.available() <= 0 );
      char state = Serial.read();
      if ( state == '1' )
        digitalWrite( Relay4, HIGH );
      else if ( state == '0' )
        digitalWrite( Relay4, LOW );
    }


// Profile Temperature
    else if ( device == 't' ) {
      while ( Serial.available() <= 0 );
      temperatureToMaintain = Serial.read();
      automaticTemperatureControl = true;
      Serial.print( temperatureToMaintain - temperatureTolerance );
      Serial.print( "-" );
      Serial.println( temperatureToMaintain + temperatureTolerance );
    }

// Profile Moisture
    else if ( device == 'm' ) {
      while ( Serial.available() <= 0 );
      moistureToMaintain = Serial.read();
      automaticMoistureControl = true;
      Serial.println( moistureToMaintain );
    }

// RESET
    else if ( device == 'R' ) {
       digitalWrite( LED1, LOW );
       digitalWrite( LED2, LOW );
       digitalWrite( LED3, LOW );
       digitalWrite( Relay1, LOW );
       digitalWrite( Relay2, LOW );
       automaticTemperatureControl = false;
       automaticMoistureControl = false;
       Serial.println( "Reset" );
    }
    
  }

  
// Temperature maintenance
  if ( automaticTemperatureControl ) {
    if ( dataTemperature < temperatureToMaintain - temperatureTolerance ) {
      digitalWrite( Relay1, HIGH );
      digitalWrite( Relay2, LOW );
    }
    else if ( dataTemperature > temperatureToMaintain + temperatureTolerance ) {
      digitalWrite( Relay1, LOW );
      digitalWrite( Relay2, HIGH );
    }
  }


// Moisture maintenance
  if ( automaticMoistureControl ) {
    if ( ( dataMoisture > moistureToMaintain ) && ( currentTime - lastRelay3ChangeTime > intervalOffRelay3 ) && ( lastRelay3State == LOW ) ) {
      digitalWrite( Relay3, HIGH );
      lastRelay3State = HIGH;
      lastRelay3ChangeTime = currentTime;
    }
    if ( ( currentTime - lastRelay3ChangeTime > intervalOnRelay3 ) && ( lastRelay3State == HIGH ) ) {
      digitalWrite( Relay3, LOW );
      lastRelay3State = LOW;
      lastRelay3ChangeTime = currentTime;
    }
  }

// Internal light maintenance
  if ( dataLight < 100 ) {
    digitalWrite( Relay4, HIGH );
  }
  else if ( dataLight > 100 ) {
    digitalWrite( Relay4, LOW );
  }
  
}
