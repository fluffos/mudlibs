
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("金针", ({ "jin zhen", "zhen" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long",
"这是一根黄澄澄的金针。\n");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", 
"只听见「飕」地一声，$N从发间抽出一根金针夹在姆指和食指间。\n");
                set("unwield_msg", "$N将手中的$n插回发间。\n");
        }
        init_sword(100,2);
        setup();
}
