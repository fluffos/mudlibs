//凤冠 Zine 17 Oct 2010
#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIR "凤冠" NOR, ({"feng guan","guan" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "凤冠共用红、蓝宝石一百多块，大小珍珠五千余颗，色泽鲜艳，富丽堂皇，堪称珍宝之冠。\n");
                set("material", "steel");
                set("armor_prop/armor", 1);
                set("value", 24000);
                set("female_only", 1);
        }
        setup();
}

