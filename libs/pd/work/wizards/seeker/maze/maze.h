#ifndef __MAZE_H__
#define __MAZE_H__

#define NEW_MAZE "New_Maze"
#define MAIN "/wizards/seeker/maze/"
#define BASE_ROOM MAIN+"base_room"
#define ROOMS MAIN+"rooms/"
#define EXITS ({ "west", "east", "north", "south" })
#define OPPOSITES ([ "west" : "east",\
                     "east" : "west",\
                     "north" : "south",\
                     "south" : "north",\
                     "maze"  : "out",\
                     "down"  : "up",\
                     "up"    : "down" ])
#define MAZE_DAEMON "/wizards/seeker/maze/maze_daemon"

#define MAZE_SET_LONG ({\
"There are walls leading the way in different directions. The walls "\
"tower above you with ivy plants growing on them coming off the top. "\
"Dust fills the air when people walk on the loose dirt on the ground.",\
\
"The walls tower above you and mildew and mold along with plants grow "\
"on the old wall. A cool refreshing mist falls from the top of the walls "\
"from an un-known source. The brown dirt on the ground is moist from the "\
"mist.",\
})
#endif

