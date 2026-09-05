// Room: /shenlongjiao/xiangfuju.c
// kiden 06/08/25
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
        set("short", HIC"仙福居"NOR);
        set("long", @LONG
这座大屋由竹子搭成，位居平台之上，风光极好，被称作“仙福局”。
这仙福居是教主和夫人休息之所，普通人都难得有机会来这里。
LONG
        );
//        set("outdoors", "shenlongdao");
        set("exits", ([
                "north" : __DIR__"qianlongtang",     
                "south" : __DIR__"pingtai",     
     
        ]));

   set("objects", ([
       ]));
        setup();
        replace_program(ROOM);
}
