#ifndef WEATHER_H
#define WEATHER_H

#include "nightday.h"

  // Array indices into a state description

#define WD_STATE     0  // The current state
#define WD_LENGTH    1  // Duration of the state
#define WD_SUNLIGHT  2  // Sunlight (0..MAX_SUNBRIGHT)
#define WD_DESC      3  // State description
#define WD_CDESC     4  // Description of the change into this state
#define WD_WDESC     5  // Statechange as seen through window (or door).

#define WD_USER      6  // First free entry

#endif
