
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
    "This house is almost completely bare. The flat walls have "
    "no adornments and only a single window in the front. A shelf "
    "on one wall holds some dried fruits and a cooking pot. In a "
    "back corner sits a cot with a blanket."
  );
  set_items(([
    "walls" : "Just walls.",
    "window" : "It faces south to let the sun in during the day.",
    "shelf" : "A long plank with smaller pieces of wood to hold it "
      "off the ground.",
    ({ "fruits", "fruit", "dried fruits", "dried fruit" }) :
      "Flat slices of apples and a bright yellow fruit that are dried "
      "to last a long time.",
    "pot" : "A black pot. It is empty.",
    "corner" : "There is a cot in the corner.",
    "cot" : "A rather stiff looking cot with a blanket on it.",
    "blanket" : "Dark red, made of wool, and surely quite warm.",
  ]));
  set_exits(([
    "out":VPROOMS"town11_8"
  ]));
  load_object(query_exit("out"));
}

void reset() {
  ::reset();
  if (!present("satyr"))
    new(MOBS"satyr")->move(this_object());
}

