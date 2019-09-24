#define SAMPLES 500
#define SAMPLETIME (5.0f/1000.0f)

#include "KL_SignalGenerator.h"

float NextSampleTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  NextSampleTime = SignalGeneratorStartTime() + SAMPLETIME;
}

void loop() {
  Serial.println();

  SignalGeneratorSetTime();
  Serial.print("Square:");
  Serial.print(SignalGenerateSqu(5.0, 0.0, 0.200, 0.050));
  Serial.print(",PWM:");
  Serial.print(SignalGeneratePWM(2.0, -1.0, 0.125, 0.0, 0.1));
  Serial.print(",Pulse:");
  Serial.print(SignalGeneratePulse(6.0, 0.0, 0.150, 0.0, 0.010));
  Serial.print(",Sin:");
  Serial.print(SignalGenerateSin(2.0, 1.0, 0.200, 0.025));
  Serial.print(",Saw+:");
  Serial.print(SignalGenerateSaw(3.0, 0.0, 0.250, 0.0));
  Serial.print(",Saw-:");
  Serial.print(SignalGenerateSaw(-3.0, 3.0, 0.250, 0.0));
  Serial.print(",Noise:");
  Serial.print(SignalGenerateNoise(0.5, -0.25));
  Serial.print(",RandomPeaks:");
  Serial.print(SignalGenerateRPeaks(7.0, 0.0, 0.001));

  static uint16_t overrun = 0;
  overrun = 1;
  while (millis()/1000.0f < NextSampleTime) overrun = 0;
  Serial.print(",Overrun:");
  Serial.print(overrun);
  NextSampleTime += SAMPLETIME; 
  static uint16_t i = 0;
  if (i++ >  SAMPLES)
    while(0);
}
