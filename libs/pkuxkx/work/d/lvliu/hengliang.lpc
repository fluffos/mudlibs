#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "横梁上");
	set("long","横梁上光线昏暗，只能看到前方有个朝下的洞口透着灯光。你沿着横梁爬行了一
会儿，到了洞口上面，往下望去。下面似乎是个偏僻的小厅，堆放着一些杂物，还有
两个武士在喝酒闲聊。洞口离地面不高，也许可以跳下去(jump)。\n"NOR);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();
	message_vision(HIW"$N" HIW "长吸了口气，向小洞跳了下去。\n"NOR, me);
	me->move( __DIR__"jiuzhou0");
	message_vision(HIW"\n人影一晃，$N" HIW "从屋顶上方跳了下来。\n\n"NOR, me);
	return 1;
}