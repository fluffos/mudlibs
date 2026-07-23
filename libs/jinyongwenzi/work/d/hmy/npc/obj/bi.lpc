#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIM"判官笔"NOR, ({ "Panguan bi", "bi" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "这是一只精工制成的笔，这种笔在黑木崖非常流行。\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一只$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回笔鞘。\n");
	}
	init_sword(30);
	setup();
}
