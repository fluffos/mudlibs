// shuhou.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "树丛后");
	set("long", @LONG
这里光秃秃的一大片石壁，爬满藤蔓，但见石壁平整异常，宛然一面铜镜，
只是比湖西的山壁小了许多，再细看那石壁，平整光滑，别无他异。
LONG
	);
        set("exits", ([
		"out" : __DIR__"shulin1",
	]));
        set("outdoors", "大理");
	setup();
}

void init()
{
        add_action("do_down", "tear");
        add_action("do_down", "si");
}

int do_down(string arg)
{
	object me = this_player();
        if (!arg || arg!="teng") return 0;
        message_vision("$N把石壁上的藤蔓撕得干干净净，走向后面。\n" , me);
        me->move(__DIR__"shibi");
        return 1; 
}
