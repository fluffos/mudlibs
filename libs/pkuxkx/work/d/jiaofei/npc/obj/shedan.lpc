#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"蛇胆"NOR, ({ "she dan","dan" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long", "一块水蟒的胆，价值不菲。\n");        
		set("value", 10000);        
        }
        setup();
}

