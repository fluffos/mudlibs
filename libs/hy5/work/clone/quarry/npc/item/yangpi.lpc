#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(NOR + WHT "羊皮" NOR, ({ "yang pi", "yang", "pi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "羊的皮毛，毛质光滑。\n" NOR);
                set("unit", "张");
                set("base_unit", "张");

                set("value", 900);
                set("base_weight", 600);
        }
        setup();
        set_amount(1);
}
