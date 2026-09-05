#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIM"牡丹"NOR, ({ "peony", "mu dan", "flower" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "盆");
                set("long", "这是一盆雍容华贵的牡丹，自唐宋以来牡丹便有“国色天香”之称，被尊为“花王”。\n");
                set("value", 2000);
                set("material", "wood");
             }
       setup();
}

