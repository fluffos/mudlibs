
#include <std.h>
#include <saahr.h>

inherit VAULT;

void create() {
  ::create();
  set_properties(([
    "light":2,
    "indoors":1,
    "town":1
  ]));
  set_short("inside a house");
  set_long(
    "The inside of this house is cool and cozy. A window in one wall "
    "gives a view of the willow tree outside, while across from it a "
    "four-poster bed stands against the wall. In a back corner, a very "
    "dainty-looking cooking stove sits unattended next to a closed cupboard."
  );
  set_items(([
    "window" : "It looks out directly at the willow tree.",
    "bed" : "The bed has a big fluffy comforter, and an opaque curtain "
      "hangs open from the top of the bedposts.",
    "stove" : "The stove is very small, just big enough to cook for one.",
    "cupboard" : "It is lacquered a soft green color, and latched against "
      "possible vermin.",
  ]));
  set_exits(([
    "out":VPROOMS"town14_9"
  ]));
  load_object(query_exit("out"));
}

void reset() {
  ::reset();
  if (!present("nymph"))
    new(MOBS"nymph")->move(this_object());
}
