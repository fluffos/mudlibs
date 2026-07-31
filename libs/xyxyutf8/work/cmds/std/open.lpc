// open.c
#include <room.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir,str;
	int i;

	if( !arg ) return notify_fail("你要打开什么？\n");

	doors = environment(me)->query_doors();
	if( mapp(doors) ) 
	{
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) 
			dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 ) 
			{
				dir = dirs[i];
				break;
			}
		if( !dir ) 
			return notify_fail("你要打开什么？\n");
	
		if( environment(me)->open_door(dir) ) 
		{
            		if( !stringp(str=environment(me)->open_msg()) )  
            			message_vision("$N将" + doors[dir]["name"] + "打开。\n", me);
            		else   	message_vision(str,me);
/*            		{
                    		message_vision("$N站在城下，大声对着守城官兵说道：麻烦各位官爷将城门开开。\n",me);
                    		message_vision("\n\n只听”嘎吱吱“一声闷响，"+doors[dir]["name"] +"渐渐开了开来。。。\n",me); 	
                    	}
*/                    	
			return 1;
		}
	}
	return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : open <door> 或 <方向>
 
这个指令可以让你打开门.
 
HELP
    );
    return 1;
}
