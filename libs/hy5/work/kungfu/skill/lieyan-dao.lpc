// lieyan-dao.c 烈焰刀
#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「黑龙现身」，$w有如一条黑龙在$n的周身旋游，勿快勿慢，变化若神",
        "force" : 180,
        "dodge" : 10,
        "damage" : 120,
        "lvl" : 0,
        "skill_name" : "黑龙现身",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「万水千山」，左右腿一前一后，$w乱披风势向$n的$l斩去",
        "force" : 190,
        "dodge" : 10,
        "damage" : 130,
        "lvl" : 8,
        "skill_name" : "万水千山",
        "damage_type" : "割伤"
]),
([      "action" : "$N纵身跃落，一招「横扫千里」，$w带着疾风呼的一声便向$n横扫过去",
        "force" : 110,
        "dodge" : 5,
        "damage" : 140,
        "lvl" : 16,
        "skill_name" : "横扫千里",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「左右开弓」，$w大开大阖，左右并进，左一刀，右一刀向$n的两肩砍落",
        "force" : 130,
        "dodge" : 5,
        "damage" : 150,
        "lvl" : 24,
        "skill_name" : "左右开弓",
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w自上而下，一招「百丈飞瀑」，刀光流泻，如一片雪白瀑布砍向$n的头部",
        "force" : 150,
        "dodge" : 10,
        "damage" : 160,
        "lvl" : 33,
        "skill_name" : "百丈飞瀑",
        "damage_type" : "割伤"
]),
([      "action" : "$N挥舞$w，使出一招「直摧万马」，上劈下撩，左挡右开，如千军万马般罩向$n",
        "force" : 170,
        "dodge" : 5,
        "damage" : 170,
        "lvl" : 42,
        "skill_name" : "直摧万马",
        "damage_type" : "割伤"
]),
([      "action" : "$N带得刀风劲疾，一招「怪蟒翻身」，一个猛转身，连刀带人往$n的$l的劈去",
        "force" : 190,
        "dodge" : 5,
        "damage" : 180,
        "lvl" : 51,
        "skill_name" : "怪蟒翻身",
        "damage_type" : "割伤"
]),
([      "action" : "$N向前一个弓步，一招「上步劈山」，$w直直的劈出，一片流光般的刀影向$n的全身罩去",
        "force" : 320,
        "dodge" : 5,
        "damage" : 300,
        "lvl" : 60,
        "skill_name" : "上步劈山",
        "damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("你的九阳神功火候太浅。\n");
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
        level   = (int) me->query_skill("lieyan-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        int lvl = me->query_skill("lieyan-dao", 1);
        int i = sizeof(action);
        while (i--) if (lvl == action[i]["lvl"]) return 0;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jing") < 50)
                  return notify_fail("你的精力不够练烈焰刀。\n");
        me->receive_damage("jing", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"lieyan-dao/" + action;
}

mixed ob_hit(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");

        int ap, dp;
        string result;

	ap = (int)me->query("combat_exp",1)+(int)victim->query_skill("parry",1);

        dp = victim->query("combat_exp",1);
        if (objectp(weapon1))
                dp += victim->query_skill("dodge");
if (random(me->query_skill("jiuyang-shengong",1)) > 130
&& me->query("neili") < me->query("max_neili")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)
{
message_vision(HIR"$N运起九阳神功，全身内力源源不断的涌出!\n"NOR,me, victim);
me->add("neili",(random(me->query_skill("jiuyang-shengong",1))+180));
}

if (random(me->query_skill("jiuyang-shengong",1)) > 120
&& me->query("qi") < me->query("max_qi")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)
{
message_vision(RED"$N运起九阳神功，身上的伤好了很多!\n"NOR,me, victim);
me->add("qi",random(me->query_skill("jiuyang-shengong",1))+200);
if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi",random(me->query_skill("jiuyang-shengong",1))+200);
}


if (random(me->query_skill("qiankun-danuoyi",1)) > 120
&& me->is_busy()
&& me->query_skill_mapped("force") == "jiuyang-shengong"
&& random(2)==0
)
{
message_vision(HIC"$N暗运乾坤大挪移，本来忙乱的动作快了起来!\n"NOR,me, victim);
me->start_busy(1);
}
        if ( random(ap) > dp/3 
        && me->query("jiuyangok")
        && (int)me->query_temp("shield")
        && me->query_skill_mapped("force") == "jiuyang-shengong"
        ) {
                if ( objectp(weapon1)) {
                        if (damage + damage_bonus > 0)
                        {                 
				damage_bonus=-damage/3;
                                result = HIM"$n身子一侧，将$N兵刃上的力道卸去大半。\n"NOR;
                        }
                        else {
				result = MAG"$n身子一侧，将$N兵刃上的力道卸去大半。\n"NOR;
				damage_bonus=-damage/3;
			}
                }
                else if(!objectp(weapon1)){
                        if (damage + damage_bonus > 0)
			{
				damage_bonus=-damage/2;
			        result = HIG"$n九阳神功自然而然发出抗力，将$N的力道一挡。\n"NOR;                      
			}
                	else {
				result = MAG"$n九阳神功自然而然发出抗力，将$N的力道一挡。\n"NOR;
				damage_bonus=-damage/2;
			}
		}	

	}
if (result)
        message_vision(result,me,victim);
        return damage;
}




mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl,nlvl;

        lvl = me->query_skill("jiuyang-shengong", 1);
        nlvl = me->query_skill("liuyan-dao", 1);

        if (damage_bonus < 50
           || lvl < 150
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "jiuyang-shengong"
           || me->query_skill_mapped("unarmed") != "jiuyang-shengong"
		|| !me->query("jiuyangok") )
		return 0;

        if ((random(3)==0 && damage_bonus / 5 > victim->query_con()) || random(8)==0)
        {
	        me->add("neili", -5);
                victim->receive_wound("qi", (random(nlvl)) / 2+10, me);
                return random(2) ? HIR "只见$N" HIR "九阳内劲自体内迸发，真气随招式"
                                   "而荡漾，摧毁了$n" HIR "的真元！\n" NOR:

                                   HIR "$N" HIR "九阳神功的潜力发挥了出来，突然间$n"
                                   HIR "只感喉咙一甜，喷出一口鲜血！\n" NOR;
        }
}