#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + WHT "玄铁重剑" NOR, ({ "xuantie jian", "xuantie", "jian" }) );
        set_weight(28000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "一柄由玄铁铸成的无锋长剑，着手沉重无比，但是却蕴藏着极大的威力。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", NOR + WHT "$N" NOR + WHT "抽出$n" NOR + WHT"，仗剑而立，威风凛凛，令人肃然起敬。\n" NOR);
                set("unwield_msg", NOR + WHT "$N" NOR + WHT "仰天长叹，潜运内力，将$n" NOR + WHT "收回。\n" NOR);
                set("stable", 100);

        }
        init_sword(600+random(320));
        setup();
}

