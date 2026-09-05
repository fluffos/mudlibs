// zaohua-wan.c 造化丸

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("造化丸", ({"zaohua wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", GRN"这是一颗大若龙眼的造化丸，整个药丸散发出一股
浓郁的药香，该药丸据说神奇无比，有参天地造化之奇效，乃逍遥派不传之秘\n");
		set("value", 500000);
	}
	setup();
}

int do_eat(string arg)
{
object me;
  me=this_player();

	
	if (!id(arg))
	return notify_fail("你要吃什么？\n");


	
		me->delete_skill("huagong-dafa");
            me->set_skill("beiming-shengong",150);

		message_vision(HIY "$N吃下一颗造化丸，顿觉得浑身上下如同刀割一般，$N大叫一声，便晕了过去.....\n" NOR, this_player());


	me->unconcious();
	destruct(this_object());
	return 1;
}

