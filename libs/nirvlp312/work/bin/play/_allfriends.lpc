#include <ansi.h>

int cmd_allfriends(string str)
{
	int x, y;
	string *f;
	if(str) return 0;
	
	write("\n\t\tALL FRIENDS (offline or not)\n");
	f = (string *)this_player()->query_friends();
	y = sizeof(f);
	for(x = 0; x < y; x ++)
	{
		write("\t"+capitalize(f[x])+"\n");
	}
	write("\n");
	write("Type \"friends\" to see your online friends and their location.\n");
	write("\n");
	return 1;
}