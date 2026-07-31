// gangzhang.c 钢杖

#include <weapon.h>
inherit CLUB;

void create()
{
	set_name("释厄佛棍", ({ "fo club" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是佛本至宝 释厄佛棍。\n");
		set("value", 5000);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n收回。\n");
	}
  	init_club(725);
	setup();
}
