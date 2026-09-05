#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(HIW"明光甲"NOR, ({ "mingguang jia" , "armor", "jia"  }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "steel");
                set("value", 5000);
                set("armor_prop/armor", 150);
                set("long","这件铠甲前面以大块的圆形甲板组装而成，光滑地铠甲在阳光下闪耀着晃眼的白光。\n");
        }
        set("no_sell",1);
        setup();
}