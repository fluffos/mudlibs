#include <std.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("%^RESET%^%^WHITE%^White lynx%^RESET%^%^RED%^");
   set_short("%^RESET%^%^WHITE%^White lynx%^RESET%^%^RED%^");
   set_id(({"monster", "lynx", "white lynx"}));
   set_long("Not much is known about this reclusive animal, although it can be
very fierce when protecting its home.");
   set_level(25+random(6));
   set("aggressive", 15+random(5));
   if(random(2)) set_gender("male"); else set_gender("female");
   set_race("lynx");
   set_heart_beat(1);
   set_class("fighter");
   set_subclass("warrior");
   set_body_type("feline");
}

