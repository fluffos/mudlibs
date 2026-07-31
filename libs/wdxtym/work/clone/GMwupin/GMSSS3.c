
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "真龙骸骨" NOR, ( {"zhenl gu"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "这是一条真龙的尸骨，这可是炼器的无上材料！"NOR"\n" );
		set("spectxt", "制造装备的材料。\n");
		set("unit", "颗");
		set("value", 100);
		set("yuanbao", 100);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIR "真龙" NOR);
		set("can_make", "all");
		set("power_point", 15000);
	}
}

int query_autoload() { return 1; }