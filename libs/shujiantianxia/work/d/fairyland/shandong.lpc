// Room: /u/qingyun/jyzj/shandong.c
// Written by qingyun
// Updated by jpei
// Modify By River@SJ

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIB"山洞"NOR);
	set("long", @LONG
这是一个越来越窄的山洞，洞壁皆是颇为坚硬的岩石，刀剑不能开。洞口
刚好能进一人，如果不小心头部则会撞到山石。往里十多丈后，更加狭窄，身
体已不能随意的转动了，如果身体稍大点则不能入内。再进数丈后，忽见前面
透进亮光，似乎另有一翻天地。 
LONG	);

	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_climb", ({"climb", "pa", "zuan"}));
        add_action("do_back", ({ "back", "houtui"}));
}

int do_climb(string arg)
{
	object me = this_player();
        if(me->is_busy() || me->is_fighting())
              return notify_fail("你正忙着呢！\n");
	if (me->query("str") >= 25 && me->query_skill("force", 1) < 150) {
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
	write(HIG"\n你眼前霍然一亮，竟然是一个青翠的山谷！\n\n");
	me->move(__DIR__"cuigu");
        me->start_busy(1);
	message("vision", me->name() + "从洞口钻了出来。\n", environment(me), ({me}));
	return 1;
}

int do_back()
{
        object me = this_player();
        if(me->is_busy() || me->is_fighting())
              return notify_fail("你正忙着呢！\n");
        message_vision("$N眼看不能前行，只能手足并用，慢慢向后退出了山洞。\n",me);
        me->move(__DIR__"dapingtai");
        me->start_busy(1);
	message("vision", me->name() + "从山洞中倒退了出来。\n", environment(me), ({me}));
        return 1;
}
