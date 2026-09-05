// Room: /shenlongjiao/shulin10.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
只跨出一步，眼前又有七八条蛇挡路，全身血也似红，长舌吞吐，嗤嗤发声。
这些蛇都是头作三角，显具剧毒。
一条毒蛇从树上挂了下来，马上就要缠住你的头颈。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "west" : __DIR__"shulin9",        
                "east" : __DIR__"shanjiao",
                "south" : __DIR__"shulin1",
                "north" : __DIR__"shulin1",                
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

