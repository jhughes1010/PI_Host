// Timing related functions and settings
float coilPulseWidthArray[4] = {20 US, 30 US, 40 US, 60 US};
float targetSampleWidthArray[3] = {15 US, 30 US, 45 US};


//--------------------
// setTimingTargets - load desired PI timing parameters
//--------------------
void setTimingTargets (float tx, float sampleDly, float sample, float efeDly, float efe, float period)
{
  timing.txWidth = tx;
  timing.sampleDelay = sampleDly;
  timing.sampleWidth = sample;
  timing.efeDelay = efeDly;
  timing.efeWidth = efe;
  timing.aquirePeriod = period;
}


//--------------------
// setTimingOffsets - load desired PI timing parameters
//--------------------
void setTimingOffsets (float tx, float sampleDly, float sample, float efeDly, float efe, float period)
{
  offsets.txWidth = tx;
  offsets.sampleDelay = sampleDly;
  offsets.sampleWidth = sample;
  offsets.efeDelay = efeDly;
  offsets.efeWidth = efe;
  offsets.aquirePeriod = period;
}

//--------------------
// loadCounters - Calculate and load CNT struct
//--------------------
void loadCounters(void)
{
  unsigned int cycleCNTsum;

  cycleCNT.txWidthCount = (int)((timing.txWidth - offsets.txWidth) / CNT_PERIOD);
  cycleCNT.sampleDelayCount = (int)((timing.sampleDelay - offsets.sampleDelay) / CNT_PERIOD);
  cycleCNT.sampleWidthCount = (int)((timing.sampleWidth - offsets.sampleWidth) / CNT_PERIOD);
  cycleCNT.efeDelayCount = (int)((timing.efeDelay - offsets.efeDelay) / CNT_PERIOD);
  cycleCNT.efeWidthCount = (int)((timing.efeWidth - offsets.efeWidth) / CNT_PERIOD);
  //cycleCNTsum = cycleCNT.txWidthCount + cycleCNT.sampleDelayCount + cycleCNT.sampleWidthCount + cycleCNT.efeDelayCount + cycleCNT.efeWidthCount;
  cycleCNT.aquirePeriodCount = (int)((timing.aquirePeriod - offsets.aquirePeriod) / CNT_PERIOD);
}


//--------------------
// printCounters - Dump counter values to serial
//--------------------
void printCounters (void)
{
  debug("TX CNT: ");
  debugln(cycleCNT.txWidthCount);
  debug("SampleDelay CNT: ");
  debugln(cycleCNT.sampleDelayCount);
  debug("Sample CNT: ");
  debugln(cycleCNT.sampleWidthCount);
  debug("EFEDelay CNT: ");
  debugln(cycleCNT.efeDelayCount);
  debug("EFE CNT: ");
  debugln(cycleCNT.efeWidthCount);
  debug("Period CNT: ");
  debugln(cycleCNT.aquirePeriodCount);
  debug("\n\n");
}
