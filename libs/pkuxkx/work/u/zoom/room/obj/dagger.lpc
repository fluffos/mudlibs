// dagger.c 匕首

#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("匕首", ({ "bi shou", "dagger" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
                set("long", "这是一柄普通的匕首。\n");
		set("value", 1500);
		set("material", "steel");
                set("wield_msg", "$N「唰」的一声从小腿旁抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回裤腿中。\n");
	}
        init_dagger(25);
	setup();
}
