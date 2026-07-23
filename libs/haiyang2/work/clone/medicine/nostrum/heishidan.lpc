// heishidan.c 黑石玉洞丹

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(HIB"黑石玉洞丹"NOR, ({"heishi yudongdan", "dan"}));
	set("unit", "粒");
	set("vegetable", 51);
	set("nostrum", 80);
	set("level", 100);
	set("lev", 3+random(5));
	set("value", 10000);
	set("long", "这是一粒能解百毒的黑石玉洞丹。\n");
	set("pour_type", "1");

	setup();
}

int do_eat(string arg)
{
int exp,pot,i;
	object me = this_player();

exp = 888+random(888);
pot = exp/2;

	if (!id(arg)) return notify_fail("你要吃什么？\n");
	if (!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");

	message_vision(HIG"$N吃下一粒黑石玉洞丹，只觉一股苦涩的滋味直透心臆。\n" NOR, me);
       me->add("combat_exp",exp);
       me->add("potential",pot);
message_vision("$N获得了"+chinese_number(exp)+"点经验,"+chinese_number(pot)+"点潜能!\n", me);
i=1+random(3);
if (random(12)==0 || wizardp(me))
{
if ( me->query("4zhuan") || me->query("5zhuan") )
{
if (me->query("expmax",1) < 1)
{
me->set("expmax",i);
}
else
{
me->add("expmax",i);
}       
message_vision(HIR"$N获得了"+chinese_number(i)+"点成长上限!\n"NOR, me);
}       
}
	if (me->query_condition("chanchu_poison"))
		me->apply_condition("chanchu_poison",0);
	if (me->query_condition("scorpion_poison"))
		me->apply_condition("scorpion_poison",0);
	if (me->query_condition("slumber_drug"))
		me->apply_condition("slumber_drug",0);
	if (me->query_condition("snake_poison"))
		me->apply_condition("snake_poison",0);
	if (me->query_condition("xiezi_poison"))
		me->apply_condition("xiezi_poison",0);
	if (me->query_condition("zhizhu_poison"))
		me->apply_condition("zhizhu_poison",0);
	if (me->query_condition("zhua_poison"))
		me->apply_condition("zhua_poison",0);
	destruct(this_object());
	me->start_busy(2);
	return 1;
}
