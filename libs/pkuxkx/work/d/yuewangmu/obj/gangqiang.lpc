//钢枪

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
set_name(HIW"钢枪" NOR, ({ "gang qiang", "qiang","gang" }));
        set_weight(14000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", HIW"这是一把钢枪。\n"NOR);
                set("value", 10000);
                set("material", "steel");
                set("rigidity",5000);
 set("wield_msg", HIG"$N一把将$n"+HIG"握在手中\n"NOR);
               set("unwield_msg", HIG"$N反手将$n"+HIG"背在身后。\n"NOR);
        }
        init_spear(50);
        setup();
}
