#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(YEL"熊皮袄"NOR, ({ "xiong piao", "pi ao","ao","pi" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件穿了很破旧的熊皮袄。\n");
                set("material", "skin");
		set("value", 0);
                set("armor_prop/armor", 30);
        }
        setup();
}

