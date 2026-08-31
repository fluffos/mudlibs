#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
    set_name("the upper level of the western gatehouse");
    set_short("the upper level of the western gatehouse");
    set_long("%^BOLD%^%^WHITE%^The Gatehouse.\n"
      "%^BOLD%^%^BLACK%^This is the control room of the gatehouse, not many people "
      "%^BOLD%^%^BLACK%^make it up here, but those that do usually feel really really "
      "%^BOLD%^%^BLACK%^tired. A large set of controls used to lift the gates stand "
      "%^BOLD%^%^BLACK%^next to a plush looking bed. Small shafts of sunlight drift "
      "%^BOLD%^%^BLACK%^into the window.");
    set_night_long("%^BOLD%^%^WHITE%^The Gatehouse.\n"
      "%^BOLD%^%^BLACK%^This is the control room of the gatehouse, not many people "
      "%^BOLD%^%^BLACK%^make it up here, but those that do usually feel really really "
      "%^BOLD%^%^BLACK%^tired. A large set of controls used to lift the gates stand "
      "%^BOLD%^%^BLACK%^next to a plush looking bed. Small shafts of sunlight drift "
      "%^BOLD%^%^BLACK%^into the window.");
    set_properties(([
	"light"       : 2,
	"night light" : 1,
	"no bump"     : 1,
	"outdoors"    : 1,
	"plain"       : 1,
	"no steal"    : 1,
      ]));
    set_exits( (["down" : ROOMS"gatehousew"]) );

    set_items( ([
	"controls"  : "%^BOLD%^%^WHITE%^A large wheel is set on a hinge wooden block that has all sorts of ropes coming out of it. These are the controls for the gates.",
	"wheel" : "Hmmm maybe you could raise or lower the gates with a turn of this wheel.",
	"bed" : "A large and confortable bed for the guards to sleep in during off shifts.",
	"window" : "A rather large mountain range dominates the window."
      ]) );


}

void reset() {
    ::reset();
    if (!present("guard", this_object()))
	new(MOBS"regguard" )->move(this_object());

    if (!present("guard 2", this_object()))
	new(MOBS"lazyguard" )->move(this_object());

    if (!present("guard 3", this_object()))
	new(MOBS"regguard" )->move(this_object());
}
