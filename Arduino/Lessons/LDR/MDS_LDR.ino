// LDR Contants
const float GAMMA = 0.7;  
const float RL10 = 50;

#define VOLT_METER_POS A1  // Volt Meter Pos probe
#define VOLT_METER_NEG A0  // Neg probe
#define LED_PIN      2
#define DIM_THRESHOLD 600 // Lux to turn on LED

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  Serial.println("Hello Cavaliers");
  pinMode(VOLT_METER_POS,INPUT);
  pinMode(VOLT_METER_NEG,INPUT);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Raw Voltage input Values (0-1024)
  int voltNegValue;  // Negative lead
  int voltPosValue;  // Positive lead

  // Inputs converted to volts ((Raw/1024) * 5 Volts)
  float voltNeg;     
  float voltPos;
  float lux;
  
  // Read inputs
  voltNegValue = analogRead(VOLT_METER_NEG);
  voltPosValue = analogRead(VOLT_METER_POS);

  // Convert to volts
  voltNeg = voltNegValue / 1024. * 5;
  voltPos = voltPosValue / 1024. * 5;
  
  // Calculate light intensity (Lux)
  lux = calcLux(voltPos);
  
  // Print to serial port
  Serial.print("(-) Value: ");
  Serial.print(voltNegValue);
  Serial.print(" Volts: ");
  Serial.print(voltNeg);
  
  Serial.print(" (+) Value: ");
  Serial.print(voltPosValue);
  Serial.print(" Volts: ");
  Serial.print(voltPos);

  Serial.print(" Diff: ");
  Serial.print(voltPos-voltNeg);
  Serial.print(" Volts ");

  // Turn on LED if dim light
  if(lux<DIM_THRESHOLD) {
    digitalWrite(LED_PIN,HIGH);
  } else {
    digitalWrite(LED_PIN,LOW);
  }
  Serial.print(" Lux: ");
  Serial.println(lux); 
  delay(500);
}


// Calculate light intensity in Lux from voltage across LDR
float calcLux(float volts) {
  float resistance = 990 * volts / (1 - volts / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));
  return lux;
}
