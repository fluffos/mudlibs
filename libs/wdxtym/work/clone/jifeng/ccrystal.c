// ccrystal.c Ë®¾§²ÐÆ¬

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIM "Ë®¾§²ÐÆ¬" NOR, ({ "chipped crystal" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM "Ò»Æ¬·ÛÉ«µÄË®¾§ËéÆ¬¡£"NOR"\n");
		set("base_value", 20000);
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("base_weight", 1);
		set("base_unit", "Æ¬");
		set("can_be_enchased", "/clone/gift/crystal");
		set("enchased_need", 3);
		set("jifeng", 42);
		set("magic/type", "magic");
		set("magic/power", 30);
	}
	set_amount(1);
	setup();
}
