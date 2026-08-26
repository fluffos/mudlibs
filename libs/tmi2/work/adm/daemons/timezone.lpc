//
// These are functions useful for determining the actual time where a
// player is, based on an environment variable, TZONE.
//
// 20.Jan.92
//
// Written by DocZ @ TMI.
//
// 93.07.17 - hacked to use half hours to support Newfies and central Aussies.
//

// This controls the MUD local time zone. Define your time zone as the
// number of half-hours to ADD to Greenwich Mean Time to get your time zone.
// For example: Greenwich Time = 0, British Standard = -2, Eastern Standard
// = -10, Central Standard = -12, Central European = +2, Australian Standard
// = +24.
//
// The #define in <config.h> now has precedent (if present)
#include <config.h>

#ifndef LOCAL_TIME_ZONE
#define LOCAL_TIME_ZONE -12
#endif

// Reminder: LOCAL_TIME_ZONE is the number of hours behind GMT (negative)
//           or number of hours ahead of GMT (positive), times 2.

int query_tzone(string str) {
  int offset; 
  switch (str) {
//  case "   ": { offset = -22; break; } // -11h  (Nome)
//  case "AST": { offset = -20; break; } // -10h  Aleutian Standard (Tahiti)
    case "YST": { offset = -18; break; } // -9h   Yukon Standard
    case "PST": { offset = -16; break; } // -8h   Pacific Standard
    case "MST": { offset = -14; break; } // -7h   Mountain Standard
    case "CST": { offset = -12; break; } // -6    Central Standard
    case "EST": { offset = -10; break; } // -5h   Eastern Standard
    case "AST": { offset = - 8; break; } // -4h   Atlantic Standard
    case "NST": { offset = - 7; break; } // -3.5h Newfoundland Standard
//  case "   ": { offset = - 6; break; } // -3h   (Rio de Janeiro)
//  case "   ": { offset = - 4; break; } // -2h   (Azores)
//  case "   ":                          // -1h   (Iceland)
    case "BST": { offset = - 2; break; } // -1h   British Summer
    case "WET": 			 //       Western European
    case "PWT": 			 //       Portugese Winter
    case "GMT": { offset =   0; break; } //       Greenwich Mean
    case "MET":				 // +1h   Middle European
    case "CET": { offset =   2; break; } // +1h   Central European
    case "SAST":                         //       South Africa Standard
    case "EET": { offset =   4; break; } // +2h   Eastern European
//  case "   ": { offset =   6; break; } // +3h   (Baghdad)
//  case "   ": { offset =   8; break; } // +4h   (Reunion)
//  case "   ": { offset =  10; break; } // +5h   (Karachi)
//  case "   ": { offset =  12; break; } // +6h   (Dacca)
//  case "   ": { offset =  14; break; } // +7h   (Bangkok)
//  case "   ": { offset =  16; break; } // +8h   (Manila)
    case "AWT": { offset =  16; break; } // +8h   Australian Western
//  case "   ": { offset =  18; break; } // +9h   (Kyoto)
    case "ACT": { offset =  19; break; } // +9.5h Australian Central
    case "AET": { offset =  20; break; } // +10h  Australian Eastern
    case "NZST":                         // +12h  New Zealand Standard
    case "NZT": { offset =  24; break; } // +12h  New Zealand
    default   : {
      float user_offset;
      if (str && sscanf(str, "(%fh)", user_offset) == 1) {
          if (user_offset <= 12 && user_offset >= -12) {
              offset = to_int(floor(user_offset * 2.0));
  	      break;
	  }
      } 
      return 0; /* ERROR */
    }
  }
  offset = (offset - LOCAL_TIME_ZONE) * 30 * 60;
  return (time()+offset);
}

void show_tzone_list() {
    write( @ENDLIST
Supported time zone abbreviations are:

    PST (Pacific Standard),	    MST (Mountain Standard),
    CST (Central Standard),	    EST (Eastern Standard),
    AST (Atlantic Standard),	    NST (Newfoundland Standard),
    YST (Yukon Standard),	    GMT (Greenwich Mean),
    BST (British Summer),	    PWT (Portugese Winter),
    WST (Western European),	    EET (Eastern European),
    CET (Central European),	    MET (Middle European),
    SAST (South African Standard),  AWT (Australian Western),	
    ACT (Australian Central),	    AET (Australian Eastern),
    NZT (New Zealand),		    NZST (New Zealand Standard).

If _YOUR_ time zone isn't listed, please leave mail with an admin.
Be sure to include the abbreviation, the full name, and the number
of hours difference from GMT (Greenwhich Mean Time)!

Note: You can specify TZONE numerically as the time difference in
hours from GMT.  For example, GMT - 8 hours would be: 'set TZONE (-8h)'.
ENDLIST
    );
    return;
}
