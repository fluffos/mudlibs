// Room: /open/stst/sazai/lianwu.c

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
        这里是野羊寨的练武场。场地十分宽敞，场子四周有许多木桩，都
已经是体无完肤了，平时无事，寨里的兄弟们就在此练武，你可以和他们切
磋切磋。练武场的北边是到大厅的路，南边是出寨的路。

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lu2",
  "north" : __DIR__"lu3",
]));
	set("objects",([
		__DIR__"npc/toumu1":1,
		__DIR__"npc/toumu2":1,
]));

        setup();
        replace_program(ROOM);
}

