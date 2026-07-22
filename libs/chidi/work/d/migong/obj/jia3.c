#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
	set_name(HIR"千年火龙甲"NOR, ({ "huolong jia", "jia" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一件千年火龙腹部的软鳞制成的宝甲。\n");
		set("material", "copper");
		set("unit", "件");
        set("value",100000);
		set("wear_msg", HIR "$N披上一件千年火龙甲，周身环绕着淡淡的红光。\n" NOR);
		set("remove_msg", HIR "$N将千年火龙甲卸下，小心翼翼的收在怀里。\n" NOR);
		set("armor_prop/armor", 2000);
                set("armor_prop/constitution",5);
	
	}
	setup();
}
