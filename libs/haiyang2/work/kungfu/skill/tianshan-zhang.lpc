// tianshan-zhang.c, based on dagou-bang.c
// by yucao
// Modified by Hop 97.01.05
// Added by Yzuo 97.04.08

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([  "action": "$N高举$w, 一招"+(order[random(13)])+"「雪海冰雹」"NOR"，从天而降砸向$n的$l",
        "dodge": 10,
        "force" : 170,
        "damage": 225,
        "lvl" : 3,
        "damage_type": "砸伤"
]),

([  "action": "$N使出一招"+(order[random(13)])+"「天山雪野」"NOR"，手中$w封住下盘扫向$n的$l",
        "dodge": 1,
        "force" : 100,
        "damage": 250,
        "lvl" : 5,
        "damage_type": "砸伤"
]),

([  "action": "$N使出一招"+(order[random(13)])+"「满天飞雪」"NOR"，挥动手中$w从各个方向点往$n的$l",
        "dodge": -3,
        "force" : 150,
        "damage": 180,
        "lvl" : 55,
        "damage_type": "刺伤"
]),

([  "action": "忽听得呼一声猛响，$N一招"+(order[random(13)])+"「雪峰插云」"NOR"，手握$w飞身砸向$n的$l",
        "dodge": -10,
        "force" : 200,
        "damage": 110,
        "lvl" : 79,
        "damage_type": "砸伤"
]),
([	"action": "$N使出一招"+(order[random(13)])+"「冰河开冻」"NOR"，手中$w大开大阖扫向$n的$l",
	"force" : 80,
	"dodge": 30,
	"damage": 140,
	"lvl" : 1,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w阵阵风响，一招"+(order[random(13)])+"「山风凛冽」"NOR"向$n的$l攻去",
	"force" : 140,
	"dodge": 50,
	"damage": 170,
	"lvl" : 13,
	"damage_type": "挫伤"
]),
([	"action": "$N举起$w，居高临下使一招"+(order[random(13)])+"「天山雪崩」"NOR"砸向$n的$l",
	"force" : 200,
	"dodge": 70,
	"damage": 200,
	"lvl" : 30,
	"damage_type": "挫伤"
]),
([	"action": "$N一招"+(order[random(13)])+"「残阳照雪」"NOR"，纵身飘开数尺，手中$w砸向$n的$l",
	"force" : 240,
	"dodge": 80,
	"damage": 220,
	"lvl" : 45,
	"damage_type": "挫伤"
]),
([	"action": "$N使一招"+(order[random(13)])+"「回光幻电」"NOR"，手中$w幻一条疾光点向$n的$l",
	"force" : 270,
	"dodge": 120,
	"damage": 230,
	"lvl" : 60,
	"damage_type": "挫伤"
]),
([	"action": "$N使出的"+(order[random(13)])+"「风霜碎影」"NOR"，$w连挥杖影霍霍劈向$n的$l",
	"force" : 300,
	"dodge": 120,
	"damage": 330,
	"lvl" : 75,
	"damage_type": "挫伤"
]),
([	"action": "$N的$w凭空一指，一招"+(order[random(13)])+"「断石狼烟」"NOR"点向$n的$l",
	"force" : 320,
	"dodge": 120,
	"damage": 340,
	"lvl" : 90,
	"damage_type": "挫伤"
]),
([	"action": "$N纵身一跃，手中$w一招"+(order[random(13)])+"「长空雷隐」"NOR"对准$n的$l扫去",
	"force" : 340,
	"dodge": 140,
	"damage": 350,
	"lvl" : 105,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w中宫直进，一式"+(order[random(13)])+"「冰谷初虹」"NOR"对准$n的$l点去",
	"force" : 350,
	"dodge": 140,
	"damage": 360,
	"lvl" : 120,
	"damage_type": "挫伤"
]),
([	"action": "$N一招"+(order[random(13)])+"「峰回路转」"NOR"，$w左右迂回向$n的$l点去",
	"force" : 380,
	"dodge": 150,
	"damage":480,
	"lvl" :  145,
	"damage_type": "挫伤"
]),
});

mapping query_action(object me, object weapon)
{
        int i, level,lvl_temp;
       lvl_temp = random((int)me->query_skill("tianshan-zhang", 1)+(int)me->query_skill("staff"));
        if (( (int)me->query_skill("staff", 1) >= 150 ) 
        &&      ( (int)me->query_skill("tianshan-zhang", 1) >= 150 )
        &&      ( (int)me->query_skill("huagong-dafa",1) >= 150 )
        &&      ( (int)me->query("neili") >= 800 )
        && (int)me->query_skill("poison",1) >= 100  
       &&      ( lvl_temp>=150)) {
return ([
       "action": BLU "$N嘿嘿一阵阴笑,伸手向杖端一抹,$w旋转挥动，声势更为凌厉!" NOR,
                "damage": lvl_temp+(int)me->query_str(),
                "parry":(int)me->query_skill("dodge")/5,
                "damage": 700,
                "force": 700,
                "damage_type": "砸伤"]);
}
      level=(int)me->query_skill("tianshan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{     
        int lvl_temp;
                int lvl;
        int flvl;

        lvl  = me->query_skill("tianshan-zhang", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "huagong-dafa" ||
            me->query("neili") < 300)
                return;
       lvl_temp = random((int)me->query_skill("tianshan-zhang", 1)+(int)me->query_skill("staff"));
        if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-600);
                return HIY "$n" HIY "感到内力如雪花融化一样，消失了。。\n" NOR;
        }
else
        if (random(5)==0)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
victim->apply_condition("xx_poison",20);
victim->apply_condition("x2_sandu",20);
victim->apply_condition("sanpoison",20);
                return HIY "$n" HIY "感到肌肤便似腐烂一般，散发出一股极难"
               "闻的恶臭。。\n" NOR;
        }
        if (lvl_temp >=140) {
        if( random(lvl_temp) <= 100) 
        {
        victim->apply_condition("xx_poison", random((me->query_skill("huagong-dafa")
        +me->query_skill("poison",1))/30) + 1 + victim->query_condition("xx_poison"));
        tell_object(victim, HIG "你觉得眼前一阵发晕!似乎中了毒\n" NOR );
        tell_object(victim, HIG "原来对方杖上抹的毒药正在散发着毒气！\n" NOR );
        } else if( random(lvl_temp) > 100) {
victim->apply_condition("xx_poison", random((me->query_skill("huagong-dafa")
        +me->query_skill("poison",1))/15) + 1 + victim->query_condition("xx_poison"));
        tell_object(victim, HIG "你觉得被击中的地方一阵麻木!似乎中了毒\n" NOR );
        tell_object(victim, HIG "原来对方的杖上涂抹有毒药!\n" NOR );

        }
      }
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 80)
		return notify_fail("你的内力不够。\n");
	return 1;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("huagong-dafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/7;
if (damage2>= 5000) damage2 = 5000;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "huagong-dafa")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIY"$N使出化功大法,$n到内力如雪花融化一样，消失了。。\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练天山杖法。\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianshan-zhang/" + action;
}
