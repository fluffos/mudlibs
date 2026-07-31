#include <weapon.h>

inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
	set_name("柳叶飞刀", ({ "liuye feidao", "feidao", "liuye" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "叠");
		set("long", "这是一叠适合女子使用的柳叶飞刀。\n");
		set("base_value", 1000);
		set("base_unit", "把");
                set("base_weight", 20);		
	}
	set_amount(20);
       init_throwing(20);
}
