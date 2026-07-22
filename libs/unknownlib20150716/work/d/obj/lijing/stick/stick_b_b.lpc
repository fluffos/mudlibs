#include <weapon.h>
#include <ansi.h>
inherit STICK;
void create()
{
        set_name(HIR"天龙棍"NOR, ({"stick", "gun"}));
        set_weight(7500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("no_put",1);
                set("no_zm",1);
                set("value", 50000);
                set("material", "steel");
		set("long", "一根普通的长棍．\n");
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
                set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
        }
        init_stick(120);
        setup();
}

