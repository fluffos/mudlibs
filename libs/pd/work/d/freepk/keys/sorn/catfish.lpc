#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("catfish");
   set_short("a catfish");
   set_long("This catfish is ready to fight. It has a fishing hook "
	"stuck in it's lip.");
   set_level(35);
   set_race("fish");
   set_body_type("fish");
   set_gender("female");
}

int die(object ob) {
   say("The catfish drops %^BOLD%^%^RED%^dead%^RESET%^ before you.",
	this_object());
   new("/d/freepk/keys/sorn/fish2")->move(environment(this_object()));
   this_object()->remove();
   return 1;
}
