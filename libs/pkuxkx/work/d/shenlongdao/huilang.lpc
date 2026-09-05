// Room: /shenlongjiao/huilang.c
// kiden 06/08/25

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "小回廊");
        set("long", @LONG
从厅中屏风的侧面走过，来到了一个小回廊。回廊的中间种了些许花草，不知道那都是些什么花儿呢？
LONG
        );

        set("exits", ([
                "south" : __DIR__"keting",        
                "north" : __DIR__"chufang",
//                "south" : __DIR__"shulin5",
//                "west" : __DIR__"woshi",                
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

