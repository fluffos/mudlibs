// OBJ : /u/lius/yaodai.c 药袋
// By lius 99/8

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"药袋"NOR, ({ "yao dai","dai" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long",
                        "这是白色的粗布药袋，里面装着许多药材。\n");
                set("value", 0);
                set("material", "cloth");
                set("no_drop",1);
                set("no_get",1);
                set("no_put",1);
                set("no_give",1);

         }
}
