#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name("»¢¹Ç", ({"tiger bone"}) );
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "»¢¹Ç¡£\n" NOR);
                set("base_unit", "¾ß");
                set("base_value", 8000);
                set("base_weight", 500);
        }
        set("maze_item", 1);
	setup();
        set_amount(1);
}
