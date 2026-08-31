#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Mage Tower");
    set_long("The stairway in the middle of the tower seems to spiral up and down "
      "endlessly.  There is only the occasional passageway to the current floor just "
      "south of here.  A mage hurries by, clutching a few books to his chest, muttering "
      "to himself.  A swirling object at the top of the stairs sheds light on the stairwell.");
    set_exits( ([ "up" : ROOMS "mtower40",
                  "down" : ROOMS "mtower20",
                  "south" : ROOMS "mtower31"
     ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "Crackling from an unseen fire.");
    set_items(([
        ({"stairway", "stairwell"}) : "The solid black stairs shine slightly in the light, but are not slick to the touch.",
        ({"object", "swirling object"}) : "It looks like some of the portals that you've seen mages create, except much bigger.",
        "mage" : "The mage ignores you completely, intent on the task at hand.",
        "passageway" : "The passageway leads off of the stairs onto the current floor."
    ]));
    add_pre_exit_function("up", "do_up");
    add_pre_exit_function("south", "do_south");
}

int do_up() {
  if(!wizardp(this_player())) {
    write("A mage hurries out and tells you that you aren't allowed up there.");
    say("A mage comes out and tells "+this_player()->query_cap_name()+" that they aren't allowed to go up.");
    return 0;
  }
  return 1;
}

int do_south() {
  if(!wizardp(this_player())) {
    write("You think twice about disturbing such powerful mages.");
    say(this_player()->query_cap_name()+" starts to head south, but thinks better of it.");
    return 0;
  }
  return 1;
}
