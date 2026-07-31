// xuedao.c 血刀
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( HIR"血刀"NOR , ({ "xue dao", "xuedao","blade","dao"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIR"这把缅刀极轻极薄，刃锋上全是暗红之色，血光隐隐，极是可怖。\n"NOR);
                set("value", 1000);
                set("rigidity", 10);
                set("sharpness", 5);
                set("weapon_prop/dodge", 5);
                set("wield_maxneili", 1100);
                set("treasure",1);
                set("material", "steel");
                set("wield_msg", HIR
"$N伸手腰间，一抖之下，手中已多了一柄软软的缅刀。刀身不住颤动，宛然一条活的蛇一般。\n"NOR);
                set("unwield_msg",HIR" $N轻轻的摸了摸血刀，小心的缠回了腰间。\n"NOR);
        }
        init_blade(110);
        setup();
}
