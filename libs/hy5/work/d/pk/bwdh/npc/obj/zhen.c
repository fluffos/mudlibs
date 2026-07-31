// 针
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
	set_name(HIW "冰魄神针" NOR, ({ "bingbo shenzhen", "zhen", "needle", "shenzhen" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "一枚透明的细针，但散发着阵阵寒气，一看就知道针上喂有剧毒。\n");
		set("value", 200000);
		set("material", "steel");
                set("needle", 1);
                set("weapon_prop/dodge", 2);
                set("wield_msg", "$N打开沙纸，轻轻捻起一枚$n。\n");
		set("unwield_msg", "$N将$n用砂纸包起来，藏回怀中。\n");                
                set("treasure", 1);
                set("poisoned", "bing_poison");
                set("poison_number", 300);
	}
	init_sword(35);
	setup();
}
