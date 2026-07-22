#include <ansi.h>
inherit VRM_SERVER;

void create()
{
        //迷宫房间所继承的物件的档案名称。
        set_inherit_room( "/d/maze/meishan/room" );

        //唯一房间
        set_unique_room( ({
		"/d/maze/meishan/boss_room1",
		"/d/maze/meishan/boss_room2",  
		"/d/maze/meishan/boss_room3",  
		"/d/maze/meishan/boss_room4",  
		"/d/maze/meishan/boss_room5",  
		"/d/maze/meishan/boss_room6",  
        }) );
        set_center_room("/d/maze/meishan/boss_room7");

        //迷宫房间里的怪物。
        set_maze_npcs( ([
                "/d/maze/meishan/npc/jing": 1 + random(2),
                "/d/maze/meishan/npc/guai": 1 + random(2),
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
        	set_maze_room_short("枫林");
        	set_maze_room_desc(@LONG
枫林中草木繁多，遍地绿草高可没膝。阵风吹过，草中
发出唏唏唆唆的响声，象是有人自草中穿行。顶上枫叶似火，
密密麻麻把天都遮住了。

LONG); 
	}
	else if( random(2) )
	{
        	set_maze_room_short("集仙坡");
        	set_maze_room_desc(@LONG
山势陡转于此，堆成半亩大小的一片平地。从此仰望山颠，
尖秀玲珑，悚拔瘦削，似有锋芒不可逼视。地下有土格分划，方
者甚方，圆者浑圆，似非天力所及。

LONG); 
	}
	else
	{
		set_maze_room_short("朝云岭");
        	set_maze_room_desc(@LONG
岭上怪石嶙峋，颇为难走。石头颜色多彩，远望有如朝云，
得名于此。向山下望，江水有如一道白练，缓向东去，岸上山云
涌起，嫩绿一片。

LONG); 
	}	
        //入口房间短描述 
        set_entry_short("铁柱关"); 
        //入口房间描述 
        set_entry_desc(@LONG
从铁柱关往上便是梅山了，铁柱关是上山的唯一道路。路旁
有两座怪石，高达丈许，形如铁柱，是以此地得名铁柱关。

LONG);
                        
        //出口房间短描述 
        set_exit_short("飞凤峰"); 
        //出口房间描述 
        set_exit_desc(@LONG
立于山颠而望四周，唯山边有数朵白云，如同鸾鹤翔舞徘徊，
久久不散，令人惊异。望灌江边小镇，皆茅草屋顶，竹编篱笆，宛
然有着幽雅的情趣。

LONG);
        // 迷宫房间是否为户外房间？ 
        set_outdoors(1);                                                

        //迷宫房间是否刷新且刷新时间设置
        set_maze_refresh(7200);
        //迷宫销毁时间
	set_remove_time(3600);
}
