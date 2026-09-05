// dulongbian.c 毒龙鞭

#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
        set_name(HIB"毒龙鞭"NOR, ({ "dulong bian", "bian","whip" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是精工制作的毒龙鞭，以神龙岛罕见寒铁为加神龙皮制成。\n");
                set("value", 10000);
                set("material", "leather");
                set("wield_msg", HIY"$N冷笑一声，反手抄到身后握起一柄$n"+HIY+"，手臂一扬，你感觉一股寒气扑面而来。\n"NOR);
                set("unwield_msg", "$N将手中的$n卷回腰间。\n");
        }
        init_whip(125+random(50));
        setup();
}

