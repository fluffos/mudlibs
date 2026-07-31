#include <weapon.h>
#include <ansi.h>
inherit STICK;
void create()
{
        set_name(HIY"魂招魄引"NOR, ({"stick", "gun"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("no_put",1);
                set("no_zm",1);
                set("value", 200000);
                set("material", "steel");
                set("weapon_prop/intelligence", 2);
		set("long", "这是一件上古宝物。\n");
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
                set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
        }
        init_stick(140);
        setup();
}

