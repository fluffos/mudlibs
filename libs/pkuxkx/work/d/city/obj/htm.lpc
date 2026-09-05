// huyao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("虎头帽", ({ "hutou mao", "mao" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
                set("long", "这是一顶小孩子们常戴的虎头帽。\n");
		set("value", 10000);
		set("material", "head");
				
	}
	setup();
}
