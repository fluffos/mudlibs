//yinlong-whip.c 《九阴真经》——九阴神功——峨嵋银龙鞭
//Edit By Vin On 13/2/2001

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N端坐不动，一式「神蛟初现」，手腕力抬，$w滚动飞舞，宛如灵蛇乱颤扫向$n",
        "force" : 98,
        "attack": 41,
        "dodge" : 5,
        "parry" : 15,
        "damage": 232,
        "lvl"   : 0,
        "damage_type": "抽伤"
]),
([      "action": "$N一式「神蛟再现」，$w抖得笔直，“呲呲”破空声中向$n疾刺而去",
        "force" : 187,
        "attack": 48,
        "dodge" : 20,
        "parry" : 36,
        "damage": 247,
        "lvl"   : 80,
        "damage_type": "刺伤"
]),
([      "action": "$N内劲到处，将$w抖动转成两个圆圈，一式「神蛟又现」，从半空中往$n缠下",
        "force" : 231,
        "attack": 65,
        "dodge" : 10,
        "parry" : 55,
        "damage": 393,
        "lvl"   : 100,
        "damage_type": "抽伤"
]),
([      "action": "$N劲走螺旋，一式「吞天裂地势」，$w在$n眼前连变数种招式，忽然从$l处倒卷上来",
        "force" : 263,
        "attack": 70,
        "dodge" : 5,
        "parry" : 60,
        "damage": 302,
        "lvl"   : 120,
        "damage_type": "抽伤"
]),
([      "action": "$N一声高喝，使出「真天罗势」，$w急速转动，鞭影纵横，似真似幻，绞向$n",
        "force" : 301,
        "attack": 77,
        "dodge" : 6,
        "parry" : 65,
        "damage": 321,
        "lvl"   : 140,
        "damage_type": "抽伤"
]),
([      "action": "$N含胸拔背，一式「六道轮回势」，力道灵动威猛，劲力从四面八方向$n挤压出去",
        "force" : 331,
        "attack": 85,
        "dodge" : 12,
        "parry" : 70,
        "damage": 342,
        "lvl"   : 160,
        "damage_type": "抽伤"
]),
([      "action":"$N力贯鞭梢，一招「大吉祥势」，手中$w舞出满天鞭影，排山倒海般扫向$n",
        "force" : 373,
        "attack": 91,
        "dodge" : 17,
        "parry" : 75,
        "damage": 163,
        "lvl"   : 180,
        "damage_type": "抽伤"
]),
([      "action":"$N力贯鞭梢，一招「龙飞十二重天势」，手中$w舞出满天鞭影，排山倒海般扫向$n",
        "force" : 401,
        "attack": 98,
        "dodge" : 20,
        "parry" : 85,
        "damage": 389,
        "lvl"   : 200,
        "damage_type": "抽伤"
]),
});

string main_skill() { return "jiuyin-shengong"; }

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

int valid_learn(object me)
{
        object weapon;


        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("你必须先找一条鞭子才能练峨嵋银龙鞭。\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("你的内力不足，没有办法练峨嵋银龙鞭。\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("你的内功火候太浅，没有办法练峨嵋银龙鞭。\n");

        if ((int)me->query_skill("bagua-dao", 1) < 100)
                return notify_fail("你的四像八卦刀火候太浅。\n");
                
        if ((int)me->query_skill("bagua-zhang", 1) < 100)
                return notify_fail("你的四像八卦掌火候太浅。\n");                


        if ((int)me->query_skill("whip", 1) < 100)
                return notify_fail("你的基本鞭法火候太浅，没有办法练峨嵋银龙鞭。\n");

        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("yinlong-whip", 1))
                return notify_fail("你的基本鞭法水平还不够，无法领会更高深的峨嵋银龙鞭。\n");

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
        level = (int) me->query_skill("yinlong-whip",1);
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

        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 350)
                return notify_fail("你的内力不够。\n");

        me->receive_damage("qi", 80);
        me->add("neili", -300);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yinlong-whip/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("yinlong-whip", 1);

        if (damage_bonus < 50 || lvl < 160) return 0;

        if (damage_bonus / 6 > victim->query_con() || random(5)==0)
        {
                                victim->receive_wound("qi", (random(lvl)+10) / 2 );
                	return RED "$n" HIR "眼光一花，胸前多了一道"
                               "深深的鞭痕。\n" NOR;
        }
}

int ob_hit(object ob, object me, int damage)
{
        object wa;
                
        string msg,limb;
                
        int i, j, p, skill, neili;

        object wp,wp1;
        int neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("linji-zhuang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "linji-zhuang")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (me->query("qi")<= me->query("max_qi") )
{
	me->add("qi", damage2);
		//ob->add("qi", 10000);
}
if (me->query("eff_qi")<= me->query("max_qi") )
{
	me->add("eff_qi", damage2);
}
msg = HIG"$N 五心向天，运行日月二庄，益气升阳，益阴潜阳，
升降反正，天地二气交泰于身，并配合峨嵋九阳功。灭绝之间顿时大起!！\n"NOR;
msg += "$N神色一变,恢复了些活力！\n",  
           message_vision(msg, me, ob);
           return j;
} 
}