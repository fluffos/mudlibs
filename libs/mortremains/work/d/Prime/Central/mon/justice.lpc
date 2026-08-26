// justice.c
// The justice of the peace of Footown. 
// Nominally performs marriages, although the marriage code is in the
// courthouse and not in the monster.

#include "central.h"
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    set("short", "The Justice of the Peace of "+CITY_NAME);
    set("long", wrap("The Justice can perform marriages "+
	"for you. Type \"help marriage\" for more details."));
    set ("id", ({ "justice", "judge" }) ) ;
    set ("name", "justice") ;
    set_living_name("justice") ;
set("prevent_summon", 1);
    set_name("Judge Judy");
    enable_commands() ;
    set ("no_attack", 1) ;
    set("gender", "female") ;
    set ("inquiry", ([
      "marriage" : "If you type \"help marriage\", I'll tell you all about it.",
      "marriages" : "Typing \"help marriage\" will give you all the details.",
      "guard" : "He's a nice man, and very persistant."
    ]) ) ;
    set_level(2);
}
