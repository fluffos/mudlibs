// shihun.c 噬魂棍

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(RED"噬魂棍"NOR, ({"shihun gun","stick", "bang"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把狼牙棒，是大天魔的兵器\n");
                set("unit", "把");
		set("wield_msg","$n"RED"抽出$N捧在手中，身后出现大天魔的幻影。\n"NOR);
		set("unwield_msg",RED"$N将手中$n"NOR+RED"一收，插在背后！\n"NOR);
                set("value", 100);
                set("material", "gold");
		set("weapon_prop/courage", 100);
        }
        init_staff(80);
        setup();
}
