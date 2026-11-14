//=========================================================================
//
// File:    def.h
// Created by Ronja@SL
//
// Project: projektuebergreifend
//
//=========================================================================

#pragma strong_types

#define MAGIERNAME "ronja"

#define TELLPLAYER(x) tell_object(TP,x)
#define TELLOTHERS(x) tell_room(ENV(TP),x,({TP}))
#define TPUID capitalize(getuid(this_player()))
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define CTPN capitalize(this_player()->name())

#define CUSTOMIZE previous_object()->CustomizeObject()

#include "../def.h"

