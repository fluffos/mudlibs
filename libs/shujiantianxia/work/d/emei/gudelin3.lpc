// Room: /d/emei/gudelin.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "古德林" NOR);
	set("long", @LONG
这是一片密密的楠木林，株株秀挺俊拔，枝叶分披上捧，如两手拥佛，据
说有七万株之多，要是不熟悉地形很容易迷路。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([
 	 "east" : __FILE__,
	 "west" : __FILE__,
	 "south" : __DIR__"bailongdong",
	 "north" : __DIR__"gudelin3",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object me;
	me = this_player();
	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");

	if( arg == "zhuang" ) {
	message_vision("$N跳上了梅花桩。\n", me); 
	me->move(__DIR__"muzhuang"); 
        message_vision("$N跳了上来。\n", me);
    return 1;
}
}
