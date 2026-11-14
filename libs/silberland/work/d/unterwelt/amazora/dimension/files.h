#define PATH "/d/unterwelt/amazora/dimension/"
#define NPC PATH "npc/"
#define ROOM PATH "room/"
#define OBJ PATH "obj/"

#define TP this_player()
#define TPN this_player()->name()
#define TO this_object()
#define TK(x) if(find_player("amazora"))tell_object(find_player("amazora"),x)
#define UPPER capitalize
#define LOWER lower_case
#define BS(x) break_string(x, 78)
#define DB(x) if(find_player("stahldorn")) tell_object(find_player("stahldorn"), ("Debug sagt: "+x+"\n") )
