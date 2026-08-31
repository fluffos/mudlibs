#include <std.h>
inherit MONSTER;
object tp;
void create() {
::create();
set_name("Rob Zombie");
set_short("Rob Zombie");
set_id(({"rob zombie", "rob", "guard"}));
set_long("This is one of the faithful guards of the Darksoul guild.");
set_level(25);
set_gender("male");
set("guild", "darksoul");
set("race", "human");
set_body_type("human");
}

void init() {
 ::init();
if(this_player()->query_guild()!="darksoul"
     && this_player()->is_player()) {
  tp = this_player();
  call_out("member", 1, tp);
  }
}

int member(object tp) {
this_object()->force_me("say Intruder you shall die!");
this_object()->force_me("kill "+tp->query_name());
}
