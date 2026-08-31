
#include <std.h>
#include <saahr.h>

inherit VAULT;

string check_sound();

void create() {
  ::create();
  set_properties(([
    "light":2,
    "indoors":1,
    "town":1
  ]));
  set_short("inside a house");
  set_long(
    "The house extends a lot "
    "further than it seems from the outside, and a lot "
    "of the extra space is used to display lavish art "
    "pieces, mainly paintings. A few lamps sit on small "
    "tables as well, sparkling faintly. A long, canopy "
    "style bed sits against the east wall. Curiously, "
    "there is no visible stove or even food storage."
  );
  set_items(([
    "house" : "A rather large, one-room house.",
    ({"art", "art pieces", "pieces", "paintings"}) :
      "Mostly nature scenes of trees and rivers.",
    "lamps" : "Each lamp is adorned with a few small gems and gives off "
      "a lot of light when lit.",
    "bed" : "This long bed has a soft, heavy blanket covering it. The four "
      "posts extend nearly to the ceiling, and some fabric is draped around "
      "three of the posts.",
  ]));
  set_exits(([
    "out":VPROOMS"town10_7"
  ]));
  set_sound("default", (: check_sound :) );
  load_object(query_exit("out"));
}

void reset() {
  ::reset();
  if (!present("nymph"))
    new(MOBS"nymph-rich")->move(this_object());
}

string check_sound() {
  object ny = present("nymph");
  if (!ny)
    return "It is very quiet in here.";
  else if (present(NECKLACE_ID, ny))
    return "A contended humming fills the house.";
  else
    return "Sobbing sounds come from the lone occupant.";
}

