// Room: /shenlongjiao/shijie1.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
沿着山脚边的石阶向上攀行，看着路边美丽的花草，听着丛林里的虫儿发出的叫声，不禁让你觉得心旷神怡。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
//                "west" : __DIR__"shulin10",        
                "northup" : __DIR__"shijie2",
//                "south" : __DIR__"shulin5",
                "southdown" : __DIR__"shanjiao",                
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

