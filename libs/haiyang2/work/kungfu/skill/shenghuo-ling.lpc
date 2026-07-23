// Shenghuo-ling  圣火令法
// Shark , 98/10/01 国庆
// 【超频】Ultra Mind Studio ,Copyright 1998

#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([  "action": ""+(order[random(13)])+"$N踏上一步，忽地在地上一坐，已抱住了$n小腿。十指扣住了$n小腿上
的‘中都’‘筑宾’两穴，$n只觉下半身酸麻难动，大吃一惊"NOR"",
        "force" : 150,
        "dodge" : 20,
"parry" : 20,
    "damage": 200,
    "damage_type": "挫伤"
]),
([  "action": ""+(order[random(13)])+"突然之间，$N身形晃动，同时欺近，手中$w往$n身上划去。脚下不知如何
移动，身形早变。右手同时抓住$n后领，一抖之下，将$n向外远远掷了出去"NOR"",
        "force" : 150,
"parry" : 20,
    "dodge": 20,
    "damage": 200,
    "damage_type": "挫伤"
]),
([  "action": ""+(order[random(13)])+"$N欺身直进，左手持$w向$n天灵盖上拍落。便在这一瞬之间，$n滚身向
左，已然一拳打在$n腿上。$n一个踉跄，$N横过$w戳向$n后心"NOR"",
    "dodge": 30,
"parry" : 20,
        "force" : 150,
    "damage": 220,
    "damage_type": "刺伤"
]),
([  "action": ""+(order[random(13)])+"$N忽地放手，手中那柄$w尾端向上弹起，拍的一响，正好打中$n手腕。"NOR"",
"parry" : 20,
        "force" : 150,
    "dodge": 20,
    "damage": 290,
    "damage_type": "刺伤"
]),
([  "action": ""+(order[random(13)])+"$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口
一痛，已被$N手肘撞中"NOR"",
        "force" : 150,
"parry" : 20,
    "dodge": 20,
    "damage": 280,
    "damage_type": "瘀伤"
]),
([  "action": ""+(order[random(13)])+"$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口
$N手中$w急挥横扫，突然连翻三个空心筋斗。$n不知对方是何用意，心想还是避之
为妙，刚向左踏开一步，眼前白光急闪，$N的$w已到右肩"NOR"",
        "force" : 250,
"parry" : 20,
    "dodge": 20,
    "damage": 230,
    "damage_type": "挫伤"
]),
([  "action": ""+(order[random(13)])+"$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口
一痛，已被$N手肘撞中"NOR"",
        "force" : 250,
"parry" : 20,
    "dodge": 20,
    "damage": 250,
    "damage_type": "挫伤"
]),
([      "action" : ""+(order[random(13)])+"$N将手中$w横挥，一式「横扫千军」，$w带出一股风声，疾驶向$n的咽喉"NOR"",
        "skill_name" : "横扫千军",
        "force" : 150,
        "dodge" : 20,
        "parry" : 20,
        "lvl" : 30,
        "damage" : 300,
        "damage_type" : "内伤",
]),
([      "action" : ""+(order[random(13)])+"$N双手持$w举过头顶，猛然挥出「天降神兵」\n只见一股强劲的气浪随$w自空而降，袭向$n"NOR"",
        "skill_name" : "天降神兵",
        "force" : 280,
        "dodge" : 30,
        "parry" : 30,
        "lvl" : 60,
        "damage" : 350,
        "damage_type" : "内伤",
]),
([      "action" : ""+(order[random(13)])+"$N手撙$w，运起真气，脚下走出怪异步法\n顿时好似有无数个$N将那无数的$w斩向$n的头颅，这着唤做「天阵伏魔」"NOR"",
        "skill_name" : "天阵伏魔",
        "force" : 320,
        "dodge" : 50,
        "parry" : 30,
        "lvl" : 100,
        "damage" : 300,
        "damage_type" : "劈伤",
]),

([      "action" : HIR"只见$N挥力太猛，$w当空坠落，$N急忙俯身去接\n$n看到如此大好时机，岂肯放过，一步抢入准备施展手段\n$n怎知这正中了圣火令法的绝招「偃旗息鼓」，只见$N突然一个鹞子翻身，$n只感到胸口冰凉，看时已是$w插入了心脏处！"NOR,
        "skill_name" : "偃旗息鼓",
        "force" : 300,
        "dodge" : 100,
        "parry" : 100,
        "lvl" : 120,
        "damage" : 500,
        "damage_type" : "刺伤",
]),

});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

//int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
        object weapon;
        if ((int)me->query_skill("sougu", 1) < 80)
		return notify_fail("你的搜骨鹰爪功火候太浅。\n");
        if ((int)me->query_skill("hanbing-mianzhang", 1) < 80)
		return notify_fail("你的寒冰绵掌火候太浅。\n");
        if ((int)me->query_skill("shenghuo-shengong", 1) < 30)
                return notify_fail("你对圣火神功的领悟不够，无法学圣火令法。\n");
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
        if (random(me->query_skill("sword")) > 150 &&
            me->query_skill("force") > 150 &&
            me->query("neili") > 500)
         {
                me->add("neili", -30);
                return ([
          "action" : "只见$N挥力太猛，$w当空坠落，$N急忙俯身去接\n$n看到如此大好时机，岂肯放过，一步抢入准备施展手段\n$n怎知这正中了圣火令法的绝招「偃旗息鼓」\n只见$N突然一个鹞子翻身，$w由下而上急速向$n刺去！",
        "skill_name" : "偃旗息鼓",
        "force" : 500,
        "dodge" : 100,
        "parry" : 100,
       "lvl" : 120,
        "damage" : 700,
        "damage_type" : "刺伤",
                       ]);
        }
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够，练不了圣火令法。\n");
        if ((int)me->query("neili") < 600)
                return notify_fail("你的内力不够练圣火令法。\n");
        if ((int)me->query_skill("sougu", 1) < 80)
		return notify_fail("你的搜骨鹰爪功火候太浅。\n");
        if ((int)me->query_skill("hanbing-mianzhang", 1) < 80)
		return notify_fail("你的寒冰绵掌火候太浅。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenghuo-ling/" + action;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jiuyang-shengong",1);
        skill = me->query_skill("jiuyang-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenghuo-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "jiuyang-shengong" || me->query_skill_mapped("force") == "shenghuo-shengong"))
{
j = -damage/2; 
j = 0;
if (damage2> 5000)	damage2=5000;
msg = HIC+"$N运起九阳神功 全身内力爆发，浮现出一层刚猛的劲气! !" +NOR;
           message_vision(msg, me, ob);
if ( me->is_busy())
{
me->start_busy(1);
ob->start_busy(2);
}
if (me->query("neili") > me->query("max_neili")*2)
{
		
		me->add("neili", damage2);
}

}


           return j;
}      

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if( random(me->query_skill("hanbing-mianzhang",1)) > 10 )
	victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 16 + victim->query_condition("ice_poison"));
}