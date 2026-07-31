// Room: /d/jinghai/moon13.c

inherit ROOM;

void create()
{
	set("short", "山寨伙房");
	set("long", @LONG
巨大的木柱撑起这个可以容纳几十个人的伙房，屋里放着几
排长桌，几个外出办事误了餐点的红巾水勇正在桌边就餐，看来
他们的伙食不太好，大家都端着碗猛扒糯米饭。你要是渴了可以
在这舀(drink)水喝。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"moon6",
]));

        set("objects", ([
            __DIR__"obj/mifan"       : 10,
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
