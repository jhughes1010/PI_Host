//defines
#define NAME "PI Pro - 2023"
#define VERSION "1.0.3"


//#define DEBUG 1

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

//=================================
//Defines
//=================================
#define MS *1E-3
#define US *1E-6
#define NS *1E-9
#define CNT_PERIOD 62.5e-9
#define LCD_START 0


//pins
#define AUDIO 11
#define VBAT A2
#define SIGNAL A3

//constants
#define CAL_BATTERY .0145
#define VSIG_LOW 1.5
#define VSIG_HIGH 3.5

//temp config
int batteryType = 0;


//Timing Structures
struct CountCycle {
  word txWidthCount;
  word sampleDelayCount;
  word sampleWidthCount;
  word efeDelayCount;
  word efeWidthCount;
  word aquirePeriodCount;
};

struct TimingCycleUs {
  float txWidth;
  float sampleDelay;
  float sampleWidth;
  float efeDelay;
  float efeWidth;
  float aquirePeriod;
};

CountCycle cycleCNT;    // holds CNT values to transmit to PI client
TimingCycleUs timing;   // holds desired timing targets in uS
TimingCycleUs offsets;  // holds timing offsets or minimum cycle times
