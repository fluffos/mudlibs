// by bugbug & alading @ 缥缈水云间, 2003-4-5
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIM"鸯刀"NOR, ({"yang dao", "blade", "dao"}));
        set_weight(18000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把精光耀眼的短刀，发着阴渗渗的杀气，刀刃上刻着“无敌”两字！\n");
                set("value", 1500);
                set("material", "crimsonsteel");
                set("wield_msg","$N「唰」地一声抽出一把$n握在手中！\n");
                set("unwield_msg","$N将手中的$n插入腰间，嘴角露出一丝笑意．\n");
        }
        init_blade(165);
        setup();
}



