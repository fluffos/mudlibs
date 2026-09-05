#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"貂皮"NOR, ({ "diao pi","pi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
		set("long", "一块貂皮，看来价值不菲。\n");
        set("material", "cloth");
		set("value", 10000);        
        }
        setup();
}

