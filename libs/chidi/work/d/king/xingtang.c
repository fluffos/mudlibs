// Room: /city/2.c    by king
// YZC 1995/12/04 
inherit ROOM;
void create()
{
        set("short", "风啸楼刑堂");
        set("long", @LONG
这里有是风啸楼的刑堂，进入这里，你就感到空前的压力，
你一看见刑堂堂主雪儿冷酷的眼神，就不禁打了个寒战，里
面有风啸楼的刑法(xingfa)看看吧.
LONG
        );
        set("item_desc", ([
                "xingfa": "加入风啸楼，永不判教！！。\n",
        ]));
        set("exits", ([
            "west" :__DIR__"datang",
                ]));
        set("objects", ([
        __DIR__"npc/xueer" : 1,
        __DIR__"npc/shizhe" :2
]));
    setup(); 
        replace_program(ROOM);
}

