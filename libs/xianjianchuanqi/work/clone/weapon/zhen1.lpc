// 针

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(BLU "蓝玉毒针" NOR, ({ "lanyu duzhen", "zhen", "needle", "duzhen" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "一枚普通的细针，但针尖闪着蓝色的光亮，喂有剧毒。\n");
		set("value", 50000);
                set("unique", 2);
                set("needle", 1);
		set("material", "steel");
                set("weapon_prop/dodge", 2);
		set("wield_msg", "$N打开沙纸，轻轻捻起一枚$n。\n");
		set("unwield_msg", "$N将$n用砂纸包起来，藏回怀中。\n");
                set("poisoned", "xx_poison");
                set("poison_number", 300);
                set("treasure", 1);
	}
	init_sword(35);
	setup();
}