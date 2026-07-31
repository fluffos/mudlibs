#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIC"七彩玉花环"NOR, ({"hat","kui" }) );
        set("level",7);
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_put",1);
                set("no_zm",1);
                set("unit", "顶");
                set("material", "cloth");
                set("long", "这是一件传说中的神器。\n");                
		set("value", 100000);
                set("armor_prop/armor", 40);
        }
        setup();
}

