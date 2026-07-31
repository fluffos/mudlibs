// douzhuan-xingyi 斗转星移
// 1997-2-14
#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
YEL"蓦地里一股力道飞来，将$n一引一带，$n身子轻轻越起，身行落在一旁"NOR,
BLU"$n当下一股内力冲向$l，$N击向$n的$l的招数莫名奇妙的溜滑向一旁"NOR,
HIW"$n双手前探，左臂搭上$N右臂，右臂使出$N的招数将$N此招化去"NOR,
HIY"$n星移斗转，$N这招莫名其妙的在中途转了方向，直奔自己袭来"NOR,
YEL"$n作壁上观，双手与对方相交数掌，谈笑间竟使出$N成名技艺，使得$N不知如何是好"NOR,
BLU"$n凝神运气向$N猛攻快打，使出的招数好似$N的成名绝技，把$N的招数化于无行"NOR,
HIW"只见$n身如飘风，恰似漫天星移，诡异地一式，双掌动向无定不可捉摸地拍向$N的$l"NOR,
HIY"$n身行飘忽不定，在星移斗转之间反用$N的招数击向$N，却令人$N百思不得其解"NOR,
});

int valid_enable(string usage)
{
        return usage == "parry";
}

string query_parry_msg(object weapon)
{
                return parry_msg[random(sizeof(parry_msg))] + "。\n";
}

int valid_learn(object me)
{
     return notify_fail("斗转星移只能通过领悟来提高。\n");
}

int practice_skill(object me)
{
        return notify_fail("斗转星移只能通过领悟来提高，无法通过练习来提高。\n");
}

string perform_action_file(string action)
{
        return __DIR__"douzhuan-xingyi/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
       string msg;
       int j, k;
       j = me->query_skill("douzhuan-xingyi", 1);
       k = me->query_skill("parry",1);
       if( random(10) >= 5 
        && !me->is_busy() 
        && !victim->is_busy() 
        && j > 201
        && k > 500
        && me->query_skill_mapped("parry") == "douzhuan-xingyi"
        && (me->query("neili")*3) > victim->query("max_neili")){
          switch(random(3)){
            case 0 :
               msg = HIW"$N反击！\n"NOR;
               msg+= HIW"$n连连後退，全力招架，无力还招！\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
               break;
            case 1 :
               msg = HIW"$N反击！！\n"NOR;
               msg+= HIW"$n根本分不清楚那一剑是虚，那一剑是实，好停下攻势，严守门户。\n"NOR;
               victim->start_busy(2);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 0);
               break;
            case 2 :
               msg = HIW"$N风驰电掣的绕著$n快跑，忽东忽西，简直像是足不点地的飞行一般！\n"NOR;
               msg+= HIW"$n随着$N转来转去，弄得眼花缭乱，摇摇欲坠。\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
               break;
          }         
       }
}

