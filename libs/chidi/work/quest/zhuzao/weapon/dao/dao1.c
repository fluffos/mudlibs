// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(HIC"淬火钢刀"NOR, ({ "gang dao","dao"}) );   
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄亮晃晃的钢刀，经过淬火处理，看起来很是锋利。\n"); 
                set("value", 10000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        }
        init_blade(100);
        setup();
}
