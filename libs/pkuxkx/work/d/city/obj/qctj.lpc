// huyao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("青绸方巾", ({ "qingchou fangjin", "fangjin" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
                set("long", "这是一块书生们常用的头巾。\n");
		set("value", 10000);
		set("material", "head");
		set("armor_prop/armor", 1);
		
	}
	setup();
}
