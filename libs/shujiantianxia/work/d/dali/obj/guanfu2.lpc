#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("便服", ({ "bianfu", "cloth" }));
	set("long", "这是一件王府的家人常穿的黑色便服。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 0);
		set("armor_prop/armor", 5);
	}
	setup();
}
