// yinsuo.c 银索 
#include <weapon.h>
#include <ansi.h>
inherit WHIP;
inherit F_UNIQUE1;

void create()
{
        set_name(HIW"银索"HIY"金铃"NOR,({ "yinsuo jinling","whip","yinsuo","jinling" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "团");
                set("replica_ob", "/clone/weapon/changbian");
                set("no_put", 1);
                set("no_steal",1);      
                set("unique", 1);
                set("rigidity", 300);
                set("material", "softsteel");
                set("weapon_prop/dodge", 5);
                set("weapon_prop/parry", 3);
                set("treasure",1);
                set("wield_neili", 200);
                set("wield_maxneili", 1000);
                set("wield_str", 20);
                set("long", "一条白色绸带，末端还系著一个金色的圆球。\n");                
                set("unwield_msg", HIY"$N随手一抖，将银索放入怀中。\n"NOR);
                set("wield_msg", HIY"$N缓缓从怀中取出一银白色绸带握在手中。\n"NOR);
        }
        init_whip(400,2);
        setup();
}

