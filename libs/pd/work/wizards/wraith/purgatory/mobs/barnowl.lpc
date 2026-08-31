#include <std.h>
#include <purgatory.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("Barn owl");
   set_short("Barn owl");
   set_id(({"monster", "owl", "barn owl"}));
   set_long("With its eyes always open, the owl keeps a watch for who is going to die next.");
   set_level(25+random(10));
   set("aggressive", 22+random(10));
   if(random(2)) set_gender("male"); else set_gender("female");
   set_race("owl");
   set_heart_beat(1);
   set_class("fighter");
   set_subclass("warrior");
   set_body_type("fowl");
   set_emotes(2,({ "The hooting of an owl calling for another death can be heard high in the trees.", "The owl follows you with unblinking eyes and a swiveling head." }),0);

}
