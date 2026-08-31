#include <std.h>
inherit OBJECT;

void find_locket();

void create() {
 ::create();
   set_name("seaweed");
   set_short("%^BOLD%^%^GREEN%^se%^CYAN%^awe%^GREEN%^ed%^RESET%^");
   set_long("Seaweed grows all over the bottom of the pond. If "
	"something were dropped in, it would most likely become "
	"tangled up in the seaweed.");
   set_prevent_get("There is too much for you to try and take.");
   set_id(({ "seaweed" }));
   set_search("default", (: find_locket :) );
}

void find_locket() {
   write("You find a silver locket in the seaweed!");
   say(this_player()->query_cap_name()+" finds something in the "
        "seaweed.", this_player());
   new("/d/freepk/keys/sorn/locket")->move(this_player());
   remove_search("default");
}

void reset() {
  ::reset();
  set_search("default", (: find_locket :) );
}
