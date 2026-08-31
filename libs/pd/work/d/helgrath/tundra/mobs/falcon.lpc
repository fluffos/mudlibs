#include <std.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("Falcon");
   set_short("Falcon");
   set_id(({"monster", "falcon", "Falcon"}));
   set_long("Falcons, such as this one, are some of the more beautiful and graceful creatures in nature.");
   set_level(25+random(6));
   set("aggressive", 15+random(5));
   if(random(2)) set_gender("male"); else set_gender("female");
   set_race("falcon");
   set_heart_beat(1);
   set_class("fighter");
   set_subclass("warrior");
   set_body_type("fowl");
   set_emotes(2,({ "The falcon swoops down on an unsuspecting mouse.", "A call of a falcon can be heard overhead." }),0);

}
