// tiancs.c 冰蚕丝

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "白晶" NOR, ( {"tian jing", "tian", "jing"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "终极炼器材料，这是一块纯白色的水晶，晶莹剔透，无暇的表面射"
		    "出耀眼的光泽。其中仿佛蕴藏着千千万万的生命，生命流动不息，散发出宇宙的力量。这便"
		    "是传说中的至宝——白晶，相传为女娲娘娘所炼制。"NOR"\n" );
		set("spectxt", "制造装备的材料。\n");
		set("unit", "束");
		set("value", 8000000);
		set("yuanbao", 3000);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "天晶" NOR);
		set("can_make", "all");
		set("power_point", 300);
	}
}

int query_autoload() { return 1; }