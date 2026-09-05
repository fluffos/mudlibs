// /d/baituo/npc/obj/dakandao.c
//-- by bibi--
#include <weapon.h> 
inherit BLADE;
void create()
{
        set_name("大砍刀", ({ "da kandao", "kandao", "blade" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 3000);
                set("material", "iron");
                set("long", "这是一把铁铸的大砍刀，适合在马上使用。\n");
                set("wield_msg", "只听呼的一声，$N抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n放下。\n");
        }
        init_blade(30);
        setup();
}
