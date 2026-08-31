#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "brown deer", "white deer", "black deer",
           "giant deer", "huge deer", "arctic deer",
           "forest deer", "forbidden deer", "devil deer",
           "baby deer", "baby brown deer", "baby white deer",
           "baby black deer", "baby arctic deer"});

 i = random(sizeof(name));
   set_name("deer");
   set_short(name[i]);
   set_level(i+37);
   set("aggressive", (i+25) );
   set_race("deer");
   set_body_type("deer");
   set_gender("male");
   set_id(({ "deer", name[i] }));
   set_long("This deer is one of the many mystical deer's "
"of the forbidden forest.");
}
