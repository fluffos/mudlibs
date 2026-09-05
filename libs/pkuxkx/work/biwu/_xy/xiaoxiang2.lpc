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
		"southwest" : __DIR__"xiaoxiang",
		"northeast" : __DIR__"xiaoxiang3",
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
			message_vision("$N你心道不好，此地毒性更加浓烈，你忙运内功抵抗。\n", me);
			if (me->query("neili")>5000)
				{
					me->add("neili",-(random(5000)));
				}
			else
				{
					me->set("neili",0);
				}
		
		}
	else
		{
			me->unconcious();
		}
	::init();
}


