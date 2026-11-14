//=========================================================================
//
// File:    def.h
// Created by Ronja@SL
//
// Project: Sternenwald
//
//=========================================================================

#pragma strong_types

#define GEBIET "sternenwald"

#include "../def.h"

#define SWMASTER ZONE "master/master"
#define KMASTER ZONE "master/killmaster"
#define SAVEFILE ZONE "master/kills"
#define ANSCHLUSS "/d/unterwelt/basics/central/room/00+05-15"
#define ANSCHLUSSLATHSPELL "/d/unterwelt/lathspell/alchemisten/room/d_7_4"
#define GEMMASTER "/obj/gemmaster"

#define LW(x) (sizeof(x)==1 ? x[0] : implode(x[0..<2],", ")+" und "+x[<1])

#define QUESTNAME "Das Schweigen der Rumpelwichte"

/* Einhoerner ************************************************************/

#define P_FARBE "fellfarbe"
#define P_GESCHLECHT "pgeschlecht" // hengst stute fohlen

#define T_HENGST         0
#define T_STUTE          1
#define T_FOHLEN         2

#define T_BRONZEN        0
#define T_KUPFERN        1
#define T_SILBERN        2
#define T_GOLDEN         3
#define T_SCHWARZ        4
#define T_WEISS          5

