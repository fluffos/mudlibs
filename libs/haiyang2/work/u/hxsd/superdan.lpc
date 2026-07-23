// dahuan-dan.c 奖励丹

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
	set_name(MAG"奖励丹"NOR, ({"super dan", "super", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗紫红晶亮的奖励丹。此丹乃给发现大bug的玩家用的，提高功力，灵效无比。\n");
		set("value", 10000);
	}

	set("shaolin",1);
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit;

	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	
	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");

		me->add("per", 1);
		me->add("kar", 1);
		me->add("dex", 1);
		me->add("con", 1);
		me->add("str", 1);
		me->add("int", 1);
		message_vision(HIG "$N吃下一颗奖励丹，只觉得体内真力源源滋生，过紫宫，入泥丸
透十二重楼，遍布奇筋八脉，全身功力顿然提高 !\n" NOR, me);
		message_vision(HIY "$N的容貌加了 !\n" NOR, me);
		message_vision(HIW "$N的身法加了 !\n" NOR, me);
		message_vision(HIR "$N的臂力加了 !\n" NOR, me);
		message_vision(HIG "$N的悟性加了 !\n" NOR, me);	
		message_vision(HIB "$N的根骨加了 !\n" NOR, me);
		message_vision(HIM "$N的福缘加了 !\n" NOR, me);
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}