// woodsword.c
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("「尺娘」", ({ "syndicator" }));
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                
                set("long",
                        "这是一把长约四寸的匕首，刃上用精细的雕工镂空出一个美貌\n"
                        "女子的脸，奇特的是这女子的表情像是伸出舌头在舔嘴边的血\n"
                        "迹，匕首的柄奇短，只能用两只手指捏住。\n");
                set("unit", "把");
                set("value", 600);
                set("material", "steel");
                set("wield_msg", "$N「刷」地一声从怀里掏出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入怀里。\n");
                set("weapon_prop/intelligence", 3);
        }
        init_dagger(35);
        setup();
}
