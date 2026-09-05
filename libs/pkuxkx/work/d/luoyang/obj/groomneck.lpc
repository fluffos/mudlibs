//大红花 Zine 17 Oct 2010
#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
        set_name(HIR "大红胸花" NOR, ({"hong hua","flower" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是一朵新郎的大红胸花。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value", 1000);
                set("male_only", 1);
        }
        setup();
}

