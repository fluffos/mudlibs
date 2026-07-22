#include <ansi.h>

inherit VRM_SERVER;

void create()
{
        //迷宫房间所继承的物件的档案名称。
        set_inherit_room( "/d/maze/beiyin/room" );

        //唯一房间
        set_unique_room( ({
		"/d/maze/beiyin/boss_room",        	
        }) );
        set_center_room("/d/maze/beiyin/boss_room");

        //迷宫房间里的怪物。
        set_maze_npcs( ([
                "/d/maze/beiyin/npc/guai": 1 + random(2),
        ]) );

	set_maze_map_color(HIW);
        set_npcs_rate(90);
	set_display_map(2);	
        set_maze_long(7);
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
        set_maze_room_short(HIG"背阴巷"NOR);
                        
        set_maze_room_desc(@LONG
背阴巷位于长安城之西南，住户大多是些贫苦人家。由于官府很
少管这里，所以治安并不十分好。周围民居破落，路边杂草丛生，到
处是沉闷的灰色，不见一丝生机。来往的人大多是衣衫褴褛，满面愁
色。

LONG); 

        //入口房间短描述 
        set_entry_short("背阴巷口"); 
                        
        //入口房间描述 
        set_entry_desc(@LONG
背阴巷位于长安城之西南，住户大多是些贫苦人家。由于官府很
少管这里，所以治安并不十分好。周围民居破落，路边杂草丛生，到
处是沉闷的灰色，不见一丝生机。来往的人大多是衣衫褴褛，满面愁
色。

LONG);
                        
        //出口房间短描述 
        set_exit_short(HIR"背阴巷口"NOR); 
                        
        //出口房间描述 
        set_exit_desc(@LONG
背阴巷位于长安城之西南，住户大多是些贫苦人家。由于官府很
少管这里，所以治安并不十分好。周围民居破落，路边杂草丛生，到
处是沉闷的灰色，不见一丝生机。来往的人大多是衣衫褴褛，满面愁
色。

LONG);
        // 迷宫房间是否为户外房间？ 
        set_outdoors(1);                                                

        set_maze_refresh(0);
        //迷宫销毁时间
	set_remove_time(3600);     
}