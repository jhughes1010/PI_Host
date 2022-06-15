//defines
#define NAME "PI Pro - 2022"
#define VERSION "1.0.0a"


#define DEBUG 1

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif


//pins
#define AUDIO 11
#define VBAT A2
#define SIGNAL A3
