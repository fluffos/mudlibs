#include <ansi.h>
inherit VRM_SERVER;

void create()
{
        set_inherit_room( "/d/maze/ymdh/room" );//迷宫房间所继承的物件的档案名称。
	set_maze_map_color(HIW);
        set_npcs_rate(90);
	set_display_map(2);	
        set_maze_long(10);//迷宫的单边长
	set_maze_exit(3);//每个房间的出口，默认是2
	set_maze_exittype(1);//无出口的方向不显示，默认是显示
        set_entry_dir("south");//入口方向(出口在对面)
        set_link_entry_dir("south");//入口与区域的连接方向
        set_link_entry_room(__DIR__"enter");//入口与区域的连接档案名
	set_link_exit_room(__DIR__"out");  //出口与区域的连接档案名
        set_link_exit_dir("north");//出口与区域的连接方向
	set_maze_room_short("禹王林");//普通房间描述
       	set_maze_room_desc(@LONG
……　禹王林里浓雾遮天，你熏熏晕晕什么也看不清　……

LONG); 
        set_entry_short("禹王林"); //入口房间短描述 
        set_entry_desc(@LONG
禹王林浓密浩瀚如海，远风吹过，林涛阵阵。雾从脚下生，有如一望
无际万里的纱帐飘渺似烟波海上。

LONG);
        set_exit_short("禹王林"); //出口房间短描述 
        set_exit_desc(@LONG
禹王林浓密浩瀚如海，远风吹过，林涛阵阵。雾从脚下生，有如一望
无际万里的纱帐飘渺似烟波海上。

LONG);
        set_maze_refresh(600);//迷宫房间是否刷新且刷新时间设置
        set_remove_time(3600);//迷宫销毁时间
}
