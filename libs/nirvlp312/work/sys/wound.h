#ifndef _sys_wound_h
#define _sys_wound_h

#define WT_SPRAIN      "sprain"      // casused through overuse
#define WT_CUT         "cut"         // caused through light cutting damage
#define WT_SLASH       "slash"       // caused through med cutting damage
#define WT_GASH        "gash"        // caused through severe cutting damage
#define WT_BURN        "burn"        // caused through burning damage
#define WT_SCALD       "scald"       // caused through scalding damage
#define WT_BRUISE      "bruise"      // caused through light crushing damage
#define WT_LACERATION  "laceration"  // caused through medium crushing damage
#define WT_FRACTURE    "fracture"    // caused through severe crushing damage
#define WT_PUNCTURE    "puncture"    // caused through light impaling damage
#define WT_STAB        "stab"        // caused through medium impaling damage
#define WT_FLESHWOUND  "fleshwound"  // caused through severe impaling damage

#define WOUND_TYPES    ({ WT_SPRAIN,WT_CUT,WT_SLASH,WT_GASH,WT_BURN,\
                          WT_SCALD,WT_BRUISE,WT_LACERATION,WT_FRACTURE,\
                          WT_PUNCTURE,WT_STAB,WT_FLESHWOUND })

#endif /* _sys_wound_h */
