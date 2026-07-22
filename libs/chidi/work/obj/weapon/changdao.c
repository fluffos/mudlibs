#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("长刀", ({ "changdao" ,"dao","blade"}) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 400);
                set("material", "iron");
                set("long", "这是一把比较狭长的刀。\n");
                set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }
        init_blade(35);
        setup();
}
