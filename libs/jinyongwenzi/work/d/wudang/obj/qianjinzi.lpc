// OBJ : /d/wudang/obj/qianjinzi.c 千金子

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"千金子"NOR, ({"yao cai","qianjinzi","yao"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
            set("unit", "株");
            set("long", YEL"这是一株刚从山林中采摘下来的药材，还带着丛林泥土的气息。\n"NOR);
            set("value", 100);
        }
        setup();
}
