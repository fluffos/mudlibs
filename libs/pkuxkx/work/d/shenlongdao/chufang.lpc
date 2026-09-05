// Room: /shenlongjiao/chufang.c
// kiden 06/08/25

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
走进屋子，你就闻到一股饭香，一个小丫头正在做饭。也许你可以讨点什么吃一下。
厨房的北边有一个小竹门，不知道门外又是什么呢？
LONG
        );

        set("exits", ([
                "south" : __DIR__"huilang",        
                "north" : __DIR__"shanquan",
//                "south" : __DIR__"shulin5",
//                "west" : __DIR__"woshi",                
        ]));

   set("objects", ([
         __DIR__"npc/yatou":1,
//        __DIR__"npc/rascal":1,
       ]));
create_door("north", "竹门", "south", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}

