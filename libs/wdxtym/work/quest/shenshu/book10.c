#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(MAG"连城决"NOR, ({ "lcjue" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("unit", "本");
            set("material", "paper");
            set("long", "神书之一。\n");
          }

    setup();
}
