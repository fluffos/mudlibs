/* maze.h -- a room.h for the mirrormaze */

inherit "players/padrone/maze/maze";


#define EXTRA_INIT
#define EXTRA_RESET
#define EXTRA_LONG
#define EXTRA_NORTH
#define EXTRA_SOUTH
#define EXTRA_EAST
#define EXTRA_WEST

#define MAZE_ROOM( n,s,e,w) set_dirs(n,s,e,w)

reset(arg) 
{
    ::reset(arg);
    if (arg) return; 
    set_light(1); 
} 

set_dirs(n,s,e,w)
{
    north_room = n;
    south_room = s;
    west_room =  w;
    east_room =  e;
}
