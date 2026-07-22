#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLU"ìóìõÓïÂ¼"NOR, ({ "qizhen-yulu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "±¾");
            set("material", "paper");
            set("long", "Ò»±¾ìóìõÓïÂ¼¡£\n");
          }

    setup();
}

