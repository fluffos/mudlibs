// shoutao.c
#include <armor.h>
inherit HANDS;
void create()
{
        set_name( "白金手套", ({ "baijin shoutao", "shoutao" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是一双白金丝编的手套，刀枪不入。\n");
                set("value", 6000);
                set("material", "hands");
                set("armor_prop/armor", 5);
                set("shaolin",1);
        }
        setup();
}
