#include <weapon.h>
inherit ARCHERY;

void create()
{
set_name("坚木箭", ({ "mu jian", "arrow", "jian", "mujian"}));
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("long","普普通通的木箭。\n");
        set("unit", "壶");
        set("base_unit", "枝");
        set("base_weight", 1);
        set("base_value", 10);
        set("value", 8000);
        }
set_amount(10000);
init_archery(1);
setup();
}

