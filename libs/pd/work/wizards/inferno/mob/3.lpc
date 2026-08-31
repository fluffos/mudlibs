#include <std.h>
inherit MONSTER;

void create() {
 string name, long, short, body, race, sex;
 int level, agr;
 ::create();
   switch(random(5)) {
     case 1:
     default:
       name = "troll";
       short = "a wicked troll";
       long = "A
       level = 20;
       body = "human";
       race = "orc";
       agr = 16;
   }
   set_name(name);
  if (sex && sex != "")
   set_gender(sex);
  else {
   if (random(10) >= 5)
     set_gender("female");
   else
     set_gender("male");
  }
   set_long(long);
   set_level(level);
   set_body_type(body);
   set_race(race);
   set("aggressive", agr);
   set_short(short);
}
