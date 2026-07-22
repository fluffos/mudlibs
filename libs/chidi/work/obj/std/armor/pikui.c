// huyao.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("皮盔" , ({"pi kui","pikui","kui"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
                set("long", "这是一顶牛皮制成的头盔，用以保护头部。\n");
	set("value",500);
		set("material", "pi");
		set("armor_prop/armor", 5);
	}
	setup();
}
