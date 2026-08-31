#include <std.h>

inherit DAEMON;

int cmd_ditch(string str)
{
 object ob;
 object *fol;
 int i;

 if (!str || str=="")
    return notify_fail("Ditch who?\n");
 
 ob = find_player(str);
 if (!ob)
   return notify_fail("Could not find that player.\n");
 
 if (ob->query_following()!=this_player())
   return notify_fail(ob->query_cap_name()+" is not following you.\n");
 write("You ditch "+ob->query_cap_name()+".");
 message("info", this_player()->query_cap_name()+" ditches you.", ob);
 this_player()->remove_follower(ob);
 return 1;
}

void help()
{
 message("info", "Syntax: <ditch [player name]>\n"
"It causes a player that is following you to stop following.", this_player());
}
