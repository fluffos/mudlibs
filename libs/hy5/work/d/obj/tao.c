inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	}
void create()
{
	set_name(HIR"仙桃"NOR, ({"xian tao", "tao"}));
	set("unit", "只");
	set("long", "这是昆仑绝顶出产的仙桃，极为珍贵。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="tao")
	{
		me->add("max_neili",5);
		me->set("neili",me->query("max_neili"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("eff_qi"));
                message_vision("$N吃下一颗仙桃，只觉得精神健旺，气血充盈，体内真力源源滋生!\n",me);

		destruct(this_object());
	}
	return 1;
}
