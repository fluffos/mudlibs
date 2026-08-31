#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "gorilla", "white gorilla", "fat gorilla",
           "giant gorilla","huge gorilla", "arctic gorilla",
           "rabid gorilla", "old gorilla", "young gorilla",
           "baby gorilla", "brown gorilla", "baby white gorilla",
           "black gorilla", "baby black gorilla"});

 i = random(sizeof(name));
   set_name("gorilla");
   set_short(name[i]);
   set_level(i+39);
   set("aggressive", (i+25) );   
   set_race("gorilla");
   set_body_type("human");
   set_gender("male");
   set_id(({ "gorilla", name[i] }));
   set_long("This gorilla lives within the trees of the forbidden "
"forest.");
}
