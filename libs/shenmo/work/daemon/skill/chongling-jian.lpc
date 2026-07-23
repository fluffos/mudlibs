// 冲灵剑法
// Modified by rcwiz Oct.1997
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "name"  : "青梅如豆",
        "action": "$N手中$w一抖，一招"+(order[random(13)])+"「青梅如豆」"NOR"使出，眼中柔情万千，向$n的$l刺去",
        "force" : 70,
	"attack": 10,
	"parry" : 5,
        "dodge" : 10,
        "damage": 130,
        "lvl"   : 0,
        "damage_type":  "刺伤"
]),
([      "name"  : "雾中初见",
        "action": "$N身法陡快，一招"+(order[random(13)])+"「雾中初见」"NOR"倒使上来，$w直指$n$l",
        "force" : 120,
	"attack": 20,
	"parry" : 15,
        "dodge" : 20,
        "damage": 140,
        "lvl"   : 20,
        "damage_type":  "刺伤"
]),
([      "name"  : "雨后乍逢",
        "action": "$N手中$w反转回来，似攻非攻，但剑身突转，刺向$n，心中似乎藏有万千感慨",
        "force" : 160,
	"attack": 25,
	"parry" : 20,
        "dodge" : 30,
        "damage": 45,
        "lvl"   : 140,
        "damage_type":  "刺伤"
]),
([      "name"  : "同生共死",
        "action": "$N长叹一声，跨步向前，使一招"+(order[random(13)])+"「同生共死」"NOR"，手中$w斜刺而出，不守不防，誓将生死置之度外",
        "force" : 280,
	"attack": 60,
	"parry" : 10,
        "dodge" : 10,
        "damage": 250,
        "lvl"   : 60,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
    object ob;

    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够，没有办法练冲灵剑法。\n");

    if (me->query_skill("huashan-sword", 1) < 100)
        return notify_fail("你华山剑法火候不够，无法练冲灵剑法。\n");

    if (me->query_skill("fanliangyi-dao", 1) < 100)
        return notify_fail("你反两仪刀法火候不够，无法练冲灵剑法。\n");
    if (me->query_skill("feiyan-huixiang", 1) < 100)
        return notify_fail("你飞燕回翔火候不够，无法练冲灵剑法。\n");
    if (me->query_skill("hunyuan-zhang", 1) < 100)
        return notify_fail("你混元掌火候不够，无法练冲灵剑法。\n");
    if (me->query_skill("poyu-quan", 1) < 100)
        return notify_fail("你劈石破玉拳火候不够，无法练冲灵剑法。\n");
    if (me->query_skill("kuangfeng-jian", 1) < 100)
        return notify_fail("你狂风快剑火候不够，无法练冲灵剑法。\n");
                                   


    if (! (ob = me->query_temp("weapon"))
    ||  (string)ob->query("skill_type") != "sword" )
        return notify_fail("你必须先找一把剑才能学习冲灵剑法。\n");

    if (me->query_skill("sword", 1) < me->query_skill("chongling-jian", 1))
	return notify_fail("你的基本剑法火候有限，无法领会更高深的冲灵剑法。\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level = (int) me->query_skill("chongling-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 60)
        return notify_fail("你的体力太低，没有办法练习冲灵剑法。\n");

    if (me->query_skill("huashan-sword", 1) < 100)
        return notify_fail("你华山剑法火候不够，无法练冲灵剑法。\n");
                
    if ((int)me->query("neili") < 40)
        return notify_fail("你的内力不够，没有办法练习冲灵剑法。\n");

    me->receive_damage("qi", 50);
    me->add("neili", -31);
    return 1;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	int damage;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("chongling-jian", 1);
        if (random(me->query_skill("chongling-jian",1)) < 100 ||		             me->query_skill("force",1) < 100 )
        return 0;

	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("zixia-shengong",1);
        level2= (int) me->query_skill("zixia-shengong",1);
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "zixia-shengong")
{
if (random(2)==0)
{
	victim->start_busy(2);
}
else 	victim->receive_wound("qi", (random(damage_bonus))+200);
                  return random(2) ? HIR "$N" HIR "运起紫霞神功，一剑攻出，剑气横飞，,$n双眼一花,不知如何是好!\n" NOR:
                                     HIR "$N" HIR "剑随意走,手中" + weapon->name() + HIR "犹如生了眼睛一般，随意挥出几剑,$n双眼一花,不知如何是好!\n"NOR;
}
	weapon = me->query_temp("weapon");
level2= (int) me->query_skill("zixia-shengong",1);             
	if (random(3)==1 && me->query_skill("zixia-shengong",1)>300)
	{
	if( damage_bonus > 50 && random(level2)>100) {
	victim->receive_wound("qi", (random(damage_bonus)+20));
	return HIG"$N的身形随着剑式一变，剑身闪出无数耀眼的光芒，震出了一片茫茫的剑幕!\n"NOR;
        }
}

}
string perform_action_file(string action)
{
        return __DIR__"chongling-jian/" + action;
}