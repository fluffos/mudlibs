#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(NOR + WHT "狐狸皮" NOR, ({ "huli pi", "huli", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "这是一张毛质颇为不错的狐狸皮。\n" NOR);
                set("base_unit", "张");
                set("unit", "张");
                set("value", 3000);
                set("base_weight", 500);
        }
        setup();
        set_amount(1);
}
