//=========================================================================
//
// File:    def.h
// Created by Yason@Andracia
//
// Project: zwirbelstein
// am 8.2.2019 umbenannt in Friedbeim Yondala@SilberLand
//=========================================================================

// diverse Compilerpruefungen einschalten

#pragma strong_types

//Gebiet angeben

#define GEBIET "friedheim"

//uebergeordnete Definitionen laden

#include "../def.h"



#ifndef DORF
#define DORF  ROOM "dorf/"
#endif

#ifndef BURG
#define BURG  ROOM "burg/"
#endif

#ifndef WEGE
#define WEGE  ROOM "wege/"
#endif

#ifndef KELLER
#define KELLER  ROOM "keller/"
#endif

#ifndef WIESE
#define WIESE  ROOM "fallobstwiese/"
#endif



