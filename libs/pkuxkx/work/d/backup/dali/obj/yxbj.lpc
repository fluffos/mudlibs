// /d/dali/obj/yxbj.c 游侠宝剑
// notme 2004/04/11
// 降低了剑的重量

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
    set_name( MAG"游侠宝剑" NOR, ({ "paladin sword", "sword" }) );
    set_weight(10000);

    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "柄");
        set("long", "这是一把游侠早年闯荡江湖时炼就的宝剑.\n");
        set("value", 10000);
        set("material", "steel");
        set("wield_msg", HIY"$N把宝剑拔出剑鞘, 耀眼的光芒照亮了周围的一切.\n"NOR );
        set("unwield_msg", YEL"$N将剑插回剑鞘, 天空顿时暗淡下来.\n"NOR );
    }
    init_sword(100);
    setup();
}
