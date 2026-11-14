//=========================================================================
//
// File:    def.h
// Created by Ronja@SL
//
// Project: Testgebiet
//
//=========================================================================

// diverse Compilerpruefungen einschalten

#pragma strong_types

//Magiername angeben

#define MAGIERNAME "beispiele"

//uebergeordnete Definitionen laden

#include "../def.h"

#define DBR(x) if (find_player("ronja")) tell_object(find_player("ronja"),("DBR: "+x+"\n"))



