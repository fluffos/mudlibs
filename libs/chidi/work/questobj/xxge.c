#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"ÏÉÐ¦¸è"NOR, ({ "xxge" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Æ×");
            set("material", "stone");
            set("long", "Ò»Æ×ÏÉÐ¦¸è\n");
          }

    setup();
}

