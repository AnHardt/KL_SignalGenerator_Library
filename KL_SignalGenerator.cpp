#include "KL_SignalGenerator.h"
#include "limits.h"

float SignalGeneratorSignalTime = 0.0f; // by default in ms
float SignalGeneratorStartT = 0.0f;

float SignalGeneratorStartTime(void) {
  return SignalGeneratorStartT = millis()/1000.0f;
}
float SignalGeneratorStartTimeS(float s) {
  return SignalGeneratorStartT = s;
}

float SignalGeneratorSetTime(void) {
  return SignalGeneratorSignalTime = millis()/1000.0f - SignalGeneratorStartT;
}
float SignalGeneratorSetTimeS(float s) {
  return SignalGeneratorSignalTime = s - SignalGeneratorStartT;
}

float SignalGeneratePWM(float amplitude, float bias, float periodTime, float offsetTime, float PWM) {
  float T = fmod((SignalGeneratorSignalTime + offsetTime), periodTime);
  if (T < periodTime*PWM)
    return  amplitude + bias;
  else
    return 0.0f + bias;
}

float SignalGenerateSqu(float amplitude, float bias, float periodTime, float offsetTime) {
  return SignalGeneratePWM(amplitude, bias, periodTime, offsetTime, 0.5);
}

float SignalGeneratePulse(float amplitude, float bias, float periodTime, float offsetTime, float pulse) {
  return SignalGeneratePWM(amplitude, bias, periodTime, offsetTime, ((float)pulse / (float)periodTime));
}

float SignalGenerateSin(float amplitude, float bias, float periodTime, float offsetTime) {
  float T = fmod((SignalGeneratorSignalTime + offsetTime), periodTime);
  return amplitude/2.0f*sin(PI*2.0f * T/periodTime) + bias;
}

float SignalGenerateSaw(float amplitude, float bias, float periodTime, float offsetTime) {
  float T = fmod((SignalGeneratorSignalTime + offsetTime), periodTime);
  return  bias + amplitude*T/periodTime;
}

float SignalGenerateNoise(float amplitude, float bias) {
  return bias + amplitude * random(INT_MIN,INT_MAX)/(INT_MIN*-2.0f);
}
