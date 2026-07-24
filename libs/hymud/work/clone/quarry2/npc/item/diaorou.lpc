#include <ansi.h>

inherit COMBINED_ITEM;
#include "meat.h"

void create()
{
        set_name(NOR + WHT "貂肉" NOR, ({ "diao rou", "diao", "rou" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "这是一块散发着腥臊臭的貂肉。\n" NOR);
                set("unit", "块");
                set("base_unit", "块");

                set("value", 360);
        }
        setup();
        set_amount(1);
}
