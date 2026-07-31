#include <ansi.h>
inherit VRM_SERVER;

void create()
{
        //迷宫房间所继承的物件的档案名称。
        set_inherit_room( "/d/maze/tupo10/room" );

        //唯一房间
        set_unique_room( ({
		"/d/maze/tupo10/boss_room",
        }) );
        //迷宫房间里的怪物。
        set_maze_npcs( ([
                "/d/maze/tupo10/npc/jing": 1 + random(3),
        ]) );
	set_maze_map_color(HIW);
        set_npcs_rate(90);
	set_display_map(2);	
        //迷宫的单边长
        set_maze_long(8);
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
        	set_maze_room_short("树林");
        	set_maze_room_desc(@LONG
树林中草木繁多，遍地绿草高可没膝。阵风吹过，草中
发出唏唏唆唆的响声，象是有人自草中穿行。顶上绿叶华盖，
密密麻麻把天都遮住了。

LONG); 
	}
	else if( random(2) )
	{
        	set_maze_room_short("树林");
        	set_maze_room_desc(@LONG
树林之中非常的暗，光线全被如伞如盖的树枝挡住。周围看不到一
个人影，你只能手摸着树干一步步走。除了脚下的枯枝发出被踩断
时的惨叫，还有一些无聊的小虫无聊的叫着。
黑暗深处不时传来一阵恐怖垂涎之声，你小心翼翼的走着。

LONG); 
	}
	else
	{
		set_maze_room_short("林间小道");
        	set_maze_room_desc(@LONG
树林中的一条小路。这里葛藤纠结，古木参天，绝少人行。周围看
不到一个人影，你只能手摸着树干一步步走。除了脚下的枯枝发出
被踩断时的惨叫，还有一些无聊的小虫无聊的叫着。
黑暗深处不时传来一阵恐怖垂涎之声，你小心翼翼的走着。

LONG); 
	}	
        //入口房间短描述 
        set_entry_short("花果山"); 
        //入口房间描述 
        set_entry_desc(@LONG
此山乃十洲之祖脉，三岛之来龙，自开清浊而立，鸿蒙判后而成。真个好山！
山中也多飞禽走兽，吸食天地精华，成精成魅的也不在少数。

LONG);
                        
        //出口房间短描述 
        set_exit_short("傲来国"); 
        //出口房间描述 
        set_exit_desc(@LONG
东胜神洲海边一小国。傲来国西临大海，东靠花果山，只是在其间
一块狭窄的平原地带上建有一座城池。一条大路直通南方，路上行
人也是匆匆而过。

LONG);
        // 迷宫房间是否为户外房间？ 
        set_outdoors(1);                                                
        //迷宫房间是否刷新且刷新时间设置
        set_maze_refresh(1800);
        //迷宫销毁时间
	set_remove_time(7200);
}
