// Room: /shenlongjiao/zhulin3.c
// kiden 06/08/26
#include <ansi.h>;
#include <room.h>;

inherit ROOM;

void create()
{
        set("short", "竹林");
        set("long", @LONG
好一片郁郁葱葱的竹林，阳光从叶间静静的照下来，地面上斑斑点点。
林间一片寂静，连鸟儿虫儿的叫声似乎都停止了。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "west" : __DIR__"zhulin4",        
                "east" : __DIR__"zhulin2",
                "south" : __DIR__"zhulin"+random(4),
                "north" : __DIR__"zhulin"+random(4),                
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

