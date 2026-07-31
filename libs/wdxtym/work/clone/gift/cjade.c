// cjade.c Ù‰¥‰≤–∆¨

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIG "Ù‰¥‰≤–∆¨" NOR, ({ "chipped jade" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIG "“ª∆¨æß”®ÃﬁÕ∏¡£µƒÙ‰¥‰ÀÈ∆¨°£"NOR"\n");
		set("base_value", 20000);
		set("base_unit", "∆¨");
		set("base_weight", 1);
		set("can_be_enchased", __DIR__"jade");
		set("enchased_need", 3);
		set("magic/type", "cold");
		set("magic/power", 30);
	}
	set_amount(1);
	setup();
}
