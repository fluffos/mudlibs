#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"╨Х╧бремп" NOR, ({ "hgyituo" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "уе");
            set("material", "stone");
            set("long", "р╩уе╨Х╧бремп\n");
          }
    setup();
}

