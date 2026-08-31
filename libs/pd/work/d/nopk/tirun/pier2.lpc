#include <std.h>
#include <tirun.h>
inherit PIER;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 2);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
    set_short("Tirun Docks");
    set_long(
        "The pier here is long and narrow.  Water can be seen on both sides. "
        "Torches mounted on poles are set at four foot intervals around "
        "the pier. Several benches have been set on both sides of the pier. "
        "The boards of the pier are weathered from long years of use." );
    set_night_long(
        "The pier here is long and narrow.  Water can be seen on both sides. "
        "Torches mounted on poles provide enough light to see anything on "
        "the pier. Several benches have been set on both sides of the pier. ");
      set_smell("default", "Rotting fish offend your nostrils.");
      set_smell("fish", "They smell as if they have been out for days.");
    set_items(
        (["port" : "Ships from all over Carnage dock here to "
            "do business in Tirun.",
          "pier" : "A wooden structure extending over the ocean.",
          "torch" : "It lights up the pier at night.",
          "torches" : "They light up the pier at night."]) );
    set_exits( 
          (["west" : ROOMS "pier1"]) );
}

void reset() {
  ::reset();
    if(present("stick")) return;
    new(OBJ "fishing_pole")->move(this_object());
}
