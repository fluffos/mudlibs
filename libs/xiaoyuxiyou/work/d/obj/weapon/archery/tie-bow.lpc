#include <weapon.h>
inherit BOW; 

void create()
{
set_name("铁弓", ({"tie gong", "bow", "gong"}));
set_weight(5000);
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("long", "一张铁制的短弓。\n");
        set("unit", "张");
        set("value", 7000);
        set("wield_msg", "$N抓起一张$n，握在手中当武器。\n");
        set("material", "iron");
        }
init_bow(110);
setup();
}

