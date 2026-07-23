#include "/doc/help.h"
#include <ansi.h>
#include <mudlib.h>
#include <group.h>

inherit F_CLEAN_UP;

string *default_search = DEFAULT_SEARCH_PATHS;

int main(object me, string arg )
{
        int i, j;
    	string file, *search, dir;

    	if( !arg ) 
    	{
            	cat( HELP_DIR + "help/topics" );
        	return 1;
    	}
        
        seteuid( getuid() );
        
    	if( arg == "map" ) 
    	{
    		dir = "/help/map/";
    		search = get_dir(dir);
    		i = sizeof(search);
    		if( !i ) 
    			return notify_fail("目前地图文件还没准备好。\n");
        	file = "目前共有以下地区的地图：";
    		for(j = 0; j < i; j++){
                	if ( j % 3 == 0 )
                		file += "\n\t";
                	file += sprintf("%-12s\t\t", search[j]);
                }
            	file += "\n你可用 help map xxx 的格式查看具体地图。\n";
        	me->start_more( file );
        	return 1;
          
        }  
        
	if( sscanf(arg, "map %s", arg) ) 
    	{
        	if( !file_size("/help/map/"+arg) )
        		return notify_fail("目前还没有这个地区的地图文件。\n");
        	me->start_more( read_file("/help/map/" + arg) );
        	return 1;
          
        }  
        
    	arg = ALIAS_D->process_global_alias( arg );
    	if( stringp( file = me->find_command( arg )) ) 
    	{
                notify_fail("有这个指令存在，并没有说明文件。\n");
        	return write( HIY"◎"HIW+CHINESE_MUD_NAME+HIY"◎"NOR"\n") + file->help( me );
    	}

    	if( pointerp( search = me->query( "help_search_path" ) ) ) 
    	{
        	i = sizeof(search);
        	while( i-- )
                {
                        if( file_size( search[i] + arg) > 0 ) 
                        {
                                me->start_more( read_file(search[i] + arg) );
                                return 1;
                        }
                }
    	}

    	sscanf(arg, "%s()", arg);
    	if( pointerp(default_search) ) 
    	{
            	i = sizeof(default_search);
        	while(i--) 
                {
                        if( file_size(default_search[i] + arg)>0 ) 
                        {
                            	me->start_more( read_file(default_search[i] + arg) );
                            	return 1;
                        }
                }
    	}

    	if( sscanf(arg, "group %s", arg) ) 
    	{
            	dir = GROUP_DIR + arg + "/";
        	if( file_size(dir) != -2 )
                	return notify_fail("没有这个帮派。\n");
        	if( file_size(dir + "story") < 0 )
                	return notify_fail("这个帮派没有简介。\n");
        	me->start_more(HIY"◎"HIW+CHINESE_MUD_NAME+HIY"◎"NOR"－"
                + find_object(dir + "kingdom")->query("kingdom_name") + "\n"NOR
            	+ read_file(dir+"story"));
            	return 1;
    	} 
    	return notify_fail("没有针对这项主题的说明文件。\n");
}

int help(object me)
{
    	write(@HELP
----------------------------------------
指令格式：help <主题>

help <函数名称>
      
例如：> help cmds

这个指令提供你针对某一主题的详细说明文件，若是不指定主题，
则提供你有关主题的文件。

help map
查看地图

help group <帮派名称>
查看帮派简介
----------------------------------------
HELP
        );
    	return 1;
}

