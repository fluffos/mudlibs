#include <std.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("The victor's room.");
 set_long("Gladiators of the past have come here after defeating "
          "their foes.  As the victor of this event, the crowd "
          "chants your name hoping for your return.  The voices of "
          "of the past stir in congratulations of your victory. \n\n"
          "Leave with your head held high knowing those of the past "
          "are pleased with you.");
 set_exits( ([ "out" : "/d/arena/bet" ]) );
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "no teleport" : 1,
                    "night light" : 2 ]) );
}

