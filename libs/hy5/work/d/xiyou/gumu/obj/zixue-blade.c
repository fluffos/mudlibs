//紫血狂刀
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;
inherit F_UNIQUE;

inherit BLADE;
#include <ansi.h>
void create()
{
        set_name(MAG"紫血狂刀"NOR, ({"zixue kuangdao", "dao","blade"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","一柄通体紫色的宝刀。\n");
                set("unit", "柄");
                 set("unique", 1);
                set("value", 120);
                set("wield_msg", "$N手中升起一团紫气，慢慢化作一柄宝刀！\n");
                set("unwield_msg", "$N手中的宝刀化作一团紫气消失了。\n");
                set("weapon_prop/courage", 20);
                }
        init_blade(820);
        setup();
}

