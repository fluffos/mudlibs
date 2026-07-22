#include <ansi.h>

inherit COMBINED_ITEM;
inherit F_UNIQUE;
void create()
{
	set_name("含沙射影", ({ "hansha sheying", "hansha" }));
	if (clonep()) set_default_object(__FILE__);
	else {
		set("long", "一个黑色的小铁匣子，好象就是让人闻风丧胆的含沙射影。\n");
                set("value", 1);
                set("unique", 1);
		set("unit", "个");
                set("material", "steel");
                set("treasure",1);
		set("base_value", 10000);
		set("base_unit", "次");
		set("base_weight", 5000);
	}
	set_amount(1);
}

void init()
{
	if (environment() == this_player())
		add_action("do_shoot", "shoot");
}

int do_shoot(string arg)
{
	object me = this_object();
	object ob = this_player();
	object victim;

	if (!arg) return 0;
	victim = present(arg, environment(ob));
	if (!victim || !living(victim)) return notify_fail("你要对谁下手？\n");
	if (victim->query_condition("man_poison"))
		return notify_fail(victim->name()+"已经中毒了。\n");
	write("你悄悄掀动"+name()+"的机关，一蓬绝细钢针急射而出，尽数打在"+victim->name()+"身上。\n");
	tell_room(environment(ob), ob->name()+"悄悄掀动"+name()
		+"的机关，一蓬绝细钢针急射而出，尽数打在"+victim->name()+"身上。\n", ({ ob, victim }));
	victim->set_temp("last_damage_from", "中含沙射影");
        victim->die();
	add_amount(-1);
	return 1;
}
