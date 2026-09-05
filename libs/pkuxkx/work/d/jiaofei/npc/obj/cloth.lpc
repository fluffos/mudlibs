#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"软藤丝衣"NOR, ({ "ruanteng siyi","cloth" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "这是用五指山特产的一种软藤剥丝织就的衣服，除了防寒保暖，还有一定的防御功效。\n");
        set("material", "cloth");
		set("value", 1000);
        set("armor_prop/armor", 50);
        }
        setup();
}

