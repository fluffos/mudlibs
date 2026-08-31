#include <std.h>
#include <citrin.h>
inherit ROOM;
int y;
string get_long() {
    if(!query_night())  {
	return 
	"The entrance to a swamp is to the southwest of the village.  "
	"A gate stands there to help protect the village from the evil "
	"inside of the swamp.  An abandoned village can be seen to the "
	"north and east.  An inscription can be seen on the gate.  "
	"The gate is open."; }
    return 
    "The entrance to a swamp is to the southwest of the village.  "
    "A gate stands there to help protect the village from the evil "
    "inside of the swamp.  An abandoned village can be seen to the "
    "north and east.  An inscription can be seen on the gate.  "
    "The gate is closed.";
    y = 1;
}

void create() {
    ::create();
    set_name("Entrance to swamp");
    set_short("entrance to a swamp");
    set_long(get_long());
    set_exits((["southwest":ROOMS"swamp/12", "east":ROOMS"30",
	"north":ROOMS"28"]));
    set_pre_exit_functions( ({"southwest"}), ({"go_southwest"}) );
    set_items((["gate":"It protects the city from the evil "
	"in the swamp.  A small inscription is on the "
	"base of the gates."]));
}
int x;
void reset() {
    ::reset();
    get_long();
    if(present("ladder"))
	present("ladder")->remove();
    x = 0;
    y = 0;
}

void init() {
    ::init();
    add_action("read", "read");
    add_action("face", "face");
    add_action("pull", "pull");
    add_action("climb", "climb");
    add_action("look", "look");
}

int go_southwest() {
    if(query_night()) {
	write("The gate prevents your passage.\n");
	return 0;
    }
    write("You pass under the gate safely.\n");
    return 1;
}

int read(string str) {
    if(str != "inscription") return notify_fail("Read what?\n");
    write("The inscription reads:\n");
    write("To those that are lost, may find their way in the sun.  "
      "In the night those who face the moon will be free.\n");
    return 1;
}

int face(string str) {
    if(!query_night()) return 0;
    if(!str) return notify_fail("Face what?\n");
    if(x) return notify_fail("Nothing happens.\n");
    write("You notice a small glimpse of a handle.\n");
    x = 1;
    return 1;
}

int pull(string str) {
    object ob;
    if(x != 1) return 0;
    if(str != "handle") return notify_fail("Pull what?\n");
    write("You pull the handle and a ladder appears.\n");
    x = 2;
    say(this_player()->query_cap_name()+" pulls a handle and "
      "a ladder slides down the side of the gates and hits the ground.");
    ob = new(OBJECT);
    ob->set_name("ladder");
    ob->set_prevent_get("You cannot take the ladder.\n");
    ob->set_short("a ladder");
    ob->set_long("The ladder came from the wall.  You might be "
      "able to climb up it.\n");
    ob->move(this_object());
    return 1;
}

int climb(string str) {
    if(x != 2) return 0;
    if(str != "ladder") return notify_fail("Climb what?\n");
    write("You climb over the gate to the other side.\n");
    say(this_player()->query_cap_name()+" climbs the ladder and disappears "
      "to the other side.  The ladder slides back up the wall.");
    this_player()->move_player(SWAMP"12");
    reset();
    return 1;
}

int look(string str) {
    if(str != "at handle" && str != "handle") return 0;
    if(x != 2) return 0;
    write("You may be able to pull it.\n");
    return 1;
}

