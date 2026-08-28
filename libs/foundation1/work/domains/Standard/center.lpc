/* Beek's first contribution to IdeaExchange.
 *
 * Started just after midnight, October 1st, 1994, when IdeaExchange was
 * approximately 3 hours old.
 *
 * Initially created to be the central meeting point for the IdeaExchange,
 * and so the original admins had somewhere else to stand other than on the
 * Nightmare mudlib backbone.  Designed after a similar room on Distortion,
 * a now defunct MUD created by me.
 */

#include <std.h>

inherit ROOM;

create() {
    ::create();
    set_short("Pool Room");
    set_long("You find yourself standing in a large cavern, lit softly by \
glowing lichen which cover a significant portion of the walls.  The air \
is damp and moist, but warm, which gives it a comfortable feel.  The floor \
is somewhat smooth here, and water seeps out of the walls and collects in \
shallow basins in the floor, forming the pools.  A sense of magic floods \
over you as you look at them.");
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_items( ([
      "pool" : "Which pool do you want to look at?",
      "pools" : "The pools average about 5 feet in diameter.  Several of them lie here and  there, almost covering the floor of the large cavern.",
      "basins" : "The basins are filled with water, forming several pools.",
      "walls" : "Water slowly seeps out of the walls, and trickles down to the floor.",
      "water" : "Water slowly seeps out of the walls, and trickles down to the floor.",
    ]) );
    call_out("make_pools",2);
}

void make_pools(){
    int i;
    mixed *pools = get_dir("/domains/Standard/pools/");
    for (i=0; i < sizeof(pools); i++) {
        new("/domains/Standard/pools/"+pools[i])->move(this_object());
    }
}
