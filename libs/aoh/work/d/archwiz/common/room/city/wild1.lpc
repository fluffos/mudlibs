#include "path.h"
inherit "std/room";

create() {
 ::create();
 SetIntShort("Wilderness");
 SetIntLong(
"You are on a path west of the capital of the world. To the east you see the "
"busy streets of Nightfall City, though you are standing within a light forest. "
"The trees are strong and the bushes are thick. There is no way to leave the "
"path here. The forest gets darker to the west.\n");
 SetIndoors(0);
 AddDetail("wilderness","The forest is full of dark, dense trees.\n");
 AddDetail( ({"city","nightfall city","Nightfall City","Nightfall city","City"}),
"The biggest and most important town of the world lies east of you.\n");
 AddDetail("forest",
"You are in a small forest, that goes over into the huge Elvenwood to the "
"southwest.\n");
 AddDetail("elvenwood","It's a huge forest to the southwest.\n");
 AddDetail(({"tree","trees"}),"They are dark and dense.\n");
 AddExit("east","./hump");
 AddExit("west","./wood1");
}
