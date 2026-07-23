
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name("铜箫", ({ "tong xiao","tong","xiao" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把铜箫，上面刻着一龙一凤。\n");
		set("value", 2000);
		set("material", "steel");
	}
	init_sword(170);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插回腰间。\n");

	setup();
}
