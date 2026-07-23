// ruanhong-zhusuo.c 软红蛛索
// by Vin 2000

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N端坐不动，一式「天蛛盘丝」，手腕力抬，$w滚动飞舞，宛如灵蛇乱颤扫向$n",
        "force" : 198,
        "attack": 141,
        "dodge" : 5,
        "parry" : 15,
        "damage": 332,
        "lvl"   : 0,
        "damage_type": "抽伤"
]),
([      "action": "$N一式「蛛丝马迹」，$w抖得笔直，“呲呲”破空声中向$n疾刺而去",
        "force" : 187,
        "attack": 148,
        "dodge" : 120,
        "parry" : 36,
        "damage": 347,
        "lvl"   : 80,
        "damage_type": "刺伤"
]),
([      "action": "$N内劲到处，将$w抖动转成两个圆圈，一式「灵蛛夺食」，从半空中往$n缠下",
        "force" : 231,
        "attack": 65,
        "dodge" : 110,
        "parry" : 55,
        "damage": 393,
        "lvl"   : 100,
        "damage_type": "抽伤"
]),
([	"action": "$N劲走螺旋，一式「蛛网织天」，$w在$n眼前连变数种招式，忽然从$l处倒卷上来",
        "force" : 263,
        "attack": 170,
	"dodge" : 5,
        "parry" : 60,
	"damage": 302,
	"lvl"   : 120,
	"damage_type": "抽伤"
]),
([	"action": "$N一声高喝，使出「龙蛛捉蟒」，$w急速转动，鞭影纵横，似真似幻，绞向$n",
        "force" : 301,
        "attack": 177,
	"dodge" : 6,
        "parry" : 65,
	"damage": 321,
	"lvl"   : 140,
	"damage_type": "抽伤"
]),
([	"action": "$N含胸拔背，一式「金蛛银索」，力道灵动威猛，劲力从四面八方向$n挤压出去",
        "force" : 331,
        "attack": 85,
	"dodge" : 12,
        "parry" : 70,
	"damage": 142,
	"lvl"   : 160,
	"damage_type": "抽伤"
]),
([	"action":"$N力贯鞭梢，一招「天虹密布」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
        "force" : 373,
        "attack": 191,
	"dodge" : 17,
        "parry" : 75,
	"damage": 363,
	"lvl"   : 180,
	"damage_type": "抽伤"
]),
([	"action":"$N力贯鞭梢，一招「天地蚕食」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
        "force" : 401,
        "attack": 198,
	"dodge" : 20,
        "parry" : 85,
	"damage": 389,
	"lvl"   : 200,
	"damage_type": "抽伤"
]),
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

int valid_learn(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("你必须先找一条鞭子才能练软红蛛索。\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力不足，没有办法练软红蛛索，多练些内力再来吧。\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的内功火候太浅，没有办法练软红蛛索。\n");

        if ((int)me->query_skill("whip", 1) < 100)
                return notify_fail("你的基本鞭法火候太浅，没有办法练软红蛛索。\n");
 
 if ((int)me->query_skill("chilian-shenzhang", 1) < 150)
   return notify_fail("你的赤练神掌火候不够，无法学。\n");

 if ((int)me->query_skill("jueqing-bian", 1) < 150)
   return notify_fail("你的绝情鞭法不够，无法学。\n");

        if (((int)me->query_skill("whip", 1)+100) < (int)me->query_skill("ruanhong-zhusuo", 1))
                return notify_fail("你的基本鞭法水平还不够，无法领会更高深的软红蛛索。\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("ruanhong-zhusuo",1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力不够练软红蛛索。\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("你的内力不够练软红蛛索。\n");

 if ((int)me->query_skill("chilian-shenzhang", 1) < 150)
   return notify_fail("你的赤练神掌火候不够，无法学。\n");

 if ((int)me->query_skill("jueqing-bian", 1) < 150)
   return notify_fail("你的绝情鞭法不够，无法学。\n");
 
        me->receive_damage("qi", 75);
        me->add("neili", -85);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"ruanhong-zhusuo/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("wudu-shengong",1);
        level2= (int) me->query_skill("wudu-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "wudu-shengong")
{
if (!victim->is_busy()) victim->start_busy(3);	
if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",damage2);
if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",damage2);
 return HIG "$N使出五毒神功！舔了舔$n流出的鲜血，全身的伤好像好了很多！!\n";
}
 


if (damage_bonus <30) damage_bonus=30;
      if( random(me->query_skill("ruanhong-zhusuo",1)) > 30 ) 
{
	  victim->receive_wound("qi", damage_bonus/2);
        return HIM "$n身中巨毒，闷哼一声,身子晃了两晃！\n" NOR;
}
      if (random(me->query_skill("ruanhong-zhusuo",1)) > 150 ) {
	 switch( random(5) ) {
		case 0:
            victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("snake_poison"));
			break;
		case 1:
            victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("zhizhu_poison"));
			break;
		case 2:
            victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("wugong_poison"));
			break;
		case 3:
            victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("xiezi_poison"));
			break;
		case 4:
            victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("chanchu_poison"));
			break;
	}
        return HIR "$n只觉得伤处一阵发麻，似乎中毒了。\n" NOR;
   }
}