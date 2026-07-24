// 药材

inherit ITEM;
#include <ansi.h>
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(order[random(13)]+"北沙参"NOR, ({"zhong yao"}));
	set_weight(800);
	set("vegetable", 16);
	set("value", 30+random(121));
	set("nostrum", 32);
	set("unit", "根");
	set("long", "这是一种药材。\n");
	set("pour_type", "1");set("yaocao",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	me->add("food",20);
	me->add("water",20);
	write("你三口两口把"+this_object()->query("name")+"吃了下去。\n");
	destruct(this_object());
	return 1;
}
