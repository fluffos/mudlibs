// Room: /d/migong/migong2.c



//inherit VRM_SERVER;

inherit "/adm/daemons/vrm_server";



void create()

{

        // 迷宫房间所继承的物件的档案名称。

        set_inherit_room( ROOM );



        //迷宫房间里的怪物。

        set_maze_npcs(__DIR__"npc/bing1");


        //迷宫的单边长

        set_maze_long(40);



        //入口方向(出口在对面)

        set_entry_dir("east");



        //入口与区域的连接方向

        set_link_entry_dir("east");



        //入口与区域的连接档案名

        set_link_entry_room(__DIR__"xiaocun1/ximen");



        //出口与区域的连接方向

        set_link_exit_dir("west");



        //出口与区域的连接档案名

        set_link_exit_room(__DIR__"bingying2");



        //入口房间短描述

        set_entry_short("小村边");



        //入口房间描述

        set_entry_desc(@LONG

这里是村边的一条小河西岸。东面是座小桥。向西面望

去是莽莽的草原。

LONG

);



        //出口房间短描述

        set_exit_short("兵营口");



        //出口房间描述

        set_exit_desc(@LONG

这里是一条小路，东面是莽莽的草原。向西望去好象是

有个军营。

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
