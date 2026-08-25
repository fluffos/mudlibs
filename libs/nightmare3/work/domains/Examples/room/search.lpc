#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_properties(([ "light": 3 ]));
    set_short("an open field in the woods");
    set_long(
      "In the middle of an open field found packed into a dense wood "
      "sits a small, uninhabited shack.  Clearly suffering "
      "from years of neglect, the shack appears to be rotting into "
      "the high brush of the field which surrounds it.  A great "
      "forest walls itself around this tiny field."
    );
    set_listen("default", "Spooky sounds from the surrounding wood echo "
      "across the field.");
    set_items( ([
      "field" : "Brush rising to five feet fills a small cavity "
        "in the great woods which surround it.  A small shack sits "
        "at its center.",
      "shack" : "It looks like it has seen better days.",
      ({ "forest", "woods" }) : "A great forest which has meant the "
        "end for many adventurers.",
      "brush" : "It is so thick that you could lose yourself in it!"
    ]));
    set_exits(([ "south": "/domains/Examples/room/simple_search",
      "north" : "/domains/Examples/room/simple" ]));
}

void reset() {
    ::reset();
    set_search("brush", (: "search_brush" :));
}

int search_brush(string str) {
    object ob;

    if(random(5) < 2) {
        write("You find nothing odd.");
        return 1;
    }
    else ob = new(OB_TORCH);
    write("You find a torch in the brush!");
    say((string)this_player()->query_cap_name() + " finds a torch in " +
      "the brush!");
    if((int)ob->move(this_player())) {
        write("You fumble the torch as you pick it up!");
        say((string)this_player()->query_cap_name()+" fumbles the torch "+
          "into the brush as "+nominative(this_player())+" picks it up!");
        ob->remove();
        return 1;
    }
    remove_search("brush");
}
