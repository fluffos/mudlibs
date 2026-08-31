#include <std.h>
#include <tirun.h>
inherit MONSTER;
int oi = 0;
int test_heart;
void create()
{
 ::create();
 set_name("town guard");
 set_id( ({"patrol guard", "guard", "town guard" }) );
 set_short("A patrol guard");
 set_long("A member of the town guard that patrols the area.");
 set_race("human");
   set_gender("female");
 set_body_type("human");
 set_heart_beat(1);
 set_property("no attack", 1);
 set_patrol(4, ({ "north", "north", "west", "west", "west", "west",
                  "west", "southwest", "south", "south", "south", "south",
                  "south", "east", "east", "east", "east", "east",
                  "east", "northeast", "north", "north" }) );
 new(WEP"bclub")->move(this_object());
 command("wield club");
}
int test_heart() { 
    if(!heart_beat_on) set_heart_beat(heart_beat_on = 1);
 return 1; 
}
