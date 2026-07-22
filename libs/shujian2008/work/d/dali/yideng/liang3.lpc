// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "石梁");
	set("long", @LONG
只见此处是条宽约尺许的石梁，横架在两座山峰之间，云雾笼罩，望不见
尽处。若是在平地之上，尺许小径又算得了甚么，可是这石梁下临深谷，别说
行走，只望一眼也不免胆战心惊，石梁忽然中断，前(front)后(back) 都各约
有七八尺长的一个缺口。
LONG
	);
	set("outdoors", "桃源县");

	setup();
}

void init()
{
	add_action("do_jump", ({ "yue", "jump", "tiao" }));
}

int do_jump(string arg)
{
	object me = this_player();

	if ( ! arg || ( arg != "front" && arg != "back") ) return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");

	if ( me->query("neili") < 1000)
		return notify_fail("你的内力不够，就这样飞跃断崖可能会有危险。\n");

	if ( arg == "front") {
		message_vision(HIW"\n$N提气快步而行，奔出七八丈，借着一股冲力，飞跃而起，越过了断崖。\n\n"NOR, me);
		me->move(__DIR__"liang4");
		me->add("neili", -1000);
		tell_room(environment(me), me->name() + "纵身从石梁上跃了过来。\n", ({ me }));
 		return 1;
 	}
	if ( arg == "back") {
		message_vision(HIW"\n$N提气快步而行，奔出七八丈，借着一股冲力，飞跃而起，越过了断崖。\n\n"NOR, me);
		me->move(__DIR__"liang2");
		me->add("neili", -1000);
		tell_room(environment(me), me->name() + "纵身从石梁上跃了过来。\n", ({ me }));
 		return 1;
 	}
}
