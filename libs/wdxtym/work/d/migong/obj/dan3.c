inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	}
void create()
{
	set_name(HIR"火龙丹"NOR, ({"huolong dan", "dan"}));
	set("unit", "颗");
	set("long", "这是一颗火龙修炼以久的内丹。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="dan")
	{
		me->add("max_neili",80);
                		
                message_vision(HIR"$N吃下一颗火龙丹，只觉一股火热之气直冲丹田，丹田内力源源而生!\n"NOR,me);

		destruct(this_object());
	}
	return 1;
}
