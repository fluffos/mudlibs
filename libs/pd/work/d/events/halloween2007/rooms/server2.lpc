
#include <std.h>
#include <h2k7.h>

inherit VIRTUALSERVER;

void create() {
  ::create();
  set_properties( ([ "light" : 0, "night light" : 0,
    "town":1, "plain":1, "indoors":0 ]) );
  set_short("a dark pumpkin maze");
  set_how_long(3);
  set_mob_cap(3);
  set_listen("Eerie howling sounds float above the fog.");
  set_reset_list( ({
    H2K7MOBS"crow", H2K7MOBS"raven",
    H2K7MOBS"scarecrow", H2K7MOBS"jackolantern",
    H2K7MOBS"scarecrow", H2K7MOBS"jackolantern",
    H2K7MOBS"ghost", H2K7MOBS"ghost",
  }) );
  set_day_sentances( ({
    "Fog covers the ground in a soft blanket.",
    "Pumpkin vines lie on the ground.",
    "A bit of hay has been tracked into the area.",
    "Mounds of loose dirt are scattered around.",
    "A shadow flits across the ground momentarily.",
    "A scarecrow stands sentinel amid the vines."
  }) );
  set_item_list( ([
    "fog" : "A wispy grey fog that obscures the ground.",
    "ground" : "The ground here is a deep black soil for growing pumpkins.",
    "vines" : "Some green, mostly brown, and a few still have pumpkins "
      "growing on them.",
    "pumpkins" : "Large orange squash-like vegetables.",
    "hay" : "A few wisps of hay lie on the ground.",
    ({ "mounds", "dirt" }) : "Places where pumpkins were recently lying.",
    "shadow" : "It is gone, but it seemed to have wings."
  ]) );
}

