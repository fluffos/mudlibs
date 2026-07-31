#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( "绿如意", ({ "green ruyi", "ruyi", "sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "一柄墨绿色的如意，顺其纹理雕成波浪形状。\n");
                set("value", 3000);
                set("no_sell",1);
                set("wield_msg", "$N拿出$n捧在手上。\n");
        	set("weapon_prop/karma", 15);
                set("material", "stone");
        }
        init_sword(115);
        setup();
}
