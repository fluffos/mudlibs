#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "grunt", "white grunt", "fat grunt",
           "giant grunt","huge grunt", "arctic grunt",
           "forbidden grunt", "young grunt", "devil grunt",
           "baby grunt", "brown grunt", "baby white grunt",
           "black grunt", "baby black grunt"});

 i = random(sizeof(name));
   set_name("grunt");
   set_short(name[i]);
   set_level(i+42);
   set("aggressive", (i+25) );
   set_race("grunt");
   set_body_type("feline");
   set_gender("male");
   set_id(({ "grunt", name[i] }));
   set_long("This Grunt lives in the forbidden forest, he travels "
"from tree to tree.");
}
