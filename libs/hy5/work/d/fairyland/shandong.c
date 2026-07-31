// Room: /u/qingyun/jyzj/shandong.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
这是一个越来越窄的山洞，洞壁皆是颇为坚硬的岩石，刀剑不能开。洞口
刚好能进一人，如果不小心头部则会撞到山石。往里十多丈后，更加狭窄，身
体已不能随意的转动了，如果身体稍大点则不能入内。再进数丈后，忽见前面
透进亮光，似乎另有一翻天地。 
LONG	);
	set("exits", ([
		"out" : __DIR__"dapingtai",
	]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
  add_action("do_climb", ({"climb", "pa", "zuan"}));
}

int do_climb(string arg)
{
	object me = this_player();

	if (me->query("str") >= 25 && me->query_skill("force",1) < 80) {
		write(HIY"\n你运劲双肩，手脚兼用，向前钻去，但孔道确实太小，不能进去。\n\n"NOR);
		write(HIR"\n你只觉得整个身体被嵌在孔中，不能移动了。\n"NOR);
		me->start_busy(10);
		return 1;
	}
	if (me->query("str") < 25) {
		message("vision", me->name() + "加速向前钻去。\n", environment(me), ({me}));
		write("你手足兼用，迅速向有光亮之处钻去。\n");
	}
	else {
		message_vision("$N运起内功，硬生生地向前钻去。\n", me);
	}
	write("眼前霍然一亮，竟然是一个青翠的山谷！\n");
	me->move(__DIR__"cuigu");
	message("vision", me->name() + "从洞口钻了出来。\n", environment(me), ({me}));
	return 1;
}
