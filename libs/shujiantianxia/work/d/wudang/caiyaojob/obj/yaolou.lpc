#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("药篓", ({ "yao lou", "lou" }) );
        set_max_encumbrance(3000);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("long", "这是一个用竹子编成的药篓，一般采药人都随身携带一个\n"
"上面盖着一个竹盖。\n"
);
        set("unit", "个");
        set("material","bamboo");
        set("no_get", 1);
        }
        setup();
}
