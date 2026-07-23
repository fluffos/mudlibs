// Last Modified by winder on Sep. 12 2001
// xuezhonglian.c 雪中莲

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW "雪中莲" NOR, ({"xuezhong lian", "lian"}));
	set("unit", "朵");
	set("value", 10000);
	set("lev", 3+random(5));
	set("long","这是一朵生长在雪山上的雪莲，它洁白的花瓣上附着几颗晶莹的露珠，正散发着淡淡的幽香。\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit;
int exp,pot,i;
	object me = this_player();

exp = 888+random(888);
pot = exp/2;

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");

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
	me->add("max_neili", random(10));
	message_vision( HIG"$N吃下一朵"NOR, me);
	message_vision( HIW"雪中莲"NOR, me);
	message_vision( HIG"，顿时觉得灵台一清，一股热气直穿任督二脉，头上冒出丝丝热气。\n"NOR, me);
	destruct(this_object());
	return 1;
}
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
	remove_call_out("destlian");
	call_out("destlian", 10);
}
void destlian()
{
	message_vision("$N慢慢干枯萎缩，一会就溶化消失掉了。\n", this_object());
	destruct(this_object());
}

