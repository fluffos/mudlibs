#ifndef __ROOM__
#define __ROOM__

#define DOOR_CLOSED        1
#define DOOR_LOCKED        2
#define DOOR_SMASHED       4
#define DOOR_HIDDEN        8

int AddExits(mapping m);
mapping GetExits();
mapping GetItemDesc();
mapping GetObjects();
string GetOutDoor();
int SetExits(mapping m);
int SetItemDesc(mapping m);
int SetObjects(mapping m);
int SetOutDoors(string s);
object make_inventory(string f);
int query_max_encumbrance();
void reset();
void setup();
int valid_leave(object who, string d);
int welcome_visitor(object me);

#endif
