    //水漫三秋
    //by dewbaby@sk


#include <ansi.h>
#include <weapon.h>
inherit FORK;
inherit F_UNIQUE;

void create()
{
       set_name(HIC"水漫三秋"NOR, ({"sanqiu fork","sanqiu","fork"}));
       set_weight(20000);
if( clonep() )
             set_default_object(__FILE__);
       else {
       set("long",HIC"据说这是东海龙王的贴身宝物。它周身泛着幽蓝的光泽，似乎隐藏着深海的奥秘。\n");
             set("unit","柄");
             set("value", 12000);
             set("wield_msg",HIC"$N仰天纵身一跃，接住了从天而降的$n"HIC"，如碧水游龙般敏捷迅速!\n"NOR);
             set("unwield_msg",HIC"$N随手一挥，手中的$n"HIC"突然化为点点露水消失了!\n"NOR);
             set("no_sell","你大脑有问题吧？这东西你都敢卖？\n");
             set("no_drog","去垃圾堆丢吧，乱扔会污染环境!\n");

             set("weapon_prop/courage",20);
       }
       init_fork(130);
       setup();
}
/*
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    if( (string)me->query("family/family_name") == "东海龙宫"
             && me->query_skill("fengbo-cha",1) > 1)
    damage_bonus = me->query_skill("fengbo-cha",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("qi",damage_bonus);
    return HIB"水漫三秋发出阵阵碧波之音!\n"NOR;
}

*/
