#include <weapon.h>
inherit ARCHERY;

void create()
{
set_name("铁箭", ({ "tie jian", "arrow", "jian", "tiejian"}));
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("long","普普通通的铁箭。\n");
        set("unit", "壶");
        set("base_unit", "枝");
        set("base_weight", 1);
        set("base_value", 500);
        set("value", 50000);
        }
set_amount(1000);
init_archery(10);
setup();
}

