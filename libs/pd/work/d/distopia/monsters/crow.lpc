// Hermes' own special stalker
#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("crow");
   set_id(({ "crow" }));
   set_short("A crow");
   set_level(400);
   set_long("This large black crow stares at you with it's beady little "
            "eyes as you look him over.");
   set_body_type("bird");
   set("race", "crow");
   set_gender("male");
}

int dest() { 
 this_object()->force_me("lick hermes");
 this_object()->force_me("say nevermore.");
 return 1;
}

void heart_beat() {
  if(find_player("hermes")) {
    if(environment(this_object()) != environment(find_player("hermes"))) {
      say(this_object()->query_cap_name()+" continues to stalk Hermes.");
      this_object()->move(environment(find_player("hermes")));
      say(this_object()->query_cap_name()+" flies in, stalking Hermes.");
    }
    if(random(100) < 3)
      this_object()->force_me("say nevermore.");
  }
  ::heart_beat();
}

int die() { return 1; }

int is_invincible() { return 1; }
