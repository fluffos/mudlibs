// Room: /shenlongjiao/shanjiao.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "山脚");
        set("long", @LONG
竹林边上有一片开阔的平地，几间小竹屋疏落有致地点缀其中。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "west" : __DIR__"shulin10",        
                "northup" : __DIR__"shijie1",
                "south" : __DIR__"shulin"+random(10),
                "east" : __DIR__"zhuwu",                
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

