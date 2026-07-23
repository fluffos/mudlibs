// luoying-zhang.c 落英神剑掌
// modified by Venus Oct.1997
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$N双手平伸，向外掠出，一式「春云乍展」，指尖轻盈漂动，
轻轻反点$n的$l",
        "force" : 100,
        "dodge" : 45,
        "damage" : 130,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "春云乍展"
]),
([      "action" : "$N右手五指缓缓一收，一式「回风拂柳」，五指忽然遥遥拂向$n，
$n只觉得五股疾风袭向自己五处大穴",
        "force" : 110,
        "dodge" : 60,
        "damage" : 160,
        "damage_type" : "内伤",
        "lvl" : 0,
        "skill_name" : "回风拂柳"
]),
([      "action" : "$N突然纵身跃入半空，一个轻巧转身，单掌劈落，一式「江城飞
花」，拍向$n的头顶",
        "force" : 120,
        "damage" : 100,
        "dodge" : 185,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "江城飞花"
]),
([      "action" : "$N突然跃起，双手连环，运掌如剑，势如疾风电闪，一式「雨急风
狂」，攻向$n的全身",
        "force" : 130,
        "dodge" : 105,
        "damage" : 150,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "雨急风狂"
]),
([      "action" : "$N左手挥起，掌心朝天，伸出右手并拢食指中指，捻个剑决，一式
「星河在天」，直指$n的中盘",
        "force" : 140,
        "dodge" : 120,
        "damage" : 200,
        "damage_type" : "瘀伤",
        "lvl" : 20,
        "skill_name" : "星河在天"
]),
([      "action" : "$N突然抽身而退，接着一式「流华纷飞」，平身飞起，双掌向$n
的后脑连拍数掌",
        "force" : 140,
        "dodge" : 145,
        "damage" : 230,
        "damage_type" : "瘀伤",
        "lvl" : 30,
        "skill_name" : "流华纷飞"
]),
([      "action" : "$N突然抽身跃起，左掌挟着劲风汹涌拍出，接着右掌自左掌后突地
伸出，一式「彩云追月」抢在左掌前向$n的$l拍去",
        "force" : 150,
        "dodge" : 165,
        "damage" : 250,
        "damage_type" : "瘀伤",
        "lvl" : 30,
        "skill_name" : "彩云追月"
]),
([      "action" : "$N使一式「天如穹庐」，全身突然飞速旋转，双掌忽前忽后，猛
地拍向$n的胸口",
        "force" : 160,
        "dodge" : 180,
        "damage" : 300,
        "damage_type" : "瘀伤",
        "lvl" : 40,
        "skill_name" : "天如穹庐"
]),
([      "action" : "$N前后一揉，一式「朝云横度」，化掌如剑，一股凌厉剑气袭向$n
的下盘",
        "force" : 170,
        "dodge" : 200,
        "damage" : 300,
        "damage_type" : "内伤",
        "lvl" : 50,
        "skill_name" : "朝云横度"
]),
([      "action" : "$N使一式「白虹经天」，双掌舞出无数圈劲气，一环环向$n的$l
斫去",
        "force" : 180,
        "parry" : 15,
        "damage" : 300,
        "dodge" : 200,
        "damage_type" : "内伤",
        "lvl" : 70,
        "skill_name" : "白虹经天"
]),
([      "action" : "$N双手食指和中指一和，一式「紫气东来」，一股强烈的气流涌向
$n的全身",
        "force" : 190,
        "parry" : 5,
        "damage" : 320,
        "dodge" : 200,
        "damage_type" : "内伤",
        "lvl" : 60,
        "skill_name" : "紫气东来"
]),
([      "action" : "$N一式「落英漫天」，双掌在身前疾转，掌花飞舞，铺天盖地直指
向$n。$n只见漫天掌花，眼花缭乱。",
        "force" : 200,
        "parry" : 20,
        "damage" : 350,
        "dodge" : 200,
        "damage_type" : "瘀伤",
        "lvl" : 99,
        "skill_name" : "落英漫天"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; } 

int valid_combine(string combo) { return combo=="xuanfeng-leg"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练落英神剑掌必须空手。\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 15)
        return notify_fail("你的碧波神功火候不够，无法学落英神剑掌。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练落英神剑掌。\n");
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
    level = (int)me->query_skill("luoying-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("你的内力不够练落英神剑掌。\n");
    me->receive_damage("qi", 20);
    me->add("neili", -1);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"luoying-zhang/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
       string msg;
       int j, k;
       j = me->query_skill("yuxiao-jian", 1);
       k = me->query_skill("qimen-wuxing",1);
 level = (int) me->query_skill("bibo-shengong",1);
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "bibo-shengong")
        {
if (victim->query("qi") > 600)
victim->add("qi",-250+random(200));
victim->add("eff_qi",-(50+random(200)));
                me->add("neili", -20);
if (!victim->is_busy()) victim->start_busy(1);
return HIR "$N施展开奇门五行,$n心神一乱,被打中$l。结果鲜血狂奔!!\n";
        }
	weapon = me->query_temp("weapon");
level2= (int) me->query_skill("luoying-zhang",1);             
	if (random(5)==1 && me->query_skill("luoying-zhang",1)>100)
	{
	if (!victim->is_busy())
	victim->start_busy(2);
	return HIR"$N脚走五行,$n二眼一花不知所知!!\n"NOR;
	}
	if( damage_bonus > 80 && random(level2)>80) {
	victim->receive_wound("qi", (random(damage_bonus)+150));
	return HIB"$n被一掌击中$l要害，顿时痛不欲生!!\n"NOR;
        }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("luoying-zhang", 1);
level2 = me->query_skill("luoying-zhang", 1);
        if (  level2 > 100
        && random(5)==1){
 
            msg = HIC"$n出招时，$N脚踏五行，$n心头一乱!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
               }

}