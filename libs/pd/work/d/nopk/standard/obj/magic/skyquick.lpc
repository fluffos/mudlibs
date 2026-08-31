#include <std.h>
inherit ROOM;
 
void create() {
::create();
   set_name("the sky");
   set_properties(([
        "light" : 2,
        "night light" : 2,
        "no teleport" : 1,
        "no attack" : 1,
        ]));
    set_short("Flying in the sky.");
    set_long(
    "%^CYAN%^The sun shines high above this place. Lazy white clouds float "
    "%^CYAN%^by on their journey to wherever it is that clouds go. Far "
    "%^CYAN%^below, a town can be seen, though it is much too far to tell "
    "%^CYAN%^what town.%^RESET%^"
    );
    set_night_long(
    "%^BOLD%^%^BLUE%^The sister moons loom large in the sky. Millions of "
    "%^BOLD%^%^BLUE%^stars can be seen this high above the world. Far below, "
    "%^BOLD%^%^BLUE%^the lights of a town can be seen, though it is much too "
    "%^BOLD%^%^BLUE%^far to tell what town.%^RESET%^"
    );
    set_smell("default", "The air smells of a fresh spring rain!.");
    set_listen("default", "The wind whistles in your ears.");
}
void init() {
  ::init();
  add_action("fly","fly");
  add_action("dismount","dismount");
  add_action("drop", "drop");
}
int fly(string str) {
  if(str)
    if(str == "list")
      return 0;
  write("You are already flying!");
  return 1;
}
int dismount(string str) {
  if(this_player()->query_mounting()) {
    write("And fall to your death?");
    return 1;
  }
  return 0;
}
int drop(string str) {
  call_out("do_clean", 1);
  return 0;
}
void do_clean() {
  object *stuff;
  int i;
  stuff = all_inventory(this_object());
  i = sizeof(stuff);
  while(i--) {
    if(!living(stuff[i])) {
      message("info", "The "+stuff[i]->query_name()+" falls through the sky to the ground below.", all_inventory(this_object()));
      stuff[i]->remove();
      if(stuff[i])
        destroy(stuff[i]);
    }
  }
}
