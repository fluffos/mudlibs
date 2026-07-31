// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("武士刀", ({ "japanblade" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 700);
                set("material", "iron");
                set("long", "这种稍微有点弯的武士刀，小日本喜欢用，份量大约十斤重。\n");
                set("wield_msg", "$N抽出一把武士刀$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插回腰间。\n");
        }
        init_blade(35);
        setup();
}
