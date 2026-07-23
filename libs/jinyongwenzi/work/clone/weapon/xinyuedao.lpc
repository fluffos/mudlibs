// xinyuedao.c 
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( HIW"雪山新月刀"NOR , ({ "xinyue dao", "xueshan dao","dao","blade"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIW"这把刀既轻且薄，刀身弯成半月形，形状古怪，武林中甚为少见。\n"NOR);
                set("value", 1000);
                set("material", "steel");
        }
        init_blade(30);
        setup();
}
