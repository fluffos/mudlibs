// Room: /shenlongjiao/shijie3.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
再前行了几个台阶，视野更加开阔，朝东边看去，那海天一线就在眼前。
清风吹过，你似乎还可以闻到海水的味道，你不走熏熏欲醉。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
//                "west" : __DIR__"shulin10",        
                "north" : __DIR__"shanyao",
//                "south" : __DIR__"shulin5",
                "westdown" : __DIR__"shijie2",                
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

