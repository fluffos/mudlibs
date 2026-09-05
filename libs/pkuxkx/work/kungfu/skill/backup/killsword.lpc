#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":HIB"
$N强压住剑上枉死的冤魂，一阵阵杀气夺剑而出，将$n困在剑幕之中，$N轻送$w\n"NOR+
  HIW"一道白光一闪即失，$N手中的$w"NOR+HIW"已夺向$n的周身死穴"NOR,
        "force" : 600,
        "dodge" : 200,
        "damage": 600,
        "lvl" : 800,
        "skill_name" : "夺魄追魂",
        "damage_type":  "内伤"
]),
([      "action" : HIB"
$N暗自激发心中魔念，将枉死于$w上的无数冤魂化做魔兽\n"NOR+
RED"血食$n，$n被魔兽吸干了七魂八魄，混身上下鲜血直流"NOR,
        "force" : 200,
        "dodge" : 50,
        "damage" : 200,
        "lvl" : 50,
        "skill_name" : "食血魔兽",
        "damage_type":  "割伤"

]),
([      "action" : HIB"
$N抚剑长吟：十步杀一人，千里不留痕， $N怨气贯穿$w"NOR+HIB"口吐鲜血\n"NOR+
RED"顿时$N觉得魔性大发，手中$w寒光点点，直击$n的$l。"NOR,
        "force" : 300,
        "dodge" : 100,
        "damage": 350,
        "lvl" : 300,
        "skill_name" : "魔剑乘龙",
        "damage_type":  "内伤"
]),
([      "action" : HIW"
$N以气御形，神贯$w，顿悟了『杀手剑』的绝学「气游百穴连绵不绝」\n"NOR+
YEL"$N顿感杀气有如大江奔腾，无穷无尽的杀气奔涌而出，$N大喝一声：$w向$n的$l刺来。\n"NOR,

        "force" : 400,
        "dodge" : 100,
        "damage": 400,
        "lvl" : 600,
        "set_name" : "气游百穴",
        "damage_type":  "刺伤"
]),
([      "action" : HIB"
$N仰目归源，的杀气聚于$w上，目随心，心随意，攻发出阵阵杀气摧动手中的$w而行\n"NOR+
HIC"杀得片地飞砂，红云遮天谁敢争风"NOR",$n突感气血翻滚，无法呼吸。\n"NOR,
        "force" : 380,
        "dodge" : 20,
        "damage": 200,
        "lvl" : 100,
        "skill_name" : "风云变色",
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "spear"|| usage == "parry"; }


string *parry_msg = ({
        "$N地将手中的$w立于身前，摄人的杀气将$n逼得连退几步。\n",
});

string *unarmed_parry_msg = ({
        "$N手中的$w慢慢地挥出，剧烈颤动的剑锋封向$n。\n",
});

int valid_learn(object me)
{
me=this_player();
if(me->query_skill("force")<300)
return notify_fail("你的基本内功修为不够学杀手剑！\n");
if(me->query_skill("sword")<300)
return notify_fail("你的基本剑术不够学杀手剑！\n");
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
        level = (int) me->query_skill("killsword", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;


        if(this_player()->query_skill("hamagong",1)<700)
        return notify_fail("你还要在蛤蟆功上有所加强！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练杀手剑！\n");
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"killsword/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
   if( random(me->query_str()) > victim->query_str()*3/4 )

       {
        victim->receive_wound("qi", damage_bonus / 2, me );
        return HIR "你听到「唰」一声，忽然间$n血冒三丈，被$N杀气所伤！\n" NOR;
    }
}



