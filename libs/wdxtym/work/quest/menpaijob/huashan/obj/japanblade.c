// blade.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("长剑", ({ "xixiajian" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "iron");
                set("long", "这种稍微有点长的长剑，，份量大约十斤重。\n");
                set("wield_msg", "$N抽出一把长剑$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插回腰间。\n");
        }
        init_sword(35);
        setup();
}
