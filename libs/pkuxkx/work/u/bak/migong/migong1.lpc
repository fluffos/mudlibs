// Room: /d/shaolin/zhulin.c



//inherit VRM_SERVER;

inherit "/adm/daemons/vrm_server";



void create()

{

        // 迷宫房间所继承的物件的档案名称。

        set_inherit_room( ROOM );



        //迷宫房间里的怪物。

        set_maze_npcs(__DIR__"npc/bing");


        //迷宫的单边长

        set_maze_long(30);



        //入口方向(出口在对面)

        set_entry_dir("east");



        //入口与区域的连接方向

        set_link_entry_dir("east");



        //入口与区域的连接档案名

        set_link_entry_room(__DIR__"westr5");



        //出口与区域的连接方向

        set_link_exit_dir("west");



        //出口与区域的连接档案名

        set_link_exit_room(__DIR__"bingying1");



        //入口房间短描述

        set_entry_short("山道旁");



        //入口房间描述

        set_entry_desc(@LONG

这里是雪山的半山腰，东面是一条陡直的山道，向西面望

去是一片莽莽草原，不时传来喊杀声。

LONG

);



        //出口房间短描述

        set_exit_short("小河边");



        //出口房间描述

        set_exit_desc(@LONG

这里是一条小河，东面是一望无际的草原。向西望去

是座小桥。桥上有几个蒙古兵正在盘查。

LONG

);



        //迷宫房间的短描述

        set_maze_room_short("草原");



        //迷宫房间的描述，如果有多条描述，制造每个房

        //间的时候会从中随机选择一个。

        set_maze_room_desc(@LONG

这是一望无际的大草原。齐腰身的草里，经常有兔子

跑出来。正当你四下观望时，突然，从草丛中出来个

蒙古兵向你杀来。

LONG

);



        // 迷宫房间是否为户外房间？

        set_outdoors(1);

}
