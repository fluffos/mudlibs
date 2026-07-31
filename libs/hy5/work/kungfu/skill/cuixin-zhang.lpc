// cuixin-zhang.c 催心掌 by XiaoYao 4/22/99
// npc skill

#include <ansi.h>
inherit SKILL;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";


mapping *action = ({
([	"action" : "$N使一招「风起云涌」，双手飘移不定击向$n$l",
	"force" : 160,
	"dodge" : 2,
	"damage":200+random(100),
	"skill_name" : "风起云涌",
	"lvl" : 0,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N倏忽欺至$n身前，一招「扬波起浪」直拍$n的$l",
	"force" : 240,
	"dodge" : 0,
	"damage":200+random(100),
	"skill_name" : "扬波起浪",
	"lvl" : 30,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形绕$n一转，一招「风雷并起」向$n$l接连出掌",
	"force" : 320,
	"dodge" : -2,
	"damage":200+random(100),
	"skill_name" : "风雷并起",
	"lvl" : 50,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形拔起，在半空一招「急电惊雷」右掌猛击$n的$l",
	"force" : 400,
	"dodge" : -4,
	"damage":200+random(100),
	"skill_name" : "急电惊雷",
	"lvl" : 90,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「含沙射影」，纵起丈余直击$n的$l",
	"force" : 500,
	"dodge" : -6,
	"damage":200+random(100),
	"skill_name" : "含沙射影",
	"lvl" : 120,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一声大喝使出「夺魄催心」，幻出满天掌影，掌掌不离$n的$l",
	"force" : 620,
	"dodge" : -8,
	"damage":200+random(100),
	"skill_name" : "夺魄催心",
	"lvl" : 150,
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jiuyin-baiguzhua"; }

int valid_learn(object me)
{
       if (!me->query("jiuyin/xia") && !me->query("jiuyin/emei"))
               return notify_fail("你现在不能学习催心掌。\n");
       if( (int)me->query_skill("jiuyin-shenzhang", 1 ) >= 1)
                return notify_fail("学了九阴神掌，还要催心掌？\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练催心掌必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练催心掌。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
        level = (int) me->query_skill("cuixin-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if( (int)me->query_skill("cuixin-zhang", 1 ) < 150 )
               return notify_fail("你现在不能练习催心掌。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练催心掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"cuixin-zhang/" + action;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("cuixin-zhang",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 180)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        //victim->start_busy(3);
        return HIC "「摧心掌!!」$N猛地一个侧身一闪，转到$n身后，右掌往$n后心印了下去。\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 180)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIM "摧心掌!! $n后心一震只觉得喉头一甜一条血丝从嘴角挂了下来！\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("cuixin-zhang", 1);

        if( damage < 10 ) return 1;
          ob->start_busy(2);
            if ( random(12) == 0 || random(level) > 180){
         msg = RED"$N的左足反踢而起，直撩$n的下阴！不待$n退开站稳，右足连环反踢，将$n踢得一时无法还手！\n"NOR;
         msg += RED"「撩阴脚!!」。$N如影随形的踢出几脚，$n吐出一口鲜血!!。\n"NOR;
             ob->add("qi",-(level+100));
             ob->add("eff_qi",-(level+100));

        if (userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12 > 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}

msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, ob);
}

            return damage;
}