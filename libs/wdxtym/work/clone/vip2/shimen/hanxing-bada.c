#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "《寒星八打》" NOR, ({ "hanxing bada"}));
	set_weight(300);

	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long", "这是一本《寒星八打》的秘籍，使用它后会获得50级寒星八打。\n");
		set("gongxian",10000);
		set("value", 100);
		set("no_give","你的劳动成果，不要给别人。\n");
		set("no_drop","这东西不能丢！！\n");
		set("no_put",1);
		set("no_steal",1);
		set("no_sell", "这是无价秘籍！！\n");
		set("material", "paper");
		set("only_do_effect",1);
	}
	setup();
}

int do_effect(object me)
{
	string skill;
	skill = "hanxing-bada";
	if (me->query_skill(skill,1))
	{
		tell_object(me,"你已经掌握这个技能了，无需再次学习！\n");
		return 1;
	}

	if (!SKILL_D(skill)->valid_learn(me))
	{
		tell_object(me,"你目前的能力不足以掌握此项技能！("+skill+")\n");
		return 1;
	}

	me->set_skill(skill,50);
	tell_object(me,HIY"你掌握了50级" + to_chinese(skill) + "。\n"NOR);

	destruct(this_object());

	return 1;
}

int query_autoload() { return 1; }