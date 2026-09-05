// Room: /shenlongjiao/qingshibanlu.c
// kiden 06/08/25
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
        set("short", "青石板路");
        set("long", @LONG
一条青石板路，西侧通向一片郁郁葱葱的竹林。石板路的两旁开满了不知名的小花儿，微风吹过，你闻到一股芬芳。
LONG
        );
        set("outdoors", "shenlongdao");
        set("exits", ([
                "east" : __DIR__"yishidating",     
                "westup" : __DIR__"zhulin1",     
//                "west" : __DIR__"zhulin0",                      
        ]));

   set("objects", ([
//         __DIR__"npc/dizi":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

