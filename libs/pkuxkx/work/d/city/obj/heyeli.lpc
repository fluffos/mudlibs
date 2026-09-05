// huyao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIG "镶边荷叶笠" NOR , ({ "heye li", "li" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
                set("long", "这是一顶镶边荷叶笠。\n");
		set("value", 150);
		set("material", "cloth");
		set("armor_prop/armor", 3);
		set("female_only",1);
	}
	setup();
}
