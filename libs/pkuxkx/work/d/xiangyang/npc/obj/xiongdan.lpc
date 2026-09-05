#include <ansi.h>
inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(BLK"熊胆"NOR, ({"xiong dan", "dan"}));
	set("unit", "只");
	set("long", "这是一只绿莹莹的熊胆，是制备灵丹妙药的原料。\n");
	set("value", 8000);
	setup();
}

int do_eat(string arg)
{
	if(!id(arg))
		return notify_fail("你要吃什么？\n");
	this_player()->add("neili",300);
	message_vision("$N吃下了一个熊胆，畅快极了。\n",this_player());
	destruct(this_object());
	return 1;
}