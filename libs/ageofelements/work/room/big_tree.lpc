#include <global.h>

inherit LIB_ROOM;

void
create_room()
{
    set_lumens(1);

    set_brief("Big tree");

    set_description(
	"A big single tree on the plain."
      );

    set_exits( ([
	"east": "/room/plane7"
	, "west": "/room/giant_path"
      ]) );

    set_commands( ([
	"climb": "climb"
	, "tie": "tie"
      ]) );

    add_transient_object("/obj/rope");
}

int
id(string str)
{
    if (str == "tree" || str == "big tree") {
	return 1;
    }

    return 0;
}

int
tie(string str)
{
    if (str == "tree" || str == "big tree") {
	write("The branches are very high up.\n");
	return 0;
    }

    return 0;
}

int
climb(string str)
{
    if (!id(str)) {
	return 0;
    }

    write("There are no low branches.\n");
    return 1;
}
