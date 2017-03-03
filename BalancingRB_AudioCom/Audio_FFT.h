#define LOG_OUT 1 // use the log output function
#define FFT_N 32 // set to 64 point fft
#include <FFT.h> // include the library
#define AUDIO_IN A0
    int *Audio[4];
    int A[4];
    int Max_value[4]={0};
void Audio_FFT_loop(){
  noInterrupts(); // Enter critical section to reduces jitter
  for (int i = 0 ; i < (FFT_N*2) ; i += 2) { // save signal samples
    int k = analogRead(AUDIO_IN);
    //k -= 0x0200; // form into a signed int
    //k <<= 6; // form into a 16b signed int
    fft_input[i] = k; // put real data into even bins
    fft_input[i+1] = 0; // set odd bins to 0
  }
  interrupts(); // Escape from critical section
  fft_window(); // window the data for better frequency response
  fft_reorder(); // reorder the data before doing the fft
  fft_run(); // process the data in the fft
  fft_mag_log(); // take the output of the fft
  
  //Serial.println("start");
  for (byte i = 0 ; i < 4 ; i++) { 
    
    A[i] = fft_log_out[4*i+2];// send out the data
    Audio[i]= &A[i]; 
    if ( Max_value[i] < *Audio[i] ) Max_value[i] = *Audio[i]; 
  } 
  *Audio[0]=map(*Audio[0], 0, Max_value[0], 0, 8);
  *Audio[1]=map(*Audio[1], 0, Max_value[1], 0, 8);
  *Audio[2]=map(*Audio[2], 0, Max_value[2], 0, 8);
  *Audio[3]=map(*Audio[3], 0, Max_value[3], 0, 8);  
}
