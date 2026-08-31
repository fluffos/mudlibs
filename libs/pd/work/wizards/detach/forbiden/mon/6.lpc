#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "brown snake", "white snake", "black snake",
           "giant snake", "huge snake", "blue snake",
           "yellow snake", "green snake", "red snake",
           "baby snake", "baby brown snake", "baby white snake",
           "baby black snake", "baby blue snake"});

 i = random(sizeof(name));
   set_name("snake");
   set_short(name[i]);
   set_level(i+38);
   set("aggressive", (i+25) );
   set_race("snake");
   set_body_type("snake");
   set_gender("male");
   set_id(({ "snake", name[i] }));
   set_long("This Snake is one of the many mystical snake's "
"of the forbidden forest.");
}

