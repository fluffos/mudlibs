#include <ansi.h>
inherit ITEM;

void setup()
{}
int cure_ob(string);
void create()
{
	set_name(HIG"菩提子"NOR, ({"puti zi", "zi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", HIG"这是一颗晶莹如玉的菩提子，采自灵山佛祖座前，珍稀无比，
乃万年菩提树之实，功能化百劫，渡千灾，与天地同寿。（奖励）\n"NOR);
		//set("no_drop",HIG"这是侠客梦对你的奖励，怎么可以随便丢弃？\n"NOR);
		//set("no_get", HIG"这是侠客梦对玩家的奖励，却不是谁都拣得起来的？\n"NOR);
		set("value", 0);
		set("medicine", 1);
	}
	setup();
}
	
int cure_ob(object me)
{
	int force_limit, neili_limit, force_skill, add_skill, improve;
	force_limit = me->query_skill("force")*(me->query("con")*2/3);
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);
	/*if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		me->add("max_neili", -(20+random(20)));
		message_vision(HIR "$N又吃下一颗菩提子，只觉得肝肠寸断，五脏欲裂，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else if ( neili_limit <= force_limit  )
	{*/
		me->add("max_neili", 20+random(20));
		me->add("neili", 100);
		message_vision(HIY "$N吃下一颗菩提子，顿然间只觉一股浩荡无比的真气直冲顶门...\n" NOR, this_player());
		//me->apply_condition("bonze_drug", 100);
	//}
	//me->unconcious();
	destruct(this_object());
	return 1;
}