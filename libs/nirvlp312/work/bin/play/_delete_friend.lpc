#include <ansi.h>

int cmd_delete_friend(string str)
{
	string *f;
	int x;
	
	if(!str) return 0;
	
	if(!this_player()->query_friend(str))
	{
		write(str+" is not one of your friends!\n");
		return 1;
	}
	this_player()->delete_friend(str);
	write("Ok, "+capitalize(str)+" has been removed from\n"+
	" your friends list.\n");
	return 1;
}