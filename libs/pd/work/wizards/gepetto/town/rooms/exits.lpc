//      /std/room/exits.c

//      from the Nightmare Mudlib
//      functions handling room exits
//      created by Descartes of Borg 18 june 1993

#include <rooms.h>

int skip_obvious;
private mapping destinations;
private mapping invis_exits;
private mapping pre_exit_func;
private mapping post_exit_func;
private mixed *tracks;

int invis_exit(string str);
#define MAX_TRACKS  10
#define NUMBER   ({ "two", "three", "four", "five", "six", "seven", "eight",\
                  "nine", "ten", "many" })
#define TMPLONG  ({ "north", "northeast", "east", "southeast", "south",\
                  "southwest", "west", "northwest", "up", "down", "in",\
                  "out", "enter","exit",})
#define TMPSHORT ({ "n", "ne", "e", "se", "s", "sw", "w", "nw", "u", "d",\
                  "in","out", "enter","exit",})
