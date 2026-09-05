// shortsword.c 长剑

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("大扫把", ({ "da saoba", "sao ba" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄很大的扫把。\n");
		set("value", 5);
		set("material", "wood");
		set("wield_msg", "$N双手把一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n扛在肩上。\n");
	}
	init_sword(1);
	setup();
}
