// Room: /shenlongjiao/shijie2.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
继续沿着石阶向上走，朝南边看去，一片郁郁葱葱的密林尽收眼底。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
//                "west" : __DIR__"shulin10",        
                "eastup" : __DIR__"shijie3",
//                "south" : __DIR__"shulin5",
                "southdown" : __DIR__"shijie1",                
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

