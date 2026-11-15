// udiamond.c 终极钻石


#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW "永恒之" BLINK HIW "钻石" NOR, ({ "ultra diamond" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "这是凝结着众神之祝福的无上钻石。"NOR"\n");
		set("value", 20000);
		set("unit", "颗");
		set("can_be_enchased", 1);
		set("magic/type", "lighting");
		set("magic/power", 220);
		set("armor_prop/per", 12);
		set("wear_msg", HIC "$N" HIC "轻轻地把$n"
		    HIC "戴在头上。"NOR"\n");
		set("remove_msg", HIC "$N" HIC "轻轻地把$n"
		    HIC "从头上摘了下来。"NOR"\n");
	}
	setup();
}

int query_autoload() { return 1; }
