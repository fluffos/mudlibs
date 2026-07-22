// close.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir,str;
	int i;

	if( !arg ) return notify_fail("你要关闭什么？\n");

	doors = environment(me)->query_doors();
	if( mapp(doors) ) 
	{
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 ) 
			{
				dir = dirs[i];
				break;
			}
		if( !dir ) 
			return notify_fail("你要关闭什么？\n");
	
		if( environment(me)->close_door(dir) ) 
		{
            		if( !stringp(str=environment(me)->close_msg()) )
            			message_vision("$N将" + doors[dir]["name"] + "关上。\n", me);
            		else	message_vision(str, me);
/*            		
            else   {
                           message_vision("\n只听城上守城官兵大声说道：天色已晚，关城门咯～～～\n",me); 
                           message_vision("\n只听”嘎吱吱“一声闷响，"+doors[dir]["name"] +"缓缓的关了起来。。。\n",me);        
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
指令格式 : close|guan <door> 或 <方向>
 
这个指令可以让你关上门.
 
HELP
    );
    return 1;
}
