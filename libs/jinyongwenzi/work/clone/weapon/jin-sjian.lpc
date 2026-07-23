#include <weapon.h>
#include <ansi.h>

inherit COMBINED_ITEM;
inherit THROWING;
inherit F_UNIQUE;
void create()
{
	set_name(HIY "金甩箭" NOR, ({ "jin shuaijian", "shuaijian", "jian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", HIY "御赐金箭，是大辽皇帝的传令牌。\n" NOR);
		set("base_value", 50000);
                set("base_unit", "支");
                set("unique", 10);
                set("base_weight", 50);		
	}
	 set_amount(1);
       init_throwing(75);
}
