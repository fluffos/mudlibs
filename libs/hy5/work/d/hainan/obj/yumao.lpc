#include <armor.h>
#include <ansi.h>;
inherit CLOTH;

void create()
{
        set_name( HIW"羽毛"NOR, ({ "yu mao", "mao" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "撮");
        set("long","一撮美丽的羽毛.\n");
                set("value", 500);
        set("combat_exp", 5000000);
                set("material", "leather");
                set("armor_prop/armor", 1);
        }
        setup();
}

