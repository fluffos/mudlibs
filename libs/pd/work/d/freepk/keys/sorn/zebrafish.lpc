#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("zebrafish");
   set_short("zebrafish");
   set_long("The small black fish has white vertical stripes across "
	"it's body. The fish swims in and out of the seaweed.");
   set_level(15);
   set_race("fish");
   set_body_type("fish");
   set_gender("male");
}

int die(object ob) {
   say("The zebrafish drops %^BOLD%^%^RED%^dead%^RESET%^ before you.",
	this_object());
   new("/d/freepk/keys/sorn/fish3")->move(environment(this_object()));
   this_object()->remove();
   return 1;
}
