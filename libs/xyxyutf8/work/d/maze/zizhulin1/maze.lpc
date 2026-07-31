#include <ansi.h>
inherit VRM_SERVER;

void create()
{
	set_maze_map_color(HIW);
	set_inherit_room(ROOM);
	set_display_map(2);	
        //迷宫的单边长
        set_maze_long(5);
	//每个房间的出口，默认是2
	set_maze_exit(3);
	//无出口的方向不显示，默认是显示
	set_maze_exittype(1);
        //入口方向(出口在对面)
        set_entry_dir("south");
        //入口与区域的连接方向
        set_link_entry_dir("south");

        //入口与区域的连接档案名
        set_link_entry_room(__DIR__"enter");

        //出口与区域的连接方向
        set_link_exit_dir("north");

        //出口与区域的连接档案名
        set_link_exit_room(__DIR__"out");  

         //普通房间描述
       	set_maze_room_short("紫竹林");
       	set_maze_room_desc(@LONG
普陀后山的紫竹林。也是观音菩萨闲憩常到的所在。紫竹
细疏，清风微拂。漫步于此，世事之纷扰顿时烟消云散。往北
似有一小池塘。

LONG); 
        //入口房间短描述 
        set_entry_short("紫竹林"); 
        //入口房间描述 
        set_entry_desc(@LONG
普陀后山的紫竹林。也是观音菩萨闲憩常到的所在。紫竹
细疏，清风微拂。漫步于此，世事之纷扰顿时烟消云散。往北
似有一小池塘。

LONG);
        //出口房间短描述 
        set_exit_short("紫竹林"); 
        //出口房间描述 
        set_exit_desc(@LONG
普陀后山的紫竹林。也是观音菩萨闲憩常到的所在。紫竹
细疏，清风微拂。漫步于此，世事之纷扰顿时烟消云散。往北
似有一小池塘。

LONG);
        // 迷宫房间是否为户外房间？ 
        set_outdoors(1);                                                

        //迷宫房间是否刷新且刷新时间设置
        set_maze_refresh(43200);
        //迷宫销毁时间
	set_remove_time(43200);
}
