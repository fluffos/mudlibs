// longsword.c 长鞭
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
set_name(HIM"五"HIY"毒"HIG"回"HIW"凤"HIR"鞭"NOR, ({"wudu shenbian", "bian", "wudushenbian"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", HIY"这是五毒教的神器，据说是用无数的毒物做成的。\n"NOR);
		set("treasure",1);
                set("weapon_prop/dodge", 2);
                set("weapon_prop/parry", 3);
		set("value", 100);
		set("material", "leather");
		set("wield_msg", HIB"只闻到一阵毒腥,$N「唰」的一声抖出一柄黑气蒸腾的$n握在手中。\n"NOR);
		set("unwield_msg", HIY"毒腥消失，$N将手中的$n卷回腰间。\n"NOR);
	}
	init_whip(500);
	setup();
}
int hit_ob(object me, object victim, int damage)
{
if (random(5) >3)
	       victim->apply_condition("snake_poison",
		        (int)victim->query_condition("snake_poison") + 3 );
else if (random(5) >3)
	       victim->apply_condition("wugong_poison",
		        (int)victim->query_condition("wugong_poison") + 3 );
else if (random(5) >3)
	       victim->apply_condition("zhizhu_poison",
		        (int)victim->query_condition("zhizhu_poison") + 3 );
else if (random(5) >3)
	       victim->apply_condition("xiezi_poison",
		        (int)victim->query_condition("xiezi_poison") + 3 );
else 	       
	       victim->apply_condition("chanchu_poison",
		        (int)victim->query_condition("chanchu_poison") + 3 );
        return 0;
}
