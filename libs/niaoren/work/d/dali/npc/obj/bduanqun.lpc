// bduanqun.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("擺夷短裙", ({ "duan qun" }));
	set("long", "這是一件擺夷短裙。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 250);
		set("armor_prop/armor", 3);
	}
	setup();
}
