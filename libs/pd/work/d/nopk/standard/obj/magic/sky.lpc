#include <std.h>
#include <locations.h>
inherit ROOM;
int didrooms;
 
void init() {
  ::init();
  add_action("fly","fly");
  add_action("dismount","dismount");
  add_action("drop", "drop");
  if(this_player()->query_mounting()) return;
  if(didrooms == 0)
    do_exits();
  didrooms = 1;
}
void do_exits() {
  int skill;
  didrooms = 1;
  skill = this_player()->query_skill("flying");
  // Notice that call_out times are half the skill req..  this can be changed if need be.  -Nightshade
  if(skill >= 100)
      call_out("add_exit", 100, "/wizards/powerman/room/patha", "dunsinane");
  if(skill >= 85)
      call_out("add_exit", 84, "/d/freepk/merkkerri/jungle/merkkirri/mjungle1", "merkkirri");
  if(skill >= 70)
      call_out("add_exit", 70, "/d/helgrath/rooms/wilndursquare", "helgrath");
  if(skill >= 60)
      call_out("add_exit", 60, "/d/roston/rooms/roston", "roston");
  if(skill >= 30)
      call_out("add_exit", 30, "/d/lodos/square", "lodos");
  if(skill >= 45)
      call_out("add_exit", 44, "/d/shadow/rooms/tene10", "tenebrae");
  if(skill >= 25)
      call_out("add_exit", 24, "/d/nopk/arlon/room/square", "arlon");
  if(skill >= 20)
      call_out("add_exit", 20, "/d/nopk/elven_path/rooms/elven_path_0", "elvenvillage");
  if (this_player()->query_race()== "archangel")
      add_exit("/wizards/inferno/angel/main", "hall");
  else if (this_player()->query_race()== "demon")
      add_exit("/d/freepk/merkkerri/demonquest/dquest115", "hall");
  else
      add_exit("/d/nopk/tirun/dragon_hall", "hall");
  add_pre_exit_function("hall", "go_hall");
}
void add_exit(string path, string dir) {
  message("info", "You see "+capitalize(dir)+" come into view.", all_inventory(this_object()));
  ::add_exit(path, dir);
}
void create() {
::create();
   didrooms = 0;
   set_name("the sky");
   set_properties(([
        "light" : 2,
        "night light" : 2,
        "no teleport" : 1
        ]));
    set_exits(([ "tirun" : SQUARE_LOC ]));
    set_short("Flying in the sky.");
    set_long(
    "%^CYAN%^The sun shines high above this place. Lazy white clouds float "
    "%^CYAN%^by on their journey to wherever it is that clouds go. Far "
    "%^CYAN%^below, a town can be seen, though it is much to far to tell "
    "%^CYAN%^what town.%^RESET%^"
    );
    set_night_long(
    "%^BOLD%^%^BLUE%^The sister moons loom large in the sky. Millions of "
    "%^BOLD%^%^BLUE%^stars can be seen this high above the world. Far below, "
    "%^BOLD%^%^BLUE%^the lights of a town can be seen, though it is much to "
    "%^BOLD%^%^BLUE%^far to tell what town.%^RESET%^"
    );
    set_smell("default", "The air smells of a fresh spring rain!.");
    set_listen("default", "The wind whistles in your ears.");
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
int go_hall() {
  if(this_player()->query_mounted()) {
    write("You wouldn't dare take someone into your sacred hall!");
    return 0;
  }
  return 1;
}
int drop(string str) {
  call_out("do_clean", 1);
  return 0;
}
/*
void reset() {
  ::reset();
  if(find_call_out("add_exit") != -1)
    return;
  if(sizeof(all_inventory(this_object())) == 0)
    this_object()->remove();
}
*/
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
