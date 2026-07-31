#include <ansi.h>
inherit VRM_SERVER; 
 
#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0

string *unique_rooms = ({
        __DIR__"unique_room/snakehole",
        __DIR__"unique_room/bearlair",
        __DIR__"unique_room/wolfcave",
        __DIR__"unique_room/tigerhill",
        __DIR__"unique_room/dragonland",
});

void create() 
{ 
        //迷宫房间所继承的物件的档案名称。 
        set_inherit_room( ROOM ); 
                        
        //唯一房间
        //set_unique_room( unique_rooms ); 

        //迷宫房间里的怪物。 
        set_maze_npcs( ([
                __DIR__"npc/lev1": random(2),
                __DIR__"npc/lev2": random(2),  
                __DIR__"npc/lev3": !random(3), 
                __DIR__"npc/lev4": !random(4), 
                __DIR__"npc/lev5": !random(5), 
                __DIR__"npc/lev6": !random(6), 
                __DIR__"npc/lev7": !random(7), 
                __DIR__"npc/lev8": !random(8), 
                __DIR__"npc/lev9": !random(9), 
                __DIR__"npc/mob": !random(10), 
        ]) );                   
        
        //不算死亡
        //set_true_death_room(1);

        //迷宫的单边长 
        set_maze_long(11); 
        set_npcs_rate(50);
        //set_npcs_rate(50);
        
        set_lonely_create(1);
                        
        //入口方向(出口在对面) 
        set_entry_dir("east"); 
                        
        //入口与区域的连接方向 
        set_link_entry_dir("east"); 
                        
        //入口与区域的连接档案名 
        set_link_entry_room(__DIR__"enter"); 
                        
        //出口与区域的连接方向 
        set_link_exit_dir("west"); 
                        
        //出口与区域的连接档案名 
        set_link_exit_room(__DIR__"out"); 

        // 迷宫出口的怪物。
        //set_exit_npcs( ([
//                "/d/city/npc/liumang" : 1,
//        ]) );
        // 迷宫入口的怪物。
//        set_entry_npcs( "/d/city/npc/liumang" );

        set_maze_boxs(1);
        set_maze_traps(6); 
                        
        //以下是入口坐标
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //普通房间描述
        set_maze_room_short(HIG"试炼之森"NOR);
                        
        set_maze_room_desc(@LONG
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
LONG); 

        //入口房间短描述 
        set_entry_short(HIR"试炼之森入口"NOR); 
                        
        //入口房间描述 
        set_entry_desc(@LONG
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
LONG);
                        
        //出口房间短描述 
        set_exit_short(HIY"试炼之森中部"NOR); 
                        
        //出口房间描述 
        set_exit_desc(@LONG
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
LONG);

        // 迷宫房间是否为户外房间？ 
        set_outdoors(1);                                                

       // 迷宫刷新时间
        set_maze_refresh(1800); 
        
        // 迷宫摧毁时间
        set_remove_time(3600); 
        //set_remove_time(1); 
} 

string query_my_map(){  return read_file(__DIR__"maze.map");}

