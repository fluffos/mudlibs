//夺命追魂枪

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
set_name(HIB"夺命追魂枪" NOR, ({ "duoming qiang", "qiang","duoming" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", HIW"夺命追魂枪,枪身其长,在前端枪尖处还有一个小勾让人不寒而栗。\n"NOR);
                 set("value", 80000);
                set("material", "steel");
                set("rigidity",10000);
 set("wield_msg", HIB"$N一把将$n"+HIB"握在手中,气势夺人\n"NOR);
               set("unwield_msg", HIB"$N反手将$n"+HIB"背在身后。\n"NOR);
        }
        init_spear(80);
        setup();
}
