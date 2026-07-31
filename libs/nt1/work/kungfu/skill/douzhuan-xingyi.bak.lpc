// douzhuan-xingyi 斗转星移
// Created by Lonely (06/11/2002)

#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
        YEL"蓦地里一股力道飞来，将$N一引一带，$N身子轻轻越起，身行落在一旁"NOR,
        BLU"$N当下一股内力冲向$L，$n击向$N的$L的招数莫名奇妙的溜滑向一旁"NOR,
        HIW"$N双手前探，左臂搭上$n右臂，右臂使出$n的招数将$n此招化去"NOR,
        HIY"$N星移斗转，$n这招莫名其妙的在中途转了方向，直奔自己袭来"NOR,
        YEL"$N作壁上观，双手与对方相交数掌，谈笑间竟使出$n成名技艺，使得$n不知如何是好"NOR,
        BLU"$N凝神运气向$n猛攻快打，使出的招数好似$n的成名绝技，把$n的招数化于无行"NOR,
        HIW"只见$N身如飘风，恰似漫天星移，诡异地一式，双掌动向无定不可捉摸地拍向$n的$l"NOR,
        HIY"$N身行飘忽不定，在星移斗转之间反用$n的招数击向$n，却令人$n百思不得其解"NOR,
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
        // return notify_fail("斗转星移只能通过领悟来提高。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("斗转星移只能通过领悟来提高，无法通过练习来提高。\n");
}

string perform_action_file(string action)
{
        return __DIR__"douzhuan-xingyi/" + action;
}

int parry_action(object me, object target, object target_weapon, int attack_type, mapping action, string limb)
{
        string msg;
        object weapon, *enemy;
        int dp, ap, i, nb;

        if (me->query_condition("dugu_damage") ||
            (string)target->query("race") == "野兽" ||
            ! living(me) ||
            me->is_busy())
                return 0;
        
        weapon = me->query_temp("weapon");
        
        if (target_weapon)       
        {
                if(! weapon) return 0;
        }
                
        msg = "\n" + action["action"] + "\n";
        msg += HIW "$n不躲不避，微微一笑，使出$N的绝技，以彼之道还制彼身！\n" NOR;
        
        if (target_weapon)
        {
                ap = target->query_skill(target_weapon->query("skill_type"));
                msg = replace_string(msg, "$w", target_weapon->query("name"));        
        }
        else    ap = target->query_skill("force");
        ap += target->query_skill("count", 1);         
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("douzhuan-xingyi", 1);

        msg = replace_string(msg, "$l", limb);
        
        if (ap / 2 + random(ap) < dp)
        {        
                message_combatd(msg, target, me);
                if (! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack1(me, target, weapon, 2, action, limb);
                return 1;
        }
        
        return 0;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (me->query_skill("shenyuan-gong", 1) < 100
        ||  me->query_skill_mapped("force") != "shenyuan-gong")
                return 0;

        lvl = me->query_skill("douzhuan-xingyi", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

