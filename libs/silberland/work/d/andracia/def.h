//=========================================================================
//
// File:    def.h
// Created by Yondala@SilberLand
// 
// Project: Andracia
// 
//=========================================================================

// diverse Compilerpruefungen einschalten
#pragma strong_types
#include "../def.h"

#ifndef _ANDRACIA_H_
#define _ANDRACIA_H_

#ifndef REGION 
#define REGION "andracia"
#endif

#ifndef BS
#define BS(x) break_string(x, 78)
#endif


//Fuer schoenere Zeilenumbrueche

#ifndef bswrite
#define bswrite(x) write(break_string(x,78))
#endif

#define BS_P_INT_LONG(x) SetProp( P_INT_LONG, break_string(x, 78))

//SetProp( BS_P_INT_LONG,"Langbeschreibung" );

//  SetProp( P_INT_LONG, break_string("Langbeschreibung",78) );
//  SetProp( P_INT_LONG, "Langbeschreibung");

//#define BS_P_INT_SHORT P_INT_SHORT, break_string (x, 78)
/*
*/

/*
#define TI this_interactive()
#define TP this_player()
#define PL this_player()
#define TPN this_player()->name()
#define CAP_TPN capitalize(this_player()->name())
#define TO this_object()
*/


//Definiere Gebietsabkuerzungen

#define KREUZUNG_02 "/d/andracia/yondala/kreuzungen/kreuzung_02"
#define KREUZUNG_03 "/d/andracia/yondala/kreuzungen/kreuzung_03"
#define KREUZUNG_04 "/d/andracia/yondala/kreuzungen/kreuzung_04"
#define KREUZUNG_05 "/d/andracia/yondala/kreuzungen/kreuzung_05"
#define KREUZUNG_06 "/d/andracia/yondala/kreuzungen/kreuzung_06"


#define CAN_ROOM "/d/andracia/yondala/wasser/caniba/room/"
#define CAN_NPC "/d/andracia/yondala/wasser/caniba/npc/"
#define CAN_OBJ "/d/andracia/yondala/wasser/caniba/obj/"
#define CAN_ARMOUR "/d/andracia/yondala/wasser/caniba/armour/"
#define CAN_WEAPON "/d/andracia/yondala/wasser/caniba/weapon/"

#define PIR_ROOM "/d/andracia/yondala/wasser/pirateninsel/room/"
#define PIR_NPC "/d/andracia/yondala/wasser/pirateninsel/npc/"
#define PIR_OBJ "/d/andracia/yondala/wasser/pirateninsel/obj/"
#define PIR_ARMOUR "/d/andracia/yondala/wasser/pirateninsel/armour/"
#define PIR_WEAPON "/d/andracia/yondala/wasser/pirateninsel/weapon/"


#define GIER_ROOM "/d/andracia/yondala/gebirge/gierlingshoehle/room/"
#define GIER_NPC "/d/andracia/yondala/gebirge/gierlingshoehle/npc/"
#define GIER_OBJ "/d/andracia/yondala/gebirge/gierlingshoehle/obj/"
#define GIER_WEAPON "/d/andracia/yondala/gebirge/gierlingshoehle/weapon/"
#define GIER_ARMOUR "/d/andracia/yondala/gebirge/gierlingshoehle/armour/"

#define PASS_ROOM "/d/andracia/yondala/gebirge/gebirgspass/room/"
#define PASS_NPC "/d/andracia/yondala/gebirge/gebirgspass/npc/"
#define PASS_OBJ "/d/andracia/yondala/gebirge/gebirgspass/obj/"
#define PASS_WEAPON "/d/andracia/yondala/gebirge/gebirgspass/weapon/"
#define PASS_ARMOUR "/d/andracia/yondala/gebirge/gebirgspass/armour/"

#define HOEHLEN_ROOM "/d/andracia/yondala/gebirge/hoehlen/room/"
#define HOEHLEN_NPC "/d/andracia/yondala/gebirge/hoehlen/npc/"
#define HOEHLEN_OBJ "/d/andracia/yondala/gebirge/hoehlen/obj/"
#define HOEHLEN_WEAPON "/d/andracia/yondala/gebirge/hoehlen/weapon/"
#define HOEHLEN_ARMOUR "/d/andracia/yondala/gebirge/hoehlen/armour/"

#define THUM_ROOM "/d/andracia/yondala/gebirge/thumfels/room/"
#define THUM_NPC "/d/andracia/yondala/gebirge/thumfels/npc/"
#define THUM_OBJ "/d/andracia/yondala/gebirge/thumfels/obj/"
#define THUM_WEAPON "/d/andracia/yondala/gebirge/thumfels/weapon/"
#define THUM_ARMOUR "/d/andracia/yondala/gebirge/thumfels/armour/"

#define LABY_ROOM "/d/andracia/yondala/gebirge/labyrinth/room/"
#define LABY_NPC "/d/andracia/yondala/gebirge/labyrinth/npc/"
#define LABY_OBJ "/d/andracia/yondala/gebirge/labyrinth/obj/"
#define LABY_ARMOUR "/d/andracia/yondala/gebirge/labyrinth/armour/"
#define LABY_WEAPON "/d/andracia/yondala/gebirge/labyrinth/weapon/"
#define LABY_LOG "/d/andracia/yondala/gebirge/labyrinth/log/"

#define NEBEL_ROOM "/d/andracia/yondala/nebelwaelder/nebel/room/"
#define NEBEL_NPC "/d/andracia/yondala/nebelwaelder/nebel/npc/"
#define NEBEL_OBJ "/d/andracia/yondala/nebelwaelder/nebel/obj/"
#define NEBEL_ARMOUR "/d/andracia/yondala/nebelwaelder/nebel/armour/"
#define NEBEL_WEAPON "/d/andracia/yondala/nebelwaelder/nebel/weapon/"

#define POESIE_ROOM "/d/andracia/yondala/nebelwaelder/poesie/room/"
#define POESIE_NPC "/d/andracia/yondala/nebelwaelder/poesie/npc/"
#define POESIE_OBJ "/d/andracia/yondala/nebelwaelder/poesie/obj/"
#define POESIE_ARMOUR "/d/andracia/yondala/nebelwaelder/poesie/armour/"
#define POESIE_WEAPON "/d/andracia/yondala/nebelwaelder/poesie/weapon/"

#endif