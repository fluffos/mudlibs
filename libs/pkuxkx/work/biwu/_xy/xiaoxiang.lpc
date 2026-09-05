// Room: /clone/misc/xiaoxiang.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 25 2010
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "小巷");
	set("long", @LONG
一条小巷，通向深处，蒙古人撤退之前，在这里布下了剧毒，竟然经年不散。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"southeast" : __DIR__"xx1",
		"northeast" : __DIR__"xiaoxiang2",
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	object me = this_player();
	if (me->query_temp("xiangyang/xxpass"))
		{
			me->add("jing", -200);
			me->add("qi", -200);
			message_vision("$N你连忙屏住呼吸，但还是慢了一步，吸入了少量毒气。\n", me);
		}
	else
		{
			me->unconcious();
		}
	::init();
}


