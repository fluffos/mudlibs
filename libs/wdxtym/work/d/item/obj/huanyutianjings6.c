
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "永恒源石" NOR, ( {"tian jings6", "tians6", "jings6"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "终极炼器材料，神魔晶石的终极进化版！"NOR"\n" );
		set("spectxt", "制造装备的材料。\n");
		set("unit", "颗");
		set("value", 1);
		set("tianji1", 200);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "永恒" NOR);
		set("can_make", "all");
		set("power_point", 5000);
	}
}

int query_autoload() { return 1; }