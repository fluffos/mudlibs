
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( "Ò»À¦²ñ»ð", ({ "chaihuo"}) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "À¦");               
                set("value", 0);
                set("material", "iron");
        }
        setup();
}
