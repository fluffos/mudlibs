 // Room: /d/shaolin/zhulin.c
//inherit VRM_SERVER;
inherit "/adm/daemons/vrm_server"; 
void create()
{
        // 迷宫房间所继承的物件的档案名称。
        set_inherit_room( ROOM ); 
        //迷宫房间里的怪物。
        //set_maze_npcs(__DIR__"npc/maque"); 
        //迷宫的单边长
        set_maze_long(6); 
        //入口方向(出口在对面)
        set_entry_dir("east"); 
        //入口与区域的连接方向
        set_link_entry_dir("east"); 
        //入口与区域的连接档案名
        set_link_entry_room(__DIR__"shandao3"); 
        //出口与区域的连接方向
        set_link_exit_dir("west"); 
        //出口与区域的连接档案名
        set_link_exit_room(__DIR__"muwu"); 
        //入口房间短描述
        set_entry_short("山道旁"); 
        //入口房间描述
        set_entry_desc(@LONG
这里是少室山的半山腰，东面是一条陡直的山道，向西面望
去是一片翠绿的竹林，不时传来声声鸟鸣。
LONG
); 
        //出口房间短描述
        set_exit_short("碎石路"); 
        //出口房间描述
        set_exit_desc(@LONG
这里是一条碎石小路，东面是一片翠绿的竹林，不时传来声
声鸟鸣。向西望去隐约一间小木屋，依山傍林，真是一处世外桃
源神仙所在。
LONG
); 
        //迷宫房间的短描述
        set_maze_room_short("竹林"); 
   //迷宫房间的描述，如果有多条描述，制造每个房
        //间的时候会从中随机选择一个。
        set_maze_room_desc(@LONG
这是一片浓密的翠竹林，小鸟的鸣叫声和风吹过竹林的沙沙
声交织成美丽的大自然的旋律。地上杂草丛生说明这里很少有人
来。粗壮的翠竹笔直向上，这就是天下闻名的南翠竹。
LONG
); 
        // 迷宫房间是否为户外房间？
        set_outdoors(1);
}  
