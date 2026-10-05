// 大使西服

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("西服", ({ "weiwuer robe", "robe"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
                set("long", "这是一崭新的西服，线条鲜明，衣料考究，绝对是跨时代的产品\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 100);
        }
        setup();
}