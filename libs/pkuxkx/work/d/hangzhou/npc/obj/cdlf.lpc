// cdlf.c  绸缎礼服  by hubo

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("绸缎礼服", ({ "chouduan lifu", "lifu" }));
	set("long", "这是一件珍贵的绸缎礼服。\n");
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
                set("value", 9000);
		set("armor_prop/armor", 1);
	}
	setup();
}
