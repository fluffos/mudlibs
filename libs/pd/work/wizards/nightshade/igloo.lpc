#include <std.h>

inherit ROOM;

void create() {
  ::create();
  set_name("igloo");
  set_properties( ([ "light" : 2,
                    "no attack" : 1,
                    "no scry" : 1,
                    "no teleport" : 1
                   ]) );
  set_short("%^BOLD%^%^BLUE%^A%^CYAN%^n%^BLUE%^ I%^CYAN%^c%^BLUE%^y %^CYAN%^I%^BLUE%^g%^CYAN%^l%^BLUE%^o%^CYAN%^o%^RESET%^");
  set_long("%^BOLD%^%^CYAN%^The walls of the igloo %^BLUE%^shimmer%^CYAN%^ lightly as light bounces around the room.  The igloo is small, only large enough to comfortably fit two people.  The floor is covered in a %^WHITE%^light fluffy snow%^CYAN%^ and is quite comfortable.  It is quite cold in this igloo.%^RESET%^");
  set_items( ([ "walls" : "%^BOLD%^The walls s%^CYAN%^p%^BLUE%^a%^WHITE%^r%^CYAN%^k%^BLUE%^l%^WHITE%^e gently in the little bit of light that shines through them from outside.%^RESET%^",
                "floor" : "%^BOLD%^The floor is made up of lightly packed snow that is soft to sit or lay on.%^RESET%^" ]) );
    set_exits( ([
/*
                "workroom" : "/wizards/nightshade/workroom",
*/
                "down" : "/d/nopk/tirun/square" ]) );
  set_smell("default", "The frosty air fills your lungs as you breathe in.");
  set_listen("default", "Snow crunches quietly under your weight.");
}

void init() {
  ::init();
  add_action("say_fun", "say");
}

int say_fun(string str) {
  write("As you speak, your breath shows up in the air.");
  say("As "+this_player()->query_cap_name()+" speaks, their breath becomes visible.");
  return 0;
}
