#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("The East Chamber of Life");
    set_long("%^BOLD%^%^WHITE%^This entire room is crafted of some rare white metal. Mithril "
"%^BOLD%^%^WHITE%^%^BOLD%^%^YELLOW%^symbols%^BOLD%^%^WHITE%^ and %^BOLD%^%^YELLOW%^emblems%^BOLD%^%^WHITE%^ have been crafted into the wall. Tall, "
"%^BOLD%^%^WHITE%^lit candles stand about four feet tall and half a foot wide "
"%^BOLD%^%^WHITE%^around %^BOLD%^%^YELLOW%^a single altar%^BOLD%^%^WHITE%^. The altar is carved completely of "
"%^BOLD%^%^WHITE%^%^BOLD%^%^YELLOW%^platinum%^BOLD%^%^WHITE%^ with a white-bound book resting in the center of it.");
    set_properties(([ "no attack" : 1, "no magic" : 1, "no bump" : 1,
        "no steal" : 1, "no teleport" : 1, "indoors" : 1, "light" : 2 ]));
    set_items(([
        "book"   : "The fabled and long sought after book of life.",
        "altar"  : "An altar to life. All souls pass through the eteral form of
this "
        "altar on their way to the heavens.",
        "symbols": "Various symbols resembling life and paradise.",
        "metal"  : "You know not the metal's name."
      ]));
    set_exits(([ "west" : "/wizards/inferno/angel/main" ]));
}

int pray() {
    if (this_player()->query_race() != "archangel") return 0;
    if (present("halo", this_player())) return 0;
    new("/wizards/inferno/angel/halo")->move(this_player());
    write("A halo winks into existance.");
    say(this_player()->query_cap_name()+" prays to a higher power.", this_player());
    this_player()->force_me("wear halo");
    return 1;
}

void init() {
    ::init();
    add_action("pray", "pray");
}
