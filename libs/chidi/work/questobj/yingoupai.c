#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"Òø¹³ÅÆ"NOR, ({ "yingoupai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¿é");
            set("material", "stone");
            set("long", "Òø¹³ÅÆ\n");
          }

    setup();
}

