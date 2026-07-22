inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW"布阵箱"NOR, ({ "array box","box"}));
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个桃花岛弟子用来布阵的布阵箱。\n");
                set("value", 10);
                set("unique", 1);
                set("material", "steel");
         }
        setup();
}
