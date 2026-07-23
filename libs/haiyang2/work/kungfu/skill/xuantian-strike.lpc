#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": HIG"$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l"NOR,
        "dodge": 20,
        "force": 100,
        "damage": 100,	
        "damage_type": "瘀伤"
]),
([      "action": HIM"$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l"NOR,
        "dodge": 30,
        "force": 200,
        "damage": 100,	
        "damage_type": "瘀伤"
]),
([      "action": HIC"$N双掌挟着一股强大的气流拍向$n的$l"NOR,
        "dodge": 40,
	"force": 300,
	"damage": 100,	
	"damage_type": "瘀伤"
]),
([      "action": HIW"$N脸上露出诡异的笑容，双掌携满寒霜，横扫$n"NOR,
        "dodge" : 30,
        "attack": 79,
        "parry" : 37,
        "dmage" : 52,
        "force" : 430,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
        "dodge" : 22,
        "attack": 96,
        "parry" : 34,
        "dmage" : 67,
        "force" : 490,
        "damage_type": "瘀伤"
]),
([      "action": "$N将冰蚕寒毒运至右手，阴毒无比地拍向$n的$l",
        "dodge" : 20,
        "attack": 113,
        "parry" : 10,
        "dmage" : 82,
        "force" : 530,
        "damage_type": "瘀伤"
]),
([      "action": HIW"$N诡异的一笑，双掌带着凌厉的寒气拍向$n的$l"NOR,
        "dodge" : 28,
        "attack": 139,
        "parry" : 36,
        "dmage" : 95,
        "force" : 580,
        "damage_type": "瘀伤"
]),
([      "action": "$N仰天一声长啸，聚集全身的力量击向$n",
        "dodge" : 27,
        "attack": 161,
        "parry" : 21,
        "dmage" : 105,
        "force" : 640,
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="sanyin-wugongzhao" || combo=="chousui-zhang"; }
mapping query_action(object me)
{
        if (random(me->query_skill("unarmed")) > 100 &&
            me->query_skill("force") > 100 &&
            me->query_skill("xuantian-strike") > 100 &&
            me->query("force") > 1000 ) {
                me->add("force", -100);
                return ([
                "action": HIW"$N咬破舌尖，口中喷血，双掌带着凌厉的寒气拍向$n的$l"NOR,
                "parry": 50,
                "dodge": 50,
                "force": 400,
                "damage": 500,                	
                "damage_type": "瘀伤"]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练玄天冰蚕掌必须空手。\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
                return notify_fail("你的化功大法火候不够，无法练玄天冰蚕掌。\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("你的三阴蜈蚣爪火候不够.\n");



	if ((int)me->query_skill("chousui-zhang", 1) < 120)
		return notify_fail("你的抽髓掌火候不够.\n");


	if ((int)me->query_skill("tianshan-zhang", 1) < 120)
		return notify_fail("你的天山杖法火候不够.\n");


	if ((int)me->query_skill("zhaixinggong", 1) < 120)
		return notify_fail("你的摘星功火候不够.\n");
		
	if ((int)me->query_skill("chanhun-suo", 1) < 120)
		return notify_fail("你的缠魂索火候不够.\n");
        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力太弱，无法练玄天冰蚕掌。");
	return 1;
}


int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练玄天冰蚕掌。\n");
        if (me->query_skill("xuantian-strike", 1) < 50)
                me->receive_damage("qi", 45);
	else
                me->receive_damage("qi", 35);
        me->add("neili", -8);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object weapon = me->query_temp("weapon");     
        string msg;
        int lvl;
        int flvl;

        lvl  = me->query_skill("xuantian-strike", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "huagong-dafa" ||
            me->query("neili") < 300)
                return;
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


        if (((int)me->query_skill("xuantian-strike", 1)/2) > random((int)victim->query_skill("force", 1)))
        {
                victim->receive_wound("qi", (damage_bonus/5)+60);
                return HIW "$n" HIW "只感一阵极寒从心底升起，看来是中了$N" HIW "掌上的冰蚕内力。\n" NOR;
        }
}

string perform_action_file(string action)
{
    return __DIR__"xuantian-strike/" + action;
}

int effective_level() { return 20;}
 
string *parry_msg = ({
        "$n双掌微合，「啪」的一声将$N的$w夹在双掌之间。\n",
        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n双掌一挥，一股大力将$N送出丈外。\n",
        "$n略一转身，单掌拍向$N拿着$w的手。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return -100;
}
int practice_bonus()
{
        return -50;
}
int black_white_ness()
{
	return 100;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("xuantian-strike",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/7;
if (damage2>= 5000) damage2 = 5000;
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "huagong-dafa")
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