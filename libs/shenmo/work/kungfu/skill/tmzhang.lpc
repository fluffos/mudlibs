#include <ansi.h>



inherit SKILL;



mapping *action = ({

([      "action": "$N睹准空隙，暴喝一声，一掌印向$n的胸膛心坎穴。",

        "dodge": 30,

        "damage" : 180,
        "force": 160,

        "damage_type": "瘀伤"

]),

([      "action": "$N运劲于双掌之上，有如千斤巨斧，狂劈$n顶门。",

        "dodge": 10,

        "force": 160,
        "damage" : 200,
        "damage_type": "瘀伤"

]),

([      "action": "$N施展身法，幻成两个身形，四道掌力劲度万钧，飞劈向$n的$l",

        "dodge": 20,

        "force": 150,
        "damage" : 220,
        "damage_type": "瘀伤"

]),

([      "action": "$N身影一动，幻化成四个身形，八掌带动连串气劲攻向$n全身。",

        "dodge": 30,

        "force": 200,
        "damage" : 240,
        "damage_type": "瘀伤"

]),

([      "action": "$N猛地腾空而起，于半空幻化成八道身形，掌劲铺天盖地般的朝$n盖顶而下。",

        "dodge": 40,

        "force": 300,
        "damage" : 280,
        "damage_type": "瘀伤"

]),

});



int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike"; }

int valid_combine(string combo) { return combo=="tmquan"; }

mapping query_action(object me)

{

        if (random(me->query_skill("unarmed")) > 60 &&

            me->query_skill("force") > 50 &&

            me->query("neili") > 100 ) {

                me->add("neili", -100);

                return ([

                "action": HIY"只见$N拚尽全力，全身急疾飞旋，双掌豪光暴现，一股"

                          "骇人的掌力攻向$n的胸前"NOR,

                "force": 600,
                "damage" : 880,
                "damage_type": "瘀伤"]);

        }

        return action[random(sizeof(action))];

}



int valid_learn(object me)

{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))

                return notify_fail("练天魔掌必须空手。\n");

        if ((int)me->query_skill("tmdafa", 1) < 10)

                return notify_fail("你的天魔大法火候不够，无法练天魔掌。\n");

        if ((int)me->query("max_neili") < 60)

                return notify_fail("你的内力太弱，无法练天魔掌");

        return 1;

}





int practice_skill(object me)

{

        if ((int)me->query("qi") < 30)

                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 8)

                return notify_fail("你的内力不够练天魔掌。\n");

        if (me->query_skill("tmzhang", 1) < 50)

                me->receive_damage("qi", 20);

        else

                me->receive_damage("qi", 30);

        me->add("neili", -5);

        return 1;

}

string perform_action_file(string action)
{
        return __DIR__"tmzhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,i;
	object weapon;
	string name;
	weapon = me->query_temp("weapon");
	
        level = (int) me->query_skill("kuihua-xinfa",1);
        level2= (int) me->query_skill("kuihua-xinfa",1);
        if (me->query_temp("weapon"))
	        name = "手中" + weapon->name();
        else
	        name = "双掌";
if (!me->query_temp("action_flag") && random(6)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{

	        message_vision(HIW "\n霎时间只见$N" HIW "身子猛摆，顿时化分为无数身影，" + name +
        	               HIW "\n宛若流星般分从不同的方位同时攻向$n" HIW "！\n"
                	       NOR, me, victim);
        me->set_temp("action_flag", 1);
        for (i = 0; i < 3; i++)
        {
                if (! me->is_fighting(victim))
                        break;
  if (random(2)==0) victim->start_busy(2);
                COMBAT_D->do_attack(me, victim, weapon, 0);
        }
        me->delete_temp("action_flag");
}
        lvl  = me->query_skill("tmdafa", 1);
        if (lvl==0)
        lvl  = me->query_skill("tmdafa", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "tmdafa" )
                return;
        if (lvl < 120 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-300);
if (me->query("neili") < me->query("max_neili"))
victim->add("neili",(random(lvl)+50));
return HIC "$n" HIC "全身功力如流水般源源不绝地吸入$N的身体！\n" NOR;
        }
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("tmdafa",1);
        level2= (int) me->query_skill("tmdafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/8;
if (random(8)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{
ob->add("neili",-damage2);
me->add("neili",damage2);
msg = HIC "$N" HIC "一声冷笑! 吸星大法!! " HIC "$n" HIC "全身功力如流水般源源不绝地吸入$N的身体！\n" NOR;

           message_vision(msg, me, ob);
           return j;
}       
}