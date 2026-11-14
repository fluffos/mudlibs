/*
 * defines fuer Bauernhof
 *
 * Ronja@SL
 *
 */

#pragma strong_types

#define REGION "ebene"
#define WIZARD "rohkopfrex"
#define APATH "/d/" REGION "/" WIZARD "/bauernhof/"
#define ALOG APATH "log/"
#define ROOM APATH "room/"
#define STRASSE APATH "strasse/"
#define NPC APATH "npc/"
#define OBJ APATH "obj/"
#define ARMOUR APATH "armour/"
#define WEAPON APATH "weapon/"
#define AMASTER APATH "master/master"

#define OSTERHASE "/d/huegelland/feyaria/osterhase/oh.h"

#include <defines.h>
#include <moredef.h>

#define TELLPLAYER(x) tell_object(TP,x)
#define TELLOTHERS(x) tell_room(ENV(TP),x,({TP}))
#define WRITELOG(x) write_file(ALOG "bauernhof.log",ctime()+":"+x+".\n")
#define TPUID capitalize(getuid(this_player()))
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define DB(x) if(find_player("ronja")) tell_object(find_player("ronja"), "\nXXX "+x+"\n\n")

#define ANSCHLUSS "/d/ebene/Silberwald/room/room_g13"
#define ANSCHLUSS_RIDU "/d/ebene/carador/ridu/room/koppel"
