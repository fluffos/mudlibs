#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
	set_name(HIR"火龙甲"NOR, ({ "huolong jia", "jia" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一件火龙腹部的软鳞制成的宝甲。\n");
		set("material", "copper");
		set("unit", "件");
        set("value",100000);
		set("wear_msg", HIR "$N披上一件火龙甲，周身散发出淡淡的红光。\n" NOR);
		set("remove_msg", HIR "$N将火龙甲卸下，小心翼翼的收在怀里。\n" NOR);
		set("armor_prop/armor", 100);
                set("armor_prop/constitution",2);
	
	}
	setup();
}
