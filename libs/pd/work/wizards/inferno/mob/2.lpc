#include <std.h>
inherit MONSTER;

void create() {
 string name, long, short, body, race, sex;
 int level, agr;
 ::create();
   switch(random(5)) {
     case 1:
       name = "orc";
       short = "a fighting orc";
       long = "This orc stands ready to die simply for the thrill of "
              "fighting you. It's fists are clenched, it is prepared "
              "to fight.";
       level = 26;
       body = "human";
       race = "orc";
       agr = 15;
       break;
     case 3:
       name = "soldier";
       short = "an orcish soldier";
       long = "The soldier is short and husky. The orc looks deathly "
              "afraid of his own post. He clearly does not want to be "
              "here.";
       sex = "male";
       level = 22;
       body = "human";
       race = "orc";
       agr = 2;
     case 4:
       name = "orc";
       short = "a small orc";
       long = "The orc is so small, it might actually be an enslaved "
              "goblin. The orc has long, sharpened teeth.";
       level = 26;
       body = "human";
       race = "orc";
       agr = 0;
       break;
     default:
       name = "guard";
       short = "an orc guard";
       long = "A cowardly orc stands here only out of fear of those "
              "higher ranks than it.";
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
