// Room: /d/jinghai/wm16.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
厨房里打扫的很干净。中间有两排大桌子，足可以坐下一百
二十多人。锅里沽嘟嘟不知煮着什么东西，冒出阵阵香气，令人
垂涎欲滴。几个丫鬟正在收拾蔬菜。一个小厮来来回回地跑个不
停，大概在打下手。你要是渴了可以在这舀(drink)水喝。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"wm14",
]));
        set("objects", ([
            __DIR__"obj/mifan"       : 3,
        ]));



	setup();
}
void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me = this_player();

        if( (int)me->query("water") >= (int)me->max_water_capacity() )
                return notify_fail("你已经再也喝不下一滴水了。\n");

        message_vision("$N在水缸边用杯子舀起水喝了几口。\n", me);
        me->add("water", 20);
        return 1;
}

