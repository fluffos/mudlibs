#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("A Purgatory Skeleton Guard");
   set_short("A Purgatory Skeleton Guard");
   set_id(({"skeleton", "monster", "guard"}));
   set_long("Risen from the grave, this skeleton is forced by Death to guard his city.");
   set_level(75);
   set("aggressive", 75);
   set("magic defense", 350);
   set_gender("dead");
   set_race("skeleton");
   set_heart_beat(1);
   set_body_type("human");
   set_emotes(2,({ "The clunk of bones can be heard as the guard makes his patrol." }),0);
}

void catch_tell(string str) {
    if(str)
      this_object()->force_me("sacrifice corpse");
}
