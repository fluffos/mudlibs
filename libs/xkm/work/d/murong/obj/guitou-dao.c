//Cracked by Roath
// guitou-dao.c  鬼头刀
// Sure 2001.5

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(CYN"鬼头刀"NOR, ({ "guitou dao","guitou","dao" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把明晃晃的鬼头刀，刀背上吱牙裂嘴地像只鬼脑袋，一摇“哗棱棱”直响。\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N「哗棱棱」的一声举起一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放下。\n");
        }
        init_blade(100);
        setup();
}
