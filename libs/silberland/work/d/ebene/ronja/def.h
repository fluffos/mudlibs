//=========================================================================
//
// File:    def.h
// Created by Ronja@SL
//
//=========================================================================

#pragma strong_types

#define MAGIERNAME "ronja"

#include "../def.h"

#define LW(x) (sizeof(x)==1 ? x[0] : implode(x[0..<2],", ")+" und "+x[<1])

#define TELLPLAYER(x) tell_object(TP,x)
#define TELLOTHERS(x) tell_room(ENV(TP),x,({TP}))

#define TPUID capitalize(getuid(this_player()))
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define CTPN capitalize(this_player()->name())

#define CUSTOMIZE previous_object()->CustomizeObject()

