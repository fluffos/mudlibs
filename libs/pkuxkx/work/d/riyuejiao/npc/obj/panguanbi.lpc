// panguanbi	判官笔

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("判官笔", ({ "panguan bi", "bi" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "这是一杆精钢所铸的判官笔，长一尺六寸，判官笔笔头上缚有一束沾过墨的羊毛，恰如是一枝写字用的大笔。\n");
		set("value", 500);
		set("material", "steel");
		set("wield_msg", "$N抽出一杆$n，握在手中作为武器。\n");
		set("unwield_msg", "$N将手中的$n收入囊中。\n");
                set("moshui", 20+random(20));
		set("no_store", 1);
		set("no_sell", 1);
		set("no_pawn", 1);
	}
	init_sword(15);
	setup();
}
