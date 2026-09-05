#include <weapon.h>
#include <ansi.h>
inherit SPEAR;
void create()
{
    set_name(HIW "秤" NOR, ({ "cheng" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", HIW"一柄秤，还有一个大秤砣，是小贩用的。\n"NOR);
                set("value", 10);
                set("material", "iron");
                set("usetime", 20+random(10));
                set("wield_msg", HIW"$N抓起秤握在手中！\n"NOR);
                set("unwield_msg", HIY"$N放下手中的$n。\n"NOR);
      }
        init_spear(10);
        setup();
}
