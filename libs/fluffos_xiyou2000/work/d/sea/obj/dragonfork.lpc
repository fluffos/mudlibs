// cracked by vikee 2/09/2002   vikee@263.net
#include <weapon.h>

inherit FORK;

void create()
{
        set_name("龙角叉", ({ "dragon fork", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 5000);
                set("material", "iron");
                set("long", "一柄尖利的龙角叉。\n");
                set("wield_msg", "$N抄起一柄$n，在头上挥舞了一圈。\n");
        }
        init_fork(50);
        setup();
}

