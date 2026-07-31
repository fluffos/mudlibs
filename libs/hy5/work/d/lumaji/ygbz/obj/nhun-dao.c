// /d/ygbz/obj/ninghun.c
// by yahoo 18:06 99-3-22
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()

{
        set_name(HIW "凝魂宝刀" NOR, ({ "ninghun blade", "blade" }) );
          set_weight(50000);
        if (clonep())

                set_default_object(__FILE__);

        else {
                set("unit", "柄");
                set("long", "这是一柄充满杀气的宝刀，一看即知是上古神兵。\n");
                set("no_get", 1);
                set("no_give", 1);
                set("value", 10000);
                set("material", "steel");
        set("wield_msg", HIW "只见$N「唰」的一声抽出一柄凝魂宝刀握在手中，一股刀气让人心寒。\n" NOR);
                  set("unwield_msg", HIW "$N将手中的凝魂宝刀插回刀鞘。大家才觉得呼吸好过一点。\n" NOR);
        }
        set("rigidity",1000);
    set("no_get",1);
    set("no_drop",1);
        init_blade(1600);
        setup();
}


