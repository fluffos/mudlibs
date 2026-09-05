//红缨枪

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
set_name(HIW"红缨枪" NOR, ({ "hongying qiang", "qiang","hongying" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", HIW"这是一把红缨枪。\n"NOR);
                set("value", 10);
                set("material", "wood");
                set("rigidity",1000);
 set("wield_msg", HIG"$N一把将$n"+HIG"握在手中\n"NOR);
               set("unwield_msg", HIG"$N反手将$n"+HIG"背在身后。\n"NOR);
        }
        init_spear(1);
        setup();
}
