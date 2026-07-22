
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"金佛"NOR, ({ "jin fo", "fo" }));
        set_weight(1500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "尊");
                set("long", "一尊金佛，正咧开了嘴巴笑。\n");
                set("value", 10000);
		set("material", "gold");
	}
	setup();
}
