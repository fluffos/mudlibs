// shenlong-bian.c 神龙教之神龙鞭法
// 2006-8-28

#include <ansi.h>
#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
"$n不闪不避，扬起$w，卷向$N的兵刃",
"只见$n不退反进，一式「龙行虎步」，动向无定不可捉摸地指向$N的$l",
"$n巍然不动，待到$N招式用老气力将近之时，用手中$w轻轻隔开",
});

string  *msg = ({
HIB"$N一声清啸，一招「虎啸龙吟」随即递向$n的$l，鞭梢颤动，发出令人胆寒的声音"NOR,
WHT"$N默守虎步，$w骤然挥出，$N突然向前跃出，绕道$n身后，$n一惊之下，已在$N鞭圈之内"NOR,
HIR"$N突然以鞭做剑，$w抖得笔直，点向$n的$l，暗藏无数后着，$n手足无措，不知如何是好"NOR,
YEL"$N倒转$w，随手一摆，但见$n自己向$w撞将上来，好一招「虎踞龙盘」"NOR,
CYN"$N突然使出一招「龙肝凤胆」，左手单掌劈向$n右臂，右手$w直袭$n左胸"NOR,
MAG"$N招式突变，使出「游龙戏水」，鞭梢舞动，直袭$N$l"NOR,
HIW"$N招式突然大开大豁，举起$w向$n当头劈头盖脸的砸将过来"NOR,
"$N手腕一抖$w，攻向$n下三路，$n眼前一片鞭影，不见$N，慌乱之中发现$w已经卷到",
});

int valid_enable(string usage)
{
        return usage == "whip" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenlong-xinfa", 1) < 30)
                return notify_fail("你的神龙心法等级不够。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                  "damage":random(5)*30+160,
                "damage_type":random(2)?"拉伤":"劈伤",
                "dodge":100+random(100),
                "force":300+random(100)
        ]);
}

string query_parry_msg(object weapon)
{
        if (!weapon) return "但是被$n挡开了。\n";
        if (weapon->query("skill_type") == "whip")
                return parry_msg[random(sizeof(parry_msg))] + "。\n";
        if (weapon->query("skill_type") != "whip")
                   return "但是被$n挡开了。\n";
}


string perform_action_file(string action)
{
        return __DIR__"shenlong-bian/" + action;
}



int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对！\n");
        if ((int)me->query("qi") < 50)
                 return notify_fail("你的体力不够！\n");
        me->receive_damage("qi", 30);
        return 1;
}

/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object weap,weap1;
        weap = victim->query_temp("weapon");
        weap1 = me->query_temp("weapon");
        if( (me->query_skill("shenlong-bian",1) > 280) && (me->query("neili") > 100)
            && random(10)>5)
        {
            message_vision(HIY "只见$N急速挥舞" + weap1->name() + "攻向对方，"+victim->query("name")+"只觉眼前一片鞭影，慌乱之中鞭梢已到面门！\n" NOR, me );

            if (random(me->query_dex()) > victim->query_dex()/2 )
              {
               message_vision(HIR "$N慌乱之中不知所措，只得拿"+ weap->name()
               +"迎向"+me->query("name")+"。\n不料"+weap1->name()
               +"似长了眼睛一样，突然一转，$N已然被击中,哇的一声吐出一口鲜血。\n" NOR, victim );
               victim->receive_wound("qi", ((int)me->query_skill("shenlong-xinfa", 1))/2);     
               victim->receive_damage("qi", ((int)me->query_skill("shenlong-bian", 1))/2);
              } 
        else 
              {
               message_vision(HIW "$N身轻似燕，" + weap->name()
               + "挥出，点向"+weap1->name()+"，身形急退，退出了"+weap1->name()+"的圈子。\n" NOR, victim );
               }
         me->add("neili", -50);
        }
     return 1;
}

*/
