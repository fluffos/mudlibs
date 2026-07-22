// gangzhang.c 钢杖

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("钢杖", ({ "gang zhang","gangzhang","zhang","staff" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long","粗长的钢杖，雕琢着精美的花纹。\n");
		set("value", 3000);
            set("material", "gang");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
  	init_staff(25);
	setup();
}
