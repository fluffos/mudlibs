//Zine
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"钥匙"NOR, ({ "yao shi", "key" }) );
        set("long", "一把古旧的铜钥匙。\n");
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("material", "steel");
				set("value", "100");
        }
		set("key_for","spider");
		set("key_tqt",1);
		set("no_get", 1);
		setup();
}

