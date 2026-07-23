#include <weapon.h>
#include <ansi.h>
inherit STICK;
void create()
{
	set_name(HIC"金刚伏魔棍"HIR"("HIY"SOCKET"HIR")"NOR, ({ "stick", "gun"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "steel");
		set("value", 100000);
                set("no_put",1);
                set("no_dzm",1);
                set("no_zm",1);
                set("max_socket", 1);
		set("socketed", 0);
		set("long", "这是一件传说中的神器。\n");
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
                set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
	}
	init_stick(150+random(50));
	setup();
}
