// gangzhang.c 钢杖

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("六道轮回鞭", ({ "lunhui whip" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是佛本至宝 六道轮回鞭。\n");
		set("value", 5000);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
  	init_whip(625);
	setup();
}
