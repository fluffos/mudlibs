#ifndef _ridu_def_h
#define _ridu_def_h

#define GEBIET "ridu"
#include "../def.h"
#include "sys/message.h"
#include "sys/grammar.h"
#define RD_HOME "/d/ebene/carador/ridu/"

#if (__HOST_NAME__ != MUDHOST)
// Solange es noch nicht im Spiel ist, findet es hier statt
#define RD_TESTROOMDIR RD_HOME"testroom/"
#define RD_WOLKENSTART RD_TESTROOMDIR"t1"
#define RD_MIDASDIR RD_TESTROOMDIR
#define RD_KOPPEL_EXIT RD_HOME"testaus/b2"
#define RD_PIER_EXIT RD_HOME"testaus/w5"
#else

// Hurra! Es ist eine Quest!
#define RD_QUESTNAME "Der fliegende Silberlaender"

// Im Spiel sind die Sachen dann hier angesiedelt
// Hier beginnt die Wolke
#define RD_WOLKENSTART "/d/ebene/Midas/room/room_c9"

// Ridu fliegt nur in Raeumen, deren Name so anfaengt
#define RD_MIDASDIR "/d/ebene/Midas/room/"

// room/koppel fuehrt nach RD_KOPPEL_EXIT
#define RD_KOPPEL_EXIT "/d/ebene/rohkopfrex/bauernhof/room/wiese1"

// room/pier fuehrt nach RD_PIER_EXIT
#define RD_PIER_EXIT "/d/wasser/woody/fischerdorf/room/weg5"
#endif

// So viele Sekunden muss man warten, bevor man wieder an den Steinen
// oder am Splitter reiben kann
#define RD_MIN_REIBEABSTAND 4

// So viele Sekunden liegen mindestens zwischen zwei magischen Entladungen
#define RD_MIN_ENTLADUNGSABSTAND 60

// Bei jedem Reiben an den Steinen besteht eine Entladungswahrscheinlichkeit
// von 1 : RD_ENTLADUNGSCHANCE
#define RD_ENTLADUNGSCHANGE 3

// Anzahl Sekunden zwischen zwei Aktionen des magicfisch:
#define RD_FISCHMAGICABSTAND 60

// Anzahl Sekunden zwischen zwei Aktionen des magischen Levitationssteins,
// den der Spieler als Belohnung einsacken kann.
#define RD_STEINMAGICABSTAND 90

// So viele Sekunden wartet Ridu, nachdem er das Schiff einen Raum
// weiterbewegt hat, bis er wieder einen Zug macht
// Dies ist auch der Abstand, in dem das Schiff an Hoehe verliert,
// wenn Ridu nicht mehr lebt
#define RD_FLIEGEABSTAND 90

// Hat Ridu sich entschieden, das Schiff einen Raum weiter zu bewegen
// (alle RD_FLIEGEABSTAND Sekunden), so handelt er solange bis der Zug
// abgeschlossen ist, alle RD_AKTIONSGESCHWINDIGKEIT Sekunden
// (d.h. Laufen, Stein reiben, usw.
#define RD_AKTIONSGESCHWINDIGKEIT 15

// Ist man in Theos Raum entscheidet man sich dort offensichtlich zum
// Landen. Der Sinkzyklus ist hierbei niedriger
#define RD_LANDEABSTAND 15

// Bei der Moewenentladung kommt alle RD_MOEWENABSTAND eine neue Moewe
// dazu, maximal werden es RD_MOEWENANZAHL Moewen. Danach verschwinden
// die Moewen wieder.
#define RD_MOEWENABSTAND 20
#define RD_MOEWENANZAHL 9

// Verschiedene Verzeichnisse
#define RD_STDDIR RD_HOME"std/"
#define RD_LIBDIR RD_HOME"lib/"
#define RD_SYSDIR RD_HOME"sys/"
#define RD_EXTROOMDIR RD_HOME"extroom/"
#define RD_TEXTDIR RD_HOME"text/"
#define RD_NPCDIR NPC
#define RD_OBJDIR OBJ
#define RD_ROOMDIR ROOM
#define RD_SAVEDIR RD_HOME"save/"
#define RD_LOGDIR LOG

// Klassen zum Erben bzw. Clonen
#define RD_THING RD_STDDIR"thing"
#define RD_ROOM RD_STDDIR"room"
#define RD_NPC RD_STDDIR"npc"
#define RD_ARMOUR "std/armour"
#define RD_WEAPON "std/weapon"

// Haeufig benutzte Objekte fuer call_other
#define RD_VOID "room/void"
#define RD_TOOLS RD_LIBDIR"tools"
#define RD_MOVER RD_LIBDIR"mover"
#define RD_LOGGER RD_LIBDIR"logger"

// Properties
#define P_RD_RIDU_AREA "ridu_area"
#define P_RD_STOLPER_CHANCE "ridu_stolper_chance"
#define P_RD_RELING_LONG "ridu_reling_long"

#endif

