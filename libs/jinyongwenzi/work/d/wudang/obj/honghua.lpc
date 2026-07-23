// OBJ : /d/wudang/obj/honghua.c 红花

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"红花"NOR, ({"yao cai","hong hua","yao"}));
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
