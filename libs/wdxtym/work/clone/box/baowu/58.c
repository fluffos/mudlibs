#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name(NOR + WHT "鱼肠剑" NOR, ({"yuchang jian", "yuchang", "jian", "dagger"}));
        set_weight(2500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", WHT "一柄古朴沉重的短匕首，匕脊上刻有「" HIY "鱼肠"
                            NOR + WHT "」二字。\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "从兜里掏出一柄匕首，空气中顿时沁"
                                 "出一丝寒气。\n" NOR);
                set("unwield_msg", WHT "$N" WHT "手中的鱼肠剑一转，眨眼间已然不"
                                 "见影踪。\n" NOR);
                set("stable", 100);
        }
        init_dagger(600+random(320));
        setup();
}
