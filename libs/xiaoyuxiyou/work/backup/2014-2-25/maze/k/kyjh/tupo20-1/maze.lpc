#include <ansi.h>
inherit VRM_SERVER;

void create()
{
        //迷宫房间所继承的物件的档案名称。
        set_inherit_room( "/d/maze/tupo20-1/room" );
	set_maze_map_color(HIW);
        set_npcs_rate(90);
	set_display_map(2);	
	set_maze_npcs( ([
                "/d/maze/tupo20-1/obj/shi-1": 1+random(2),
                "/d/maze/tupo20-1/obj/shi-2": 1+random(2),
                "/d/maze/tupo20-1/obj/shi-3": 1+random(2),
                "/d/maze/tupo20-1/obj/shi-4": 1+random(2),
                "/d/maze/tupo20-1/obj/shi-5": 1+random(2),
        ]) );	
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
	if( random(2) )
	{         
        	set_maze_room_short("峭壁");
        	set_maze_room_desc(@LONG
你走在峭壁边的小路上。一侧是密密的丛林，外侧却是极深的陡
壁。山风凛冽，几乎要把你刮落崖去。

LONG); 
	}
	else if( random(2) )
	{
        	set_maze_room_short("荒山野林");
        	set_maze_room_desc(@LONG
这是一片荒山野林，四周都是一株株高巨无比的大树。大树茂密的枝叶，
互相交织着，是以阳光难以渗透，使人有不辨天日之感。
隐约看到林中有一面石壁，长满了迷迷麻麻的山藤。

LONG); 
	}
	else
	{
		set_maze_room_short("栈道");
        	set_maze_room_desc(@LONG
栈道以铁斜插，上覆青石板，宽不足八寸。上乃绝壁，下亦绝壁。挽索
登其上，只听山风呼啸，林涛怒吼。
远处偶传一两声禽鸣兽嘶，更使人毛骨悚然。
踏上悬空的栈道，紧攀铁索，屏息静气，缓步挪动，才能过去。

LONG); 
	}	
        //入口房间短描述 
        set_entry_short("山间平地"); 
        //入口房间描述 
        set_entry_desc(@LONG
你走在山间平地上。林中冷风轻吹门响。很失意的感觉。
LONG);
                        
        //出口房间短描述 
        set_exit_short("栈道"); 
        //出口房间描述 
        set_exit_desc(@LONG
栈道以铁斜插，上覆青石板，宽不足八寸。上乃绝壁，下亦绝壁。挽索
登其上，只听山风呼啸，林涛怒吼。
远处偶传一两声禽鸣兽嘶，更使人毛骨悚然。
踏上悬空的栈道，紧攀铁索，屏息静气，缓步挪动，才能过去。

LONG);
        // 迷宫房间是否为户外房间？ 
        set_outdoors(1);                                                
        //迷宫房间是否刷新且刷新时间设置
        set_maze_refresh(7200);
        //迷宫销毁时间
	set_remove_time(7200);
}