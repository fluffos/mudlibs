#include <std.h>
#include <citrin.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Entrance to the Forgotten Tunnels");
    set_properties( (["light" : 2, "night light" : 1]) );
    set_property("forest", 1);
    set_long("The trees seem dead around here, their roots "
      "seemed to have been pulled mostly from the ground.  "
      "A large Stone Doorway protrudes from the ground, "
      "leading down into the depths of darkness.  Two stone "
      "creatures stand guard at the entrance.  The statues "
      "seemed cracked and at any minute look as if they "
      "would fall apart.");
    set_exits( (["north" : ROOMS+"57",
	"down" : "/wizards/whit/rooms/tunnels/1",
      ]) );
    set_items( ([ ({"stone creatures","creature"}) : 
	"The stone creatures seem as if they "
	"stand guard to the entrance.",
	({"doorway","stone doorway"}) : "The "
	"doorway leads down stairs into the "
	"ground.",
	({"tree","trees","roots"}) : "There "
	"roots have been long ago pulled "
	"from the ground making them lifeless.",
      ]) );
    set_pre_exit_functions( ({"down"}), ({"down"}) );
}
int down() {
    if(!wizardp(this_player())) {
	say("The creatures eyes begin to glow red as "+this_player()->query_cap_name()+" tries to "
	  "enter the doorway.\n");
	write("The creatures eyes begin to glow.  A strange force repels you.");
	return 0;
    }
    return 1;
}
