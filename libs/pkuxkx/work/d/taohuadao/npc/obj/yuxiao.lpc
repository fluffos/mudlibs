#include <ansi.h>.c
#include <weapon.h>
                                                                               
inherit SWORD;
void create()
{
set_name( GRN "玉箫" NOR, ({"yu xiao", "xiao"}));
        set_weight(200);
if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("long","这是一把发亮的玉箫，是黄药师的随身物品. \n");
                set("value",1000);
                set("material","jade");
                set("music", "shaw");
                set("wield_msg","$N抽出一把$n握在手中. \n");
                set("unwield_msg","$N将手中的$n插回腰间. \n");
        }
        init_sword(50);
        setup();
}
