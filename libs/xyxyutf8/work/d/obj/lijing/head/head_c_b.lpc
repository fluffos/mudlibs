#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIY"玉女发冠"NOR, ({"hat","kui" }) );
        set("level",7);
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_put",1);
                set("no_zm",1);
                set("unit", "顶");
                set("long", "这是一件上古宝物。\n");
                set("material", "cloth");
		set("value", 50000);
                set("armor_prop/armor", 20);
        }
        setup();
}

