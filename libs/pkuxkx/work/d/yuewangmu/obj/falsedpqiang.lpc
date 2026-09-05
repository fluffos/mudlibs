//仿制夺魄枪

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
set_name(MAG"仿制夺魄枪" NOR, ({ "false qiang", "qiang","falseqiang","false" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", HIW"这是一把仿制的夺魄枪,虽然是仿制的,也够厉害了。\n"NOR);
                 set("value", 100000);
                set("material", "steel");
                set("rigidity",100000);
 set("wield_msg", HIG"$N一把将$n"+HIG"握在手中，不禁为自己有一把'夺魄枪'得意洋洋！\n"NOR);
               set("unwield_msg", HIG"$N反手将$n"+HIG"背在身后。\n"NOR);
        }
        init_spear(100);
        setup();
}
