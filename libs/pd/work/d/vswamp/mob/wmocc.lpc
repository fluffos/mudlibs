#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("water moccasin");
   set_id( ({ "snake", "water moccasin", "moccasin" }) );
   set_short("Water Moccasin");
   set("aggressive", 5+random(4));
   set_level(5);
   set_long("The water moccasin hisses and tries to avoid "
           "being stepped on by slithering through the water.");
   set_body_type("snake");
   set("race", "snake");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
}
