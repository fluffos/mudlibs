#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "brown bear", "white bear", "black bear",
           "giant bear", "huge bear", "arctic bear",
           "devil bear", "rabid bear", "old bear",
           "baby bear", "baby brown bear", "baby white bear",
           "baby black bear"});

 i = random(sizeof(name));
   set_name("bear");
   set_short(name[i]);
   set_level(i+35);
   set("aggressive", (i+25) );
   set_race("bear");
   set_body_type("canine");
   set_gender("male");
   set_id(({ "bear", name[i] }));
   set_long("This bear is one of the many mystical bears "
"of the forbidden forest.");
}
