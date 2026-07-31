// sgzl

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

int do_install(string);
int do_uninstall(string);

string ori_long="一柄随身的佩剑，剑柄处似乎有些机关能装(install)些暗器进去。\n";


void create()
{
        set_name("佩剑", ({"pei jian","jian","sword"}));
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",ori_long);
                set("orilong",ori_long);
                set("unit", "把");
                set("value", 3000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");

                set("anqi/allow", 1);
                set("anqi/max", 20);
                set("anqi/now", 0);
        }
        init_sword(135);
        setup();
}

