// shiweifu.c 侍卫服

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIR"侍卫服"NOR, ({"shiwei fu", "fu"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 0);
                set("long", "一件代表着高级侍卫的侍卫服。\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}

