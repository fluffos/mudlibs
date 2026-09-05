#include <ansi.h>

int random_move()
{
	mapping exits;
	string *dirs;
	int i;
	if(!environment()) return 0;
	if(sizeof(environment()->query("exits")) == 0) return 0;
	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	i = random(sizeof(dirs));
	if (arrayp(this_object()->query("PlaceList"))&&member_array(environment()->query("exits/"+dirs[i]),this_object()->query("PlaceList"))==-1) return 0;
	if( !environment()->valid_leave(this_object(), dirs[i]) ) return 0;
	if(0 == command("go " + dirs[i])) return 0;
	return 1;
}