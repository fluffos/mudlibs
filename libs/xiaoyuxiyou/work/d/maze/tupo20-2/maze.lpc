#include <ansi.h>
inherit VRM_SERVER;

void create()
{
        //迷宫房间所继承的物件的档案名称。
        set_inherit_room( "/d/maze/tupo20-2/room" );
	set_maze_map_color(HIW);
        set_npcs_rate(90);
	set_display_map(2);	
	set_maze_npcs( ([
                "/d/maze/tupo20-2/obj/yao": 1+random(5),
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
	set_maze_room_short("洞内");
        set_maze_room_desc(@LONG
洞内四壁与顶上都间或镶嵌了一些玉石，闪闪发光，映得宛如白昼。

LONG); 
	//入口房间短描述 
        set_entry_short("洞口"); 
        //入口房间描述 
        set_entry_desc(@LONG
眼前是一个山洞，虽然幽深，但是石壁之上皆镶了宝石，倒也照得如同白昼。
LONG);
                        
        //出口房间短描述 
        set_exit_short("内洞"); 
        //出口房间描述 
        set_exit_desc(@LONG
洞内四壁与顶上都间或镶嵌了一些玉石，闪闪发光，映得宛如白昼。

LONG);
        // 迷宫房间是否为户外房间？ 
        set_outdoors(1);                                                
        //迷宫房间是否刷新且刷新时间设置
        set_maze_refresh(84600);
        //迷宫销毁时间
	set_remove_time(10800);
}