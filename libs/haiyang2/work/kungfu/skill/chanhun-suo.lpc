#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": "$N单手一扬，一招"+(order[random(13)])+"「虐目」"NOR"，手中$w抖得笔直，直点$n的双眼",
        "force" : 110,
        "dodge" : 12,
        "parry" : 10,
        "damage": 235,
        "lvl"   : 0,
        "skill_name" : "虐目",
        "damage_type": "刺伤"
]),
([      "action": "$N力贯鞭梢，一招"+(order[random(13)])+"「伤肝」"NOR"，手中$w舞出满天鞭影，横扫$n腰间",
        "force" : 140,
        "dodge" : 17,
        "parry" : 15,
        "damage": 250,
        "lvl"   : 20,
        "skill_name" : "伤肝",
        "damage_type": "劈伤"
]),
([      "action": "$N运气于腕，一招"+(order[random(13)])+"「损心」"NOR"，手中$w向一根铜棍般直击$n胸部",
        "force" : 180,
        "dodge" : 21,
        "parry" : 19,
        "damage": 243,
        "lvl"   : 40,
        "skill_name" : "损心",
        "damage_type": "内伤"
]),
([      "action": "$N单臂一挥，一招"+(order[random(13)])+"「催胆」"NOR"，手中$w直击向$n腰肋",
        "force" : 215,
        "dodge" : 32,
        "parry" : 27,
        "damage": 258,
        "lvl"   : 60,
        "skill_name" : "催胆",
        "damage_type": "劈伤"
]),
([      "action": "$N高高跃起，一招"+(order[random(13)])+"「摄魄」"NOR"，手中$w笔直向$n当头罩下",
        "force" : 255,
        "dodge" : 42,
        "parry" : 37,
        "damage": 275,
        "lvl"   : 80,
        "skill_name" : "摄魄",
        "damage_type": "劈伤"
]),
([      "action": "$N身形一转，一招"+(order[random(13)])+"「收魂」"NOR"，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
        "force" : 330,
        "dodge" : 87,
        "parry" : 69,
        "damage": 281,
        "lvl"   : 100,
        "skill_name" : "收魂",
        "damage_type": "劈伤"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        object weapon;

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("你必须先找一条鞭子才能练习缠魂索。\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("你的化功大法火候不够.\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("你的三阴蜈蚣爪火候不够.\n");



	if ((int)me->query_skill("chousui-zhang", 1) < 120)
		return notify_fail("你的抽髓掌火候不够.\n");


	if ((int)me->query_skill("tianshan-zhang", 1) < 120)
		return notify_fail("你的天山杖法火候不够.\n");


	if ((int)me->query_skill("zhaixinggong", 1) < 120)
		return notify_fail("你的摘星功火候不够.\n");
        if( (int)me->query("max_neili") < 400 )
                return notify_fail("你的内力不足，没有办法练习缠魂索。\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("whip", 1) < 60)
                return notify_fail("你的基本鞭法火候太浅。\n");

        if (((int)me->query_skill("whip", 1)+150) < (int)me->query_skill("ruanhong-zhusuo", 1))
                return notify_fail("你的基本鞭法水平还不够，无法领会更高深的缠魂索。\n");


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
        level   = (int) me->query_skill("chanhun-suo",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("你的化功大法火候不够.\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("你的三阴蜈蚣爪火候不够.\n");
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力不够练缠魂索。\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练缠魂索。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"chanhun-suo/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("chanhun-suo", 1);
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
	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 10) / 2+30 );
		return HIR "$N向前急进，手中$w圈转如虹，三道鞭影，罩向$n全身! \n" NOR;
	}
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("chanhun-suo",1);
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

weapon = me->query_temp("weapon");
if (weapon)
{
        if (  level2 > 150
        && random(5)==1
        && (string)weapon->query("skill_type") == "whip"){
 
            msg = HIW"$n出招时，$N身形一转 鞭舞全身，$n无法近身，也无法进攻!!\n"NOR;
   if (!ob->is_busy())
             ob->start_busy(3);
message_vision(msg, me, ob);
               }


}



}