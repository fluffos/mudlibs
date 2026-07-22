// gangzhang.c 钢杖

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("木杖", ({ "mu zhang","muzhang","zhang","staff" }));
	set_weight(1500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long","一根细长的木杖。\n");
		set("value", 200);
            set("material", "mu");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
  	init_staff(5);
	setup();
}
