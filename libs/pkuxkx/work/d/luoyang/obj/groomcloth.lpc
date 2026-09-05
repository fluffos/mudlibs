//状元服 Zine 17 Oct 2010
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIR "状元服" NOR, ({"zhuangyuan fu","cloth" }));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件状元的大红吉服。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value", 8000);
                set("male_only", 1);
        }
        setup();
}

