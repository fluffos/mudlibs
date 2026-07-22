// rope.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "皮鞭", ({ "pi bian","pibian","bian","whip" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 500);
                set("material", "pi");
        }
        init_whip(10);

        set("wield_msg", "$N从腰间抽出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");

        setup();
}

