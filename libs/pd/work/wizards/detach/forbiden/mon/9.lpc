#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "brown wolverine", "white wolverine", "black wolverine",
           "giant wolverine", "huge wolverine", "wolverine",
           "forbidden wolverine", "forest wolverine", "devil wolverine"});

 i = random(sizeof(name));
   set_name("wolverine");
   set_short(name[i]);
   set_level(i+37);
   set("aggressive", (i+25) );
   set_race("wolverine");
   set_body_type("wolverine");
   set_gender("male");
   set_id(({ "wolverine", name[i] }));
   set_long("This wolverine is one of the many mystical wolverine's "
"of the forbidden forest.");
}
