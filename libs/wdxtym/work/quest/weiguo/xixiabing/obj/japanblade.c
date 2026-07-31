// blade.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("西夏剑", ({ "xixiajian" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 700);
                set("material", "iron");
                set("long", "这种稍微有点长的西夏剑，，份量大约十斤重。\n");
                set("wield_msg", "$N抽出一把西夏剑$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插回腰间。\n");
        }
        init_sword(35);
        setup();
}
