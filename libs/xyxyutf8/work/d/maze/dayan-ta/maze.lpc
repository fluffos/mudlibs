#include <ansi.h>

inherit VRM_SERVER;

void create()
{
        //迷宫房间所继承的物件的档案名称。
        set_inherit_room( "/d/maze/dayan-ta/room" );

        //唯一房间
        set_unique_room( ({
		"/d/maze/dayan-ta/boss_room1",
		"/d/maze/dayan-ta/boss_room2",
		"/d/maze/dayan-ta/boss_room3",
		"/d/maze/dayan-ta/boss_room4",
        }) );
 	set_center_room("/d/maze/dayan-ta/boss_room5");    
	//迷宫房间里的怪物。
        set_maze_npcs( ([
                "/d/maze/dayan-ta/npc/guai": 1 + random(2),
        ]) ); 	    
	set_maze_map_color(HIG);
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
        set_maze_room_short("地宫");
                        
        set_maze_room_desc(@LONG
洞内四面纵横十余丈，其中错牙交错的甬道连接四方，两名的
石壁上画满佛符，闪烁着微弱的金光。 

LONG); 

        //入口房间短描述 
        set_entry_short("大雁塔下"); 
                        
        //入口房间描述 
        set_entry_desc(@LONG
大雁塔为一座七层方形塔，塔身十分雄伟，底座宽大，造型简洁庄严神秘。方塔底
座有门，门楣上有石刻画。
    却不想塔下另有玄机，只见四面纵横十余丈，其中错牙交错的甬道
连接四方，两名的石壁上画满佛符，闪烁着微弱的金光。  

LONG);
                        
        //出口房间短描述 
        set_exit_short(HIR"大雁塔下"NOR); 
                        
        //出口房间描述 
        set_exit_desc(@LONG
大雁塔为一座七层方形塔，塔身十分雄伟，底座宽大，造型简洁庄严神秘。方塔底
座有门，门楣上有石刻画。
    却不想塔下另有玄机，只见四面纵横十余丈，其中错牙交错的甬道
连接四方，两名的石壁上画满佛符，闪烁着微弱的金光。 

LONG);
        // 迷宫房间是否为户外房间？ 
        set_outdoors(0);                                                

        set_maze_refresh(0);
        //迷宫销毁时间
	set_remove_time(5400);     
}