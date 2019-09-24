/*
 * Modeling a bad DV voltage with KL_SignalGenerator_Library
 * 
 * View with Arduino SerialPlotter at 250000 baud
 */

#include "KL_SignalGenerator.h"

#define SAMPLETIME (5.0f/1000.0f)

void setup() {
  Serial.begin(250000);

  // Initialize the time for the Signal Generators
  SignalGeneratorStartTime();
}

void loop() {
  // A clean DC Voltage
  float sig = 3.3f;
  float sig0 = sig;

  // Set the time for the Signal Generators from millis() timer.
  SignalGeneratorSetTime();
  
  // Add the onipresent 50/60 Hz humm. 
  sig += SignalGenerateSin(sig0/20.0f, 0.0f, 1.0f/50.0f, 0.0f);

  // Add a low frequent variation. For examüle from a bang bang heater
  sig += SignalGenerateSqu(-sig0/10.0f, 0.0, 4.0f, 2.0f);

  // Add some higher freqency AC
  sig += SignalGenerateSin(sig0/25.0f, 0.0f, 1.0f/666.6f, 0.0f);

  // Add some random spikes
  sig += SignalGenerateRPeaks(0.5f, 0.0f, 0.001f);

  // And finaly a bit of random noise
  sig += SignalGenerateNoise(sig0/50.0f, 0.0f);
  
  Serial.print("Clean:");
  Serial.print(sig0);
  Serial.print(",Bad:");
  Serial.print(sig,4);
  
  Serial.println();

  static uint16_t n = 0;
  if (++n > 1500)
    while(0); // Set to 1 to stop after 1500 samples 
}
