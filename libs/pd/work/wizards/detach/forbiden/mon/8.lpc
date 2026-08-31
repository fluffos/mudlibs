#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "brown cougar", "white cougar", "black cougar",
           "giant cougar", "huge cougar", "arctic cougar",
           "forbidden cougar", "forest cougar", "devil cougar",
           "baby cougar", "baby brown cougar", "baby White cougar",
           "baby black cougar", "baby arctic cougar"});

 i = random(sizeof(name));
   set_name("cougar");
   set_short(name[i]);
   set_level(i+37);
   set("aggressive", (i+25) );
   set_race("cougar");
   set_body_type("cougar");
   set_gender("male");
   set_id(({ "cougar", name[i] }));
   set_long("This cougar is one of the many mystical cougar's "
"of the forbidden forest.");
}
