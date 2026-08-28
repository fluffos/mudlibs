/* path.h file makes easier to make areas, make it like this */

#ifndef PATH_H
#define PATH_H

#define AREA_NAME       "example_area"
#define CODER_NAME      "people"

#define ROOM_PATH       "/doc/examples/" + AREA_NAME + "/rooms/"
#define ITEM_PATH       "/doc/examples/" + AREA_NAME + "/items/"
#define MONSTER_PATH    "/doc/examples/" + AREA_NAME + "/monsters/"
#define MISC_PATH       "/doc/examples/" + AREA_NAME + "/misc/"

query_author () { return CODER_NAME; }

#endif /* PATH_H */
