#include <ansi.h>
inherit VRM_SERVER;

void create()
{
        //迷宫房间所继承的物件的档案名称。
        set_inherit_room( "/d/maze/baihuazhen/room" );
        set_valid_rooms( "/d/maze/baihuazhen/room" );
	set_display_map(2);	
        //迷宫的单边长
        set_maze_long(7);
        //入口方向(出口在对面)
        set_entry_dir("enter");
        //入口与区域的连接方向
        set_link_entry_dir("south");
        //入口与区域的连接档案名
        set_link_entry_room(__DIR__"enter");
        //出口与区域的连接方向
        set_link_exit_dir("out");
        //出口与区域的连接档案名
        set_link_exit_room(__DIR__"out");  
         //普通房间描述
        set_maze_room_short("花海");
        set_maze_room_desc(@LONG
走了也不知多久，风中突然传来一阵阵甜蜜的花香。这花香不是牡
丹，不是玫瑰，也不是梅，不是菊......这花香甜蜜得竟非世间所有。

LONG); 
        //入口房间短描述 
        set_entry_short("百花阵入口"); 
        //入口房间描述 
        set_entry_desc(@LONG
走了也不知多久，风中突然传来一阵阵甜蜜的花香。这花香不是牡
丹，不是玫瑰，也不是梅，不是菊......这花香甜蜜得竟非世间所有。

LONG);
        //出口房间短描述 
        set_exit_short(HIR"百花阵出口"NOR); 
        //出口房间描述 
        set_exit_desc(@LONG
走了也不知多久，风中突然传来一阵阵甜蜜的花香。这花香不是牡
丹，不是玫瑰，也不是梅，不是菊......这花香甜蜜得竟非世间所有。

LONG);
        // 迷宫房间是否为户外房间？ 
        set_outdoors(0);
        //迷宫房间是否刷新且刷新时间设置
        set_maze_refresh(0);
        //迷宫销毁时间
	set_remove_time(300);
}
