// pifeng

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name("披风", ({ "pifeng",}));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "天蚕丝制成的披风，华美绝伦\n");
		set("material", "cloth");
		set("unit", "件");
                set("value", 500000);
                set("wear_msg", HIY "$N哗的一下将天蚕披风披在身上。\n" NOR);
                set("remove_msg", HIY "$N将天蚕披风从身上脱了下来。\n" NOR);
                set("armor_prop/armor", 400);
	}
	setup();
}
