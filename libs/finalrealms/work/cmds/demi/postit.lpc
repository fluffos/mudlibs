#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup(){
    position = 2;
}

protected int cmd(string str, object me) {
    object ob;
    string name;

    notify_fail("Usage: postit <playername> <text>\n");
    if(str)
    {
	if (sscanf(str, "%s %s", name, str) == 2)
	{
	    name = me->expand_nickname(name);
	    ob = find_player(name);
	    if (!ob) {  
		notify_fail("Cannot find "+name+".\n");
		return 0;
	    }
	    ob->add_player_note(str);
	    write("Note added to player.\n");
	    return 1;
	}
	else if (str == "?")
	{
	    object *userP = users(), user;
	    string postits;

	    foreach (user in userP)
	    {
		if (user && (postits = user->query_player_notes()))
		{
		    write(user->query_cap_name()+"\n");
		    write(postits+"\n---------------\n");
		}
	    }
	    return 1;
	}
    }
    return 0;
} /* cmd() */  
