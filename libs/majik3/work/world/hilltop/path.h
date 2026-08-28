/*
 * PATH.H
 *
 * Hilltop Village 
 *
 */

#ifndef PATH_H
#define PATH_H

#define AREA_NAME       "hilltop"
#define CODER_NAME      "namhas"

#define ROOM_PATH       "/world/" + AREA_NAME + "/rooms/"
#define ITEM_PATH       "/world/" + AREA_NAME + "/items/"
#define MONSTER_PATH    "/world/" + AREA_NAME + "/monsters/"
#define MISC_PATH       "/world/" + AREA_NAME + "/misc/"

query_author () { return CODER_NAME; }

#endif /* PATH_H */
