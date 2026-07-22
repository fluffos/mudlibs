#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( WHT "巴山图" NOR, ({ "bstu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张详细的巴山地图。\n");
          }
    setup();
}

