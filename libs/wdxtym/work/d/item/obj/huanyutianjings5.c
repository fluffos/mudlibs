
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "神魔晶石" NOR, ( {"tian jings5", "tians5", "jings5"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "终极炼器材料，传言此乃救赎圣晶结合了神明与魔鬼的力量变化而成！"NOR"\n" );
		set("spectxt", "制造装备的材料。\n");
		set("unit", "颗");
		set("value", 100);
		set("tianji1", 150);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "神魔" NOR);
		set("can_make", "all");
		set("power_point", 4000);
	}
}

int query_autoload() { return 1; }