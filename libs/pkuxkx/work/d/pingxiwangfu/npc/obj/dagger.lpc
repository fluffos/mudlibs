#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("鱼肠刺", ({ "dagger" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把镶着无数宝石的短剑.\n");
                set("value", 800000);
                set("material", "silver");
           }
        init_sword(2);
        setup();
}
