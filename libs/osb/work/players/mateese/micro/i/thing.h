#ifndef SYS_THING_H
#define SYS_THING_H 1

#include <base.h>
#include "moving.h"

// Properties

#define P_Adjs        "Adjs"
#define P_BaseWeight  "BaseWeight"
#define P_BaseValue   "BaseValue"
#define P_Bright      "Bright"
#define P_Cleanup     "Cleanup"
#define P_Damage      "Damage"
#define P_DamageCap   "DamageCap"
#define P_Followers   "Followers"
#define P_IDs         "IDs"
#define P_LastID      "LastID"
#define P_LastPlayer  "LastPlayer"
#define P_LastVerb    "LastVerb"
#define P_Light       "Light"
#define P_Long        "Long"
#define P_Noise       "Noise"
#define P_NoTake      "NoTake"
#define P_NoDrop      "NoDrop"
#define P_NoGive      "NoGive"
#define P_Resistance  "Resistance"
#define P_Short       "Short"
#define P_Smell       "Smell"
#define P_Weight      "Weight"
#define P_Value       "Value"

// Effective Properties

#define E_DamageDsc   "DamageDsc"  // computed from P_Damage and P_DamageCap
#define E_ExaLong     "ExaLong"    // stored as P_Long[1]
#define E_RelDamage   "RelDamage"  // computed from P_Damage and P_DamageCap

#endif
