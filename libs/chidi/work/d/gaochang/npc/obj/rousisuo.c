// by mei
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name("柔丝索", ({"rousisuo", "silk"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "摞");
        set("long", "这是一摞微细透明, 几非肉眼所能察见的丝索。\n");
        set("value", 100000);
        set("material", "leather");
        set("wield_msg", "$N抽出一条$n，握在手中。\n");
        set("unwield_msg", "$N放下手中的$n绑在腰间。\n");
        }
        init_whip(1,2);
        setup();
}
