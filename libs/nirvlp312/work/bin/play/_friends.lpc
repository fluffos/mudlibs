#include <ansi.h>

int cmd_friends(string str)
{
	string *f;
	int x, y;
        int cnt;
	object ob, envob;
	
	if(!(f=(string*)this_player()->query_friends()) ||
	  (y=sizeof(f)) == 0)
	{
		write("You don't have any friends.\n");
		return 1;
    }
    write("\n");
    write("\t\t\tFRIENDS\n\n");
   write(pad("",69,'-')+"\n");
    for(x=0;x<y;x++)
    {
        if((ob=find_player(f[x])) && (envob=environment(ob)))
    	{
    		write("\t"+capitalize(f[x])+"\t"+
             "\t\t"+(string)envob->short()+"\n");
           cnt ++;
        }
    }
    write("\n");
    write(cnt+" friends logged in.\n");
   write("\n");
    write("Type \"allfriends\" to see all your friends, offline or not.\n");
    write("You can also \"add_friend\" or \"delete_friend\".\n");
    write("\n");
    return 1;
}
