#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIY"¿∞√∑"NOR, ({"wintersweet", "la mei"}) );
        set_weight(100);
        if( clonep() )
          set_default_object(__FILE__);
        else {
            set("unit", "÷¶");
            set("long", "∂‰∂‰¿∞√∑ ¢ø™£¨«Âœ„∆À±«°£\n");
            set("value", 10);
        }
        setup();
}       
