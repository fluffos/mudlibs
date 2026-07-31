#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIM "欧冶子圣符" NOR, ({ "ouyezi symbol", "symbol" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "欧冶子圣符可以将改造装备的成功率提升到90%。\n" NOR);
                set("unit", "张");
                set("value", 500000);
        }
        setup();
}

