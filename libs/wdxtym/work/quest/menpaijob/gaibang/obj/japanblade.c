// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("蒙古刀", ({ "menggublade" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "iron");
                set("long", "这种稍微有点弯的蒙古刀，，份量大约十斤重。\n");
                set("wield_msg", "$N抽出一把蒙古刀$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插回腰间。\n");
        }
        init_blade(35);
        setup();
}
