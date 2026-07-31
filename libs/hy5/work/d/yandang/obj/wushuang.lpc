#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIM"无双神剑"NOR, ({ "wushuang_jian","sword"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把"+HIM"无双神剑"+NOR+",当世七大名剑之一。\n");
		set("value", 1000);
		set("material", "steel");
	}
	init_sword(880);


      set("wield_msg",
"$N从剑鞘中拔出"+HIM+"无双神剑.\n"NOR);
	set("unwield_msg","$N把"+HIM+"无双神剑"+NOR+"插入腰间剑鞘.\n");
       setup();
}
