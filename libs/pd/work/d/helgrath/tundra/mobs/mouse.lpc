#include <std.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("field mouse");
   set_short("field mouse");
   set_id(({"monster", "mouse", "field mouse"}));
   set_long("A small harmless mouse that wouldnt hurt a soul.");
   set_level(17+random(8));
   set("aggressive", 10+random(5));
   if(random(2)) set_gender("male"); else set_gender("female");
   set_race("field mouse");
   set_heart_beat(1);
   set_class("fighter");
   set_subclass("warrior");
   set_body_type("ferrel");
   set_emotes(2,({ "The mouse squeaks in fear and runs off!", "There is something scurring about in the underbrush." }),0);
}
