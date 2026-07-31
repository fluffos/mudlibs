#include <ansi.h>

inherit ITEM;
mapping *data=({
(["name":"人参果",	"id":"yaocai",	"mw":-1,	]),
(["name":"雪莲花",	"id":"yaocai",	"mw":-1,	]),
(["name":"贝母",	"id":"yaocai",	"mw":-1,	]),
(["name":"冬虫夏草",	"id":"yaocai",	"mw":-1,	]),				
(["name":"红景天",	"id":"yaocai",	"mw":-1,	]),				
(["name":"高原灵芝草",	"id":"yaocai",	"mw":-1,	]),				
(["name":"藏红花",	"id":"yaocai",	"mw":-1,	]),				
(["name":"青稞",	"id":"yaocai",	"mw":-1,	]),					
(["name":"昌都醉梨",	"id":"yaocai",	"mw":-1,	]),					
(["name":"白青梨",	"id":"yaocai",	"mw":-1,	]),						
});

void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 2000);
	}
	setup();
}

int init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	message_vision("$N吃下一个" + name() + "。\n", me);

	if ((me->query("eff_jing") / me->query("max_jing")) < 0.9)
	{
		me->receive_curing("jing", (int)me->query("max_jing") / 50);
	}

	if ((me->query("eff_qi") / me->query("max_qi")) < 0.9)
	{
		me->receive_curing("qi", (int)me->query("max_qi") / 50);
	}

	me->start_busy(2);
	destruct(this_object());
	return 1;
}

