#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest40");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^The General of the Barbarians has commandeered this room as "
"%^ORANGE%^his command post. A sturdy desk sits at the of the room. The "
"%^ORANGE%^small armoury stands to the west to hold the General's "
"%^ORANGE%^weapons.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["west" : ROOMS"guest23"]) );

    set_items( ([
          "desk" : "Many papers are scatters about the desk.",
          "papers" : "These papers outline plans for the assult against the King."
      ]) );


}

void reset() {
 ::reset();
  if (!present("general", this_object()))
    new(MOBS"general" )->move(this_object());
}
