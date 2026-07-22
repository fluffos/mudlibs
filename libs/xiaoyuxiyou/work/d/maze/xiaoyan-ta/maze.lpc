#include <ansi.h>

inherit VRM_SERVER;

void create()
{
        //迷宫房间所继承的物件的档案名称。
        set_inherit_room( "/d/maze/xiaoyan-ta/room" );

        //唯一房间
        set_unique_room( ({
		"/d/maze/xiaoyan-ta/boss_room",        	
        }) );
        
	set_maze_map_color(HIG);
        set_npcs_rate(90);
	set_display_map(2);	
        set_maze_long(8);
	set_maze_exit(3);
	set_maze_exittype(1);

        //入口方向(出口在对面)
        set_entry_dir("west");
        //入口与区域的连接方向
        set_link_entry_dir("north");
        //入口与区域的连接档案名
        set_link_entry_room(__DIR__"enter");

        //出口与区域的连接方向
        set_link_exit_dir("south");
        //出口与区域的连接档案名
        set_link_exit_room(__DIR__"out");  

         //普通房间描述
        set_maze_room_short("甬道");
                        
        set_maze_room_desc(@LONG
洞内四面纵横十余丈，其中错牙交错的甬道连接四方，两名的
石壁上画满佛符，闪烁着微弱的金光。 

LONG); 

        //入口房间短描述 
        set_entry_short("小雁塔下"); 
                        
        //入口房间描述 
        set_entry_desc(@LONG
小雁塔是一座通高几十丈的砖塔，庄严而玲珑，塔身檐角密布，一共有
十五层之高。
    却不想塔下另有玄机，只见四面纵横十余丈，其中错牙交错的甬道
连接四方，两名的石壁上画满佛符，闪烁着微弱的金光。  

LONG);
                        
        //出口房间短描述 
        set_exit_short(HIR"小雁塔下"NOR); 
                        
        //出口房间描述 
        set_exit_desc(@LONG
小雁塔是一座通高几十丈的砖塔，庄严而玲珑，塔身檐角密布，一共有
十五层之高。
    却不想塔下另有玄机，只见四面纵横十余丈，其中错牙交错的甬道
连接四方，两名的石壁上画满佛符，闪烁着微弱的金光。 

LONG);
        // 迷宫房间是否为户外房间？ 
        set_outdoors(0);                                                

        set_maze_refresh(0);
        //迷宫销毁时间
	set_remove_time(5400);     
}