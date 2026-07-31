//血雾剑
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(RED"血雾剑"NOR, ({"blood sword","sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","饮千人鲜血，斩万人头颅的一柄魔剑！\n");
                set("unit", "柄");
                set("value", 12000);
                set("wield_msg",RED "$N划破左手，一滴滴鲜血凝结成一柄血色宝剑！\n"NOR);
                set("unwield_msg",RED "$N手中的血色宝剑化成一团血雾,被$N你吸进口中!\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_sword(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "陷空山无底洞"
                && me->query_skill("qixiu-jian",1) > 1)
    damage_bonus = me->query_skill("qixiu-jian",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("qi",damage_bonus);
    return RED"血雾剑上浮现出无数幽灵的怨气！\n" NOR;

}

