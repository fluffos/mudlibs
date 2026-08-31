#include <std.h>
inherit MONSTER;

void create() {
 string name, long, short, body, race, sex;
 int level, agr;
 ::create();
   switch(random(7)) {
     case 1:
       name = "snake";
       short = "a red snake";
       long = "The snake is a dark red with not other color on it. Its "
              "eyes are a wicked orange with yellow slits.";
       level = 12;
       body = "snake";
       race = "snake";
       agr = 0;
       break;
     case 2:
       name = "leach";
       short = "a fat leach";
       long = "A little maggot-like leach. Its a blood sucking resident "
              "of the black tower. It looks well fed..";
       level = 14;
       body = "worm";
       race = "leach";
       agr = 7;
       break;
     case 3:
       name = "worm";
       short = "a slimy little worm";
       long = "The slimy little worm squirms around the floor. Its the "
              "biggest worm you have ever seen, about one foot wide.";
       level = 13;
       body = "worm";
       race = "worm";
       agr = 0;
       break;
     case 4:
       name = "beetle";
       short = "a black beetle";
       long = "The black beetle scurys about flicking its wings every "
              "now and again. It has a strong black shell.";
       level = 10 + random(5);
       body = "insctwgd";
       race = "beetle";
       agr = 3;
     case 5:
       name = "beetle";
       short = "a black beetle";
       long = "The black beetle scurys about flicking its wings every "
              "now and again. It has a strong black shell.";
       level = 12 + random(6);
       body = "insctwgd";
       race = "beetle";
       agr = random(7);
       break;
     case 6:
       name = "locust";
       short = "a locust";
       long = "A plague upon wings from the black mouth of Cain.";
       level = 15 + random(5);
       body = "insctwgd";
       race = "locust";
       agr = random(14);
       break;
     default:
       name = "snake";
       short = "a red snake";
       long = "The snake is a dark red with no other color on it. Its "
              "eyes are a wicked orange with yellow slits.";
       level = 10;
       body = "snake";
       race = "snake";
       agr = 4;
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
