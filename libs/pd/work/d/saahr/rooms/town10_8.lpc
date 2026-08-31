
#include <std.h>
#include <rest.h>
#include <saahr.h>

inherit ROOM;

string feel_grass(string str);

void create() {
  ::create();
  set_properties(([
    "light":2,
    "night light":1,
    "indoors":0,
    "town":1
  ]));
  set_short("a small town");
  set_long(
    "The main paths of the town lead right through a large patch "
    "of flowers here. %^RED%^%^BOLD%^Red%^RESET%^, "
    "%^YELLOW%^yellow%^RESET%^, and %^BOLD%^white%^RESET%^ flowers "
    "cover most of the ground. A rather uniform layer of grass "
    "lies beneath them, creating a place where many of the "
    "townspeople seem to enjoy spending time."
  );
  set_items(([
    ({ "patch", "flowers" }) : "They cover the ground with various colors.",
    "ground" : "The only ground can be seen on the path, everywhere else is "
      "completely covered.",
    "grass" : "Bright %^GREEN%^%^BOLD%^green%^RESET%^, "
      "it looks so inviting you want to touch it.",
  ]));
  set_touch("grass", (: feel_grass :) );
  set_smell("default", "A strong flowery scent.");
  set_exits(([
    "north":VPROOMS"town10_7",
    "east":VPROOMS"town11_8",
    "south":VPROOMS"town10_9",
    "west":VPROOMS"town9_8"
  ]));
}

void reset() {
  int n = random(3)+1;
  ::reset();
  if (!present("nymph "+n)) {
    while (n--) {
      object ob;
      ob = new(MOBS"nymph");
      ob->move(this_object());
      ob->set_rest_type(SIT);
    }
  }
}

string feel_grass(string str) {
  object tp = this_player();
  
  if (sizeof(regexp(tp->query_walking_limbs(), "hoof")))
    return "You slide your hooves through the grass.";

  return "You squish your toes into the grass.";
}

