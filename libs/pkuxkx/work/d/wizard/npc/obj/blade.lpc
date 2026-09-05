// 新手用blade
// By Kiden@pkuxkx

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("大砍刀", ({ "dakan dao", "dao", "blade" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "steel");
                set("long", "这是一把很沉的刀，甚为锋利。\n");
        }
        init_blade(60);
        setup();
}

