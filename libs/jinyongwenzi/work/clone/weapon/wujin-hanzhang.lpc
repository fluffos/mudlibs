#include <ansi.h>
#include <weapon.h>
#include <ansi.h>
inherit STAFF;
inherit F_UNIQUE;
void create()
{
        set_name(HIR "乌金寒杖" NOR, ({ "wujin hanzhang", "hanzhang","zhang", "wujin","staff" }));
        set_weight(35000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这杖，相传由昆仑山顶采集的乌金混合精钢炼成，通体发乌，散发着冰凉寒气。\n");
                set("value", 100000);
                set("unique", 1);
                set("rigidity", 1);
                set("material", "gold");
                set("weapon_prop/parry", 3);
                set("weapon_prop/dodge", -10);
                set("wield_neili", 400);
                set("wield_maxneili", 800);
                set("wield_str", 22);
                set("wield_msg", HIY"$N发力一挥，手中握着一根乌金寒杖，威猛之极！\n"NOR);
                set("unwield_msg", HIY"$N往后斜斜一插，将杖斜背在背后。\n"NOR);
        }
        init_staff(85);
        setup();
}
