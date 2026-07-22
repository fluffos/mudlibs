#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB "太极拳经" NOR, ({ "taiji-quanjing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "cloth");
            set("long", "一本画满了各种姿势的武术典籍。\n");
          }

    setup();
}

