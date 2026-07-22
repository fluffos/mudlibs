#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("玉竹筒", ({ "zhu tong", "tong" }) );
        set_max_encumbrance(300000);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("long", "这是一节用明玉竹子做成的竹筒，传说只有五毒教才有。\n"
"上面盖着一个竹盖。\n"
);
        set("unit", "个");
        set("material","bamboo");
        set("no_get", 1);
        }
        setup();
}
