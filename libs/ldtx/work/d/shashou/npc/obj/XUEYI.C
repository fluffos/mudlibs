// xueyin-dao.c  雪饮刀

#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
	set_name("雪饮刀", ({ "xueyin dao", "dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把不平凡的刀，刀长三迟七寸，锋刃无瑕，
		一望就知是一把绝世宝刀。\n");
		set("value", 1000000);
		set("material", "steel");
		set("no_drop", "这样东西不能离开你。\n");
		set("no_get", "这样东西不能离开那儿。\n");
		set("wield_msg", HIY "只听「铮」的一声，雪饮刀脱鞘飞出，自行跃入$N掌中。
瞬时天际间风云变色，电闪雷鸣，弥漫着一片无边杀意。\n" NOR);
		set("unwield_msg", HIY "雪饮刀自$N掌中飞起，在半空中一转，「唰」地跃入刀鞘。\n" NOR);
	}
	init_blade(1000);
	setup();
}
