// yinsuo.c 银索 
#include <weapon.h>
#include <ansi.h>

inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name("银索",({ "yin suo", "whip","bian","suo" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "团");
                set("value", 1);
                set("rigidity", 3);
                set("material", "softsteel");
                set("weapon_prop/dodge", 5);
                set("weapon_prop/parry", 3);
                set("treasure",1);
                set("wield_neili", 200);
                set("wield_maxneili", 1000);
                set("wield_str", 20);
                set("long", "一条白色绸带，末端还系著一个金色的圆球。\n");                
                set("unwield_msg", HIY"$N随手一抖，将银索放入怀中。\n"NOR);
                set("wield_msg", HIY"$N缓缓从怀中取出一团冰绡般的物事握在左手之上。\n"NOR);
        }
init_whip(80);
        setup();
}
