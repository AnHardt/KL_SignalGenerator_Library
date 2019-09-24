#ifndef KL_SIGNALGENERATOR_H
#define KL_SIGNALGENERATOR_H

#include "Arduino.h"

float SignalGeneratorStartTime(void);
float SignalGeneratorStartTimeS(float);
float SignalGeneratorSetTime(void);
float SignalGeneratorSetTimeS(float s);

float SignalGeneratePWM(float amplitude, float bias, float periodTime, float offsetTime, float PWM); // PWM [0.0 ... 1.0]
float SignalGenerateSqu(float amplitude, float bias, float periodTime, float offsetTime);
float SignalGeneratePulse(float amplitude, float bias, float periodTime, float offsetTime, float pulseTime);
float SignalGenerateSin(float amplitude, float bias, float periodTime, float offsetTime);
float SignalGenerateSaw(float amplitude, float bias, float periodTime, float offsetTime);
float SignalGenerateNoise(float amplitude, float bias);
float SignalGenerateRPeaks(float amplitude, float bias, float frequency); // frequency [0.0 ... 1.00]

#endif // KL_SIGNALGENERATOR_H
