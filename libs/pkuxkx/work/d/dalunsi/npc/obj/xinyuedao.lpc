#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
    set_name(HIW"雪山新月刀"NOR, ({ "xinyue dao","blade" }));
    set_weight(7000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "柄");
        set("long", "这把刀既轻且薄，刀身弯成半月形，形状古怪，武林中甚为少见。\n");
        set("value", 1000);
        set("material", "steel");
//        set("wield_msg", "$N缓缓抽出一柄$n握在手中。\n");
//        set("unwield_msg", "$N放下手中的。\n");
    }
    init_blade(35);
    setup();
}

