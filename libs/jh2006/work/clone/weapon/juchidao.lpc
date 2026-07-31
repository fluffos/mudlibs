// juchidao.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( "锯齿刀", ({  "juchi dao" , "blade" , "dao"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把长刀，刀背处开出了一溜锋利的锯齿，相对于普通钢刀攻击力更大。\n");
                set("value", 1000);
                set("material", "steel");
              }
        init_blade(40);
        setup();
}
