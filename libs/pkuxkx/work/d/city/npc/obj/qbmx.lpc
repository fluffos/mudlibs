
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("青布棉鞋", ({ "qingbu mianxie", "xie" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "这是一双普通人冬天常穿的青布棉鞋。");
		set("value", 5000);
		set("material", "boots");
             set("armor_prop/dodge", 2);
		//set("shaolin",1);
	}
	setup();
}
