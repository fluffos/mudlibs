// 盗墓用的铁锹

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;
void create()
{
    set_name(HIW "铁锹" NOR, ({ "tie qiao", "qiao" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", HIW"一柄铁锹,用来挖地最合适不过了。\n"NOR);
                set("value", 10);
                set("material", "iron");
                set("usetime", 20+random(10));
 set("wield_msg", HIW"$N一把抓住铁锹握在手中！\n"NOR);
                set("unwield_msg", HIY"$N放下手中的$n。\n"NOR);
      }
        init_spear(10);
        setup();
}
