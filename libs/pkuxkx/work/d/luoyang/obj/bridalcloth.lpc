//霞帔 Zine 17 Oct 2010
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIR "霞帔" NOR, ({"skirt","bridal skirt" }));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件新娘的礼服，其形美如彩霞，故得名“霞帔”。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value", 12000);
                set("female_only", 1);
        }
        setup();
}

