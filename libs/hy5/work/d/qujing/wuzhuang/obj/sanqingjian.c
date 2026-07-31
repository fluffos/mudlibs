//三清剑
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIW"三清剑"NOR, ({"sanqing sword","sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","天上三清，共铸此剑，其锋之利，无可匹敌！\n");
                set("unit", "柄");
                set("value", 12000);
                set("wield_msg",HIW "$N左手捏了个剑决，右手向天一指，一柄三清剑从天而至！\n"NOR);
                set("unwield_msg",HIW "$N一声无量寿佛,将宝剑插回剑鞘之中.\n");
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
    
    if( (string)me->query("family/family_name") == "五庄观"
                && me->query_skill("sanqing-jian",1) > 1)
    damage_bonus = me->query_skill("sanqing-jian",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("qi",damage_bonus);
    return HIR"三清剑上灵光四动！\n" NOR;

}

