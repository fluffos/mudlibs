#include <room.h>
#include <areas.h>

int exit_num;

void
reset_room()
{
    exit_num = random(4);	/* "grin" */
}

void
create_room()
{
    set_short("A maze");
    set_long("In a maze. You feel fair bit lost.");
    set(IN_CITY);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_DARKNESS);
    set_exits(([
	"north"	: AREA_TRISTEZA+"rooms/well",
	"east"	: AREA_TRISTEZA+"rooms/well", 
	"south"	: AREA_TRISTEZA+"rooms/well",
	"west"	: AREA_TRISTEZA+"rooms/well" 
      ]));
    set_commands(([
	"north" : "north_cmd",
	"east"  : "east_cmd",
	"west"  : "west_cmd",
	"south" : "south_cmd"
      ]));
    add_monster( AREA_TRISTEZA+"well_maze/mazemaster", 0, 1 );
    reset_room();
}


status north_cmd()
{
    if (exit_num != 0) return 0;
    this_player() -> move_player("north", AREA_TRISTEZA+"well_maze/maze2");
    return 1;
}

status east_cmd()
{
    if (exit_num != 1) return 0;
    this_player() -> move_player("east", AREA_TRISTEZA+"well_maze/maze2");
    return 1;
}

status west_cmd()
{
    if (exit_num != 2) return 0;
    this_player() -> move_player("west", AREA_TRISTEZA+"well_maze/maze2");
    return 1;
}

status south_cmd()
{
    if (exit_num != 3) return 0;
    this_player() -> move_player("south", AREA_TRISTEZA+"well_maze/maze2");
    return 1;
}

