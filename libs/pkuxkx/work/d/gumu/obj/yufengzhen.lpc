//yufengzhen.c
#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name(GRN"玉蜂针"NOR, ({ "yufeng zhen", "zhen"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("unit","把");
		set("base_unit", "根");
           
                set("long", "这是一把非常细的银针，里面夹着少许黄金。\n");

                set("material", "steel");
                set("base_weight", 10);
                set("wield_msg", "$N拿出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放入口袋中。\n");
        }
         set_amount(1);
        init_throwing(30); 
    setup();
}
