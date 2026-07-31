#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIG "弟子服" NOR, ({ "cloth", "fu" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("long","这是痴心妄想门为弟子们特制的服装，没什么特别的。\n");
        }
        setup();
}


