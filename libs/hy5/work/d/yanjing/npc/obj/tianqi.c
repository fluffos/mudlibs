#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"田七"NOR,({"tianqi"}));
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "两");
                set("long", "中药材之一.\n");
                set("value", 100);
        }
}


