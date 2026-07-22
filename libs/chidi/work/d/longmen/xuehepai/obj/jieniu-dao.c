

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;

inherit BLADE;

void create()
{
        set_name(HIY"解牛刀"NOR, ({ "jieniu dao", "dao" }));
          set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把银光雪亮的解牛刀，刀刃间隐隐有血光流动，锋利无匹，
映面生寒。此刀乃血河三宝之一。\n");
            set("value", 500000);
               set("no_break",1);
               set("endure",150);
                set("material", "steel");
                set("wield_msg", WHT "只听「铮」的一声，解牛刀心随意转，自行跃入$N掌中。\n" NOR);
                set("unwield_msg", WHT "$N反转解牛刀，「唰」地插入刀鞘。\n" NOR);
        }
          init_blade(60);
        setup();
}

