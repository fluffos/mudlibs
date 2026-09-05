// cloth: wcloth.c
// Jay 3/17/96
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(WHT"回族长袍"NOR, ({ "huizu changpao","changpao","pao", "robe"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件白色的回族长袍。\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 5);
        }
        setup();
}

