#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("entrance to swamp");
    set_short("entrance to a swamp");
    set_long(
      "The ground is wet and muddy.  "
      "Green moss covers most of the ground.  "
      "The occasional spiderweb can be seen dangling from the "
      "trees awaiting unsuspecting prey.  "
      "Ocassional a ray of sun seems to get past the heavy "
      "over cast of the trees.  "
      "Tree stumps are on the ground where animals have knocked them "
      "down.  "
      "An occasional breeze blows through the area."
    );
    set_exits(([
	"west":SWAMP"11",
	"northeast":ROOMS"29",
      ]));
    set_pre_exit_functions( ({"northeast"}), ({"go_northeast"}) );
    set_post_exit_functions( ({"northeast"}), ({"go_northeast_post"}) );
}

int go_northeast() {
    if(query_night()) {
	say("The gate opens.  It closes almost immediatly.\n");
	write("The gate opens allowing you to pass.\n");
	return 1;
    }
    write("You pass under the gate safely.\n");
    return 1;
}

int go_northeast_post() {
    if(query_night()) {
	write("The gate closes behind you.\n");
	environment(this_player())->reset();
	return 1;
    }
    return 1;
}

