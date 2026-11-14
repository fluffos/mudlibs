//=========================================================================
//
// File:    def.h
// Created by Ronja@SL
//
// Project: Eheringquest
//
//=========================================================================

#pragma strong_types

#define GEBIET "eheringquest"

#define EMASTER "/d/" REGION "/" MAGIERNAME "/" GEBIET    "/master/master"
#define ZARMOUR "/d/" REGION "/" "zordan"   "/" "dhrkion" "/" "armour" "/"
#define ZROOM   "/d/" REGION "/" "zordan"   "/" "dhrkion" "/" "room"   "/"
#define MAINID "\nzakobj"
#define ID_EISENSCHLUESSEL ROOM "kerker" ":" ROOM "kloake3"
#define ID_HORNSCHLUESSEL  ROOM "gang11" ":" ROOM "kloake2"

#define EHERINGQUEST "Rette Xatanas Ehe"
#define EHERINGQUESTLOG "/log/quests/ehering"

#define P_SLEEP "schlafend"

#define DBR(x) if(find_player("ronja")) tell_object(find_player("ronja"),(x))

#include "../def.h"

