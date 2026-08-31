#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("toad");
   set_id( ({ "toad", "horned toad" }) );
   set_short("Horned Toad");
   set("aggressive", 3+random(3));
   set_level(3);
   set_long("This spikey toad sits on it's lilypad, it's eyes "
           "scanning for any unsuspecting insects.");
   set_body_type("quadrupe");
   set("race", "frog");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
}
