#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIG"寒月斩"NOR, ({"hanyue blade", "blade"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把淡青色的圆月弯刀，发着阴渗渗的杀气．\n");
                set("value", 1500);
                set("material", "ice");
                set("wield_msg",
"$N「唰」地一声抽出一把$n握在手中，眼中闪过一道寒光！\n");
                set("unwield_msg",
"$N将手中的$n插入腰间，嘴角露出一丝笑意．\n");
        set("weapon_prop/courage", 10);

        }
        init_blade(880);
        setup();
}

