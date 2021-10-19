#prama once 

#include "/include/generator.h"
#include "/include/constants.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

int i = 0;
int sample;

void generator_init(wave_type type){
    // set io to 12bit (4096 levels)
    analogWriteResolution(12);
    analogWriteResolution(12);
    // attach interrupt wave toggle
    attachInterrupt(BUTTON_1, wave_toggle, RISING);
    WAVE_0 = type;
    // attach led notification
    pinMode(PIN_LED_1, OUTPUT);
}

void generator_wave_loop(wave_type type){
    // map potentiometer values between min & max
    // 1Hz-170Hz for complete wave
    int sample = map(analogRead(A0), 0, 4095, 0, SampleOneHertz);
    sample = contraint(t_sample, 0, SampleOneHertz);

    // write wave to DAC0/DAC1
    // led notification
    digitalWrite(PIN_LED_1, HIGH);
    analogWrite(DAC0, wave_table[WAVE_0][i]);
    analogWrite(DAC1, wave_table[WAVE_0][i]); 
    digitalWrite(PIN_LED_1, LOW);

    // increment or reset counter
    i++;
    if(i == SampleMaxNum){
        i = 0;
    }
    delayMicroseconds(sample);
}

void wave_toggle(){
    WAVE_0++;
    if(WAVE_0 == 4){
        WAVE_0 = 0;
    }
}