#include <ansi.h>
inherit VRM_SERVER; 
 
#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0



void create() 
{ 
        //迷宫房间所继承的物件的档案名称。 
        set_inherit_room( ROOM ); set("no_clean_up",1);
                        
        //唯一房间
        //set_unique_room( unique_rooms ); 

        //迷宫房间里的怪物。 
        set_maze_npcs( ([
                __DIR__"npc/0000/toad": random(2),
                __DIR__"npc/0000/rabbit": random(2),  
                __DIR__"npc/0000/wolf_baby": random(2), 
                __DIR__"npc/0000/wolf_big": random(2), 
                __DIR__"npc/0000/wolf_king": random(2), 
                __DIR__"npc/0000/tiger_baby": random(2), 
                __DIR__"npc/0000/tiger_big": random(2), 
                __DIR__"npc/0000/tiger_king": !random(2), 
                __DIR__"npc/0000/bear_baby": random(2), 
                __DIR__"npc/0000/bear_big": random(2), 
                __DIR__"npc/0000/bear_king": random(2), 
                __DIR__"npc/0000/snake_baby": random(2), 
                __DIR__"npc/0000/snake_big": random(2), 
                __DIR__"npc/0000/snake_king": random(2), 
                __DIR__"npc/0000/dragon_baby": random(2), 
                __DIR__"npc/0000/dragon": !random(8), 	
        ]) );                   
        
        //不算死亡
        //set_true_death_room(1);

        //迷宫的单边长 
        set_maze_long(8); 

        set_npcs_rate(66);
        
        set_lonely_create(1);
                        
        //入口方向(出口在对面) 
        set_entry_dir("east"); 
                        
        //入口与区域的连接方向 
        set_link_entry_dir("east"); 
                        
        //入口与区域的连接档案名 
        set_link_entry_room("/d/city/wumiao"); 
                        
        //出口与区域的连接方向 
        set_link_exit_dir("south"); 
                        
        //出口与区域的连接档案名 
        set_link_exit_room(__DIR__"vrm00out1"); 

        //迷宫房间里的BOSS。
        set_exit_npcs(__DIR__"npc/0000/boss");
        
        
        // 迷宫入口的怪物。
//        set_entry_npcs( "/d/city/npc/liumang" );

        set_maze_boxs(2);
        set_maze_traps(6); 
                        
        //以下是入口坐标
        //set_link_entry_room_x(ENTER_ROOM_X);
        //set_link_entry_room_y(ENTER_ROOM_Y);
        //set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //普通房间描述
        set_maze_room_short("原始森林");
                        
        set_maze_room_desc(@LONG
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
LONG); 

        //入口房间短描述 
        set_entry_short("原始森林"); 
                        
        //入口房间描述 
        set_entry_desc(@LONG
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
LONG);
                        
        //出口房间短描述 
        set_exit_short("原始森林"); 
                        
        //出口房间描述 
        set_exit_desc(@LONG
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
LONG);

        // 迷宫房间是否为户外房间？ 
        set_outdoors(1);                                                

       // 迷宫刷新时间
        //set_maze_refresh(680); 
        
        // 迷宫摧毁时间
        set_remove_time(3000); 
} 



