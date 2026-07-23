// xuanfeng-leg.c 旋风扫叶腿
// modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N双手虚晃，左脚猛地飞起，一式"+(order[random(13)])+"「风起云涌」"NOR"，脚尖晃动，踢
向$n的屁股",
        "damage" : 300,
        "dodge" : 15,
        "force" : 115,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "风起云涌"
]),
([      "action" : "$N左脚顿地，别转身来抽身欲走，只一刹那间一回身，右脚一式
"+(order[random(13)])+"「空谷足音」"NOR"，猛踹$n的$l",
        "damage" : 320,
        "force" : 50,
        "dodge" : 110,
        "damage_type" : "瘀伤",
        "lvl" : 0,
        "skill_name" : "空谷足音"
]),
([      "action" : "$N左手一挣，反手扭搭住$n的右手，右脚同时踹出，既猛且准，一
式"+(order[random(13)])+"「碧渊腾蛟」"NOR"，踢中的$n的胸口",
        "damage" : 340,
        "dodge" : 15,
        "force" : 110,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "碧渊腾蛟"
]),
([      "action" : "$N突然跃起，双足连环圈转，一式"+(order[random(13)])+"「秋风落叶」"NOR"，足带风尘，攻向
$n的全身",
        "damage" : 360,
        "force" : 150,
        "dodge" : 15,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "秋风落叶"
]),
([      "action" : "$N两手护胸，双脚交叉踢起，一式"+(order[random(13)])+"「风扫残云」"NOR"，脚脚不离$n的面
门左右",
        "damage" : 280,
        "force" : 180,
        "dodge" : 20,
        "damage_type" : "瘀伤",
        "lvl" : 20,
        "skill_name" : "风扫残云"
]),
([      "action" : "$N突然侧身，却步后退，一个前空翻，右脚自上而下一式"+(order[random(13)])+"「流星坠
地」"NOR"，照$n的面门直劈下来",
        "force" : 200,
        "damage" : 300,
        "dodge" : 35,
        "damage_type" : "瘀伤",
        "lvl" : 30,
        "skill_name" : "流星坠地"
]),
([      "action" : "$N使一式"+(order[random(13)])+"「朔风吹雪」"NOR"，全身突然飞速旋转，双足忽前忽后，迅猛
无极踹向$n的胸口",
        "force" : 250,
        "damage" : 320,
        "dodge" : 30,
        "damage_type" : "瘀伤",
        "lvl" : 40,
        "skill_name" : "朔风吹雪"
]),
([      "action" : "$N抽身跃起，开声吐气，大喝一声：嗨！一式"+(order[random(13)])+"「雷动九天」"NOR"，双脚
如旋风般踢向$n的$l",
        "force" : 350,
        "damage" : 350,
        "dodge" : 35,
        "damage_type" : "瘀伤",
        "lvl" : 30,
        "skill_name" : "雷动九天"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="leg"; } 

int valid_combine(string combo) { return combo=="luoying-zhang"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("旋风扫叶腿必须空手。\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 15)
        return notify_fail("你的碧波神功火候不够，无法学旋风扫叶腿。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练旋风扫叶腿。\n");
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
    level = (int)me->query_skill("xuanfeng-leg", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("你的内力不够练旋风扫叶腿。\n");
    me->receive_damage("qi", 20);
    me->add("neili", -1);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"xuanfeng-leg/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
       string msg;
       int j, k;
 //int level;
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
level2= (int) me->query_skill("xuanfeng-leg",1);             
	if (random(5)==1 && me->query_skill("xuanfeng-leg",1)>100)
	{
	if (!victim->is_busy())
	victim->start_busy(2);
	return HIR"$N脚走五行,$n二眼一花不知所知!!\n"NOR;
	}
	if( damage_bonus > 80 && random(level2)>60) {
	victim->receive_wound("qi", (random(damage_bonus)+50));
	return HIB"$n被一脚踢中$l要害，顿时痛不欲生!!\n"NOR;
        }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("xuanfeng-leg", 1);
level2 = me->query_skill("xuanfeng-leg", 1);
        if (  level2 > 100
        && random(5)==1){
 
            msg = HIC"$n出招时，$N脚踏五行，$n心头一乱!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
               }

}
