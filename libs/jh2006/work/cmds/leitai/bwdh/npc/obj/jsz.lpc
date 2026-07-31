//jinshe-zhui.c 
#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
       set_name(HIY"金蛇锥" NOR, ({"jinshe zhui", "jinshe", "zhui" }));
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long", "两寸来长，成蛇形的暗器。\n");
               set("unit", "袋");
               set("base_value", 100000000);
               set("base_unit", "枚");
               set("base_weight", 10);
               set("treasure", 1);
               set("base_unique", 40);
            }
       set_amount(20);
       init_throwing(40);
}
