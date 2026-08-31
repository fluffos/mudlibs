#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("arowana");
   set_short("an arowana");
   set_long("The arowana swims around in the water, she lives a simple "
	"and happy life. One of these days, the arowana is going to "
	"jump out of this pond and snatch a coconut from that tree "
	"right above the pond...");
   set_level(30);
   set_race("fish");
   set_body_type("fish");
   set_gender("female");
}

int die(object ob) {
   say("The arowana drops %^BOLD%^%^RED%^dead%^RESET%^ before you.",
	this_object());
   new("/d/freepk/keys/sorn/fish1")->move(environment(this_object()));
   this_object()->remove();
   return 1;
}
