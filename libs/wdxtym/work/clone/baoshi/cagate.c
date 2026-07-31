// cagate.c Âêè§²ĞÆ¬

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIR "Âêè§²ĞÆ¬" NOR, ({ "chipped agate" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIR "Ò»Æ¬µÄÂêè§ËéÆ¬£¬·¢³öÎ¢ÈõµÄºì¹â¡£"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("base_unit", "¿é");
		set("can_be_enchased", __DIR__"agate");
		set("enchased_need", 3);
		set("magic/type", "fire");
		set("magic/power", 50);
	}
	set_amount(1);
	setup();
}
