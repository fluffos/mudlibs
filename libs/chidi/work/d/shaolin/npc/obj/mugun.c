// mudao.c
#include <weapon.h>
inherit CLUB;
void create()
{
    set_name("木棍", ({ "mu gun", "gun", "club" }) );
    set_weight(2000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "根");
        set("value", 30);
        set("material", "iron");
        set("long", "这是一根三尺余长的木棍。\n");
        set("wield_msg", "$N双手拿着$n，舞动了一下，呼呼有声。\n");
        set("unequip_msg", "$N将手中的$n插回背后。\n");
    }
    init_club(1,1);
    setup();
}
