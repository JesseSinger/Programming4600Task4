#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
#include <setVoltageFunctions.h>
#include <setVoltageFreqAmpOffset.h>
#include <openInstrument.h>
#include <setPhase.h>
#include <outputOn.h>
#include <outputOff.h>
#include <linearSweep.h>


ViSession viDG1022;

float frequency = 20000.0;
float amplitude = 2.0;
float offset = .5;
float phase = 10.0;
float startFreq = 150.0;
float stopFreq = 1000.0;
float sweepyTime = 10.0;

int initialization(void)
{
  openInstrument();
setVoltageUnit(0);
sleep(2);
setVoltageFreqAmpOffset(viDG1022,frequency, amplitude, offset);
setPhase(viDG1022,phase);
outputOn(viDG1022);
linearSweep(viDG1022,startFreq, stopFreq, sweepyTime);
 
  return 0;

}

int 
setup(void)
{

  return 0;
}

int
loop(void)
{

  return 0;
}

int
cleanup(void)
{
  return 0;
}

  
int  
main(void)  
{  

  int r = 0;
  r = initialization();
  if(!r) r = setup();
  if(!r) r = loop();
  r = cleanup();
  
  return(0);  
}  