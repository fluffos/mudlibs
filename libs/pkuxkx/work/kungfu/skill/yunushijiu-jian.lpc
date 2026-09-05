// yunushijiu-jian.c 玉女十九剑
// modified by seagate@pkuxkx

inherit SKILL;
#include <combat.h>
#include <ansi.h>
mapping *action = ({
([      "action":HIW"\n$N使一式「悠悠顺自然」，手中$w"+HIW"嗡嗡微振，幻成一条白光刺向$n的$l"NOR,
        "force" : 120,
        "dodge" : 10,
        "damage": 30,
        "lvl" : 0,
        "skill_name" : "悠悠顺自然",
        "damage_type":  "刺伤"
]),
([      "action":HIC"\n$N错步上前，使出「来去若梦行」，剑意若有若无，$w"+HIC"淡淡地向$n的$l挥去"NOR,
        "force" : 140,
        "dodge" : 15,
        "damage": 36,
        "lvl" : 30,
        "skill_name" : "来去若梦行",
        "damage_type":  "割伤"
]),
([      "action":HIM"\n$N一式「志当存高远」，纵身飘开数尺，运发剑气，手中$w"+HIM"遥摇指向$n的$l"NOR,
        "force" : 160,
        "dodge" : 20,
        "damage": 42,
        "lvl" : 60,
        "skill_name" : "志当存高远",
        "damage_type":  "刺伤"
]),
([      "action":HIG"$N纵身轻轻跃起，一式「表里俱澄澈」，剑光如水，一泻千里，洒向$n全身"NOR,
        "force" : 180,
        "dodge" : 25,
        "damage": 48,
        "lvl" : 90,
        "skill_name" : "表里俱澄澈",
        "damage_type":  "割伤"
]),
([      "action":HIY"$N手中$w"+HIY"中宫直进，一式「随风潜入夜」，无声无息地对准$n的$l刺出一剑"NOR,
        "force" : 220,
        "dodge" : 30,
        "damage": 54,
        "lvl" : 120,
        "skill_name" : "随风潜入夜",
        "damage_type":  "刺伤"
]),
([      "action":HIR"$N手中$w"+HIR"一沉，一式「润物细无声」，无声无息地滑向$n的$l"NOR,
        "force" : 250,
        "dodge" : 35,
        "damage": 60,
        "lvl" : 150,
        "skill_name" : "润物细无声",
        "damage_type":  "割伤"
]),
([      "action":WHT"\n$N手中$w"+WHT"斜指苍天，剑芒吞吐，一式「云龙听梵音」，对准$n的$l斜斜击出"NOR,
        "force" : 280,
        "dodge" : 40,
        "damage": 66,
        "lvl" : 180,
        "skill_name" : "云龙听梵音",
        "damage_type":  "刺伤"
]),
([      "action":RED"$N左指凌空虚点，右手$w"+RED"逼出丈许雪亮剑芒，一式「万里一点红」刺向$n的咽喉"NOR,
        "force" : 320,
        "dodge" : 45,
        "damage": 72,
        "lvl" : 210,
        "skill_name" : "万里一点红",
        "damage_type":  "刺伤"
]),
([      "action":CYN"$N合掌跌坐，一式「我心化云龙」，$w"+CYN"自怀中跃出，如疾电般射向$n的胸口"NOR,
        "force" : 360,
        "dodge" : 50,
        "damage": 78,
        "lvl" : 240,
        "skill_name" : "我心化云龙",
        "damage_type":  "刺伤"
]),
([      "action":HIC"\n$N呼的一声拔地而起，一式「日月与同辉」，$w"+HIC"幻出万道光影，将$n团团围住"NOR,
        "force" : 400,
        "dodge" : 55,
        "damage": 84,
        "lvl" : 270,
        "skill_name" : "日月与同辉",
        "damage_type":  "内伤"
]),
([      "action":MAG"$N随风轻轻飘落，一式「清风知我意」，手中$w"+MAG"平指，缓缓拍向$n脸颊"NOR,
        "force" : 440,
        "dodge" : 60,
        "damage": 90,
        "lvl" : 300,
        "skill_name" : "清风知我意",
        "damage_type":  "内伤"
]),
([      "action":GRN"$N剑尖微颤作龙吟，一招「高处不胜寒」，切骨剑气如飓风般裹向$n全身"NOR,
        "force" : 480,
        "dodge" : 65,
        "damage": 100,
        "lvl" : 330,
        "skill_name" : "高处不胜寒",
        "damage_type":  "内伤"
]),
([      "action":YEL"$N募的使一招「红叶舞秋山」，顿时剑光中几朵血花洒向$n全身"NOR,
        "force" : 520,
        "dodge" : 70,
        "damage": 120,
        "lvl" : 360,
        "skill_name" : "红叶舞秋山",
        "damage_type":  "内伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili", 1) < 100)
                return notify_fail("你的内力不够。\n"); 
        if ( me->query_skill("zixia-shengong", 1) < 150 )
                return notify_fail("你的紫霞神功火候太浅。\n");
        if( (int)me->query_skill("sword", 1) < 150 )
                return notify_fail("你的基本剑法还不够娴熟，无法学习「玉女十九剑」。\n");
        if ((int)me->query_skill("huashan-jianfa", 1) < 150)
                return notify_fail("你的华山剑法太弱，无法学习到「玉女十九剑」的精髓。\n");
        if (!me->query("huashan_newskills/qizong") ||
            me->query("family/family_name")!="华山派" ) 
                return notify_fail("你不是华山气宗弟子，无法学习「玉女十九剑」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level=me->query_skill("yunushijiu-jian",1);

        for(i = sizeof(action); i > 0; i--) 
                if(level >= action[i-1]["lvl"]) return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力不够练「玉女十九剑」。\n");
        if ((int)me->query("neili") < 30)
                return notify_fail("你的内力不够练「玉女十九剑」。\n");
        if ((int)me->query_skill("huashan-jianfa", 1) < me->query_skill("yunushijiu-jian", 1) )
                return notify_fail("你的华山剑法太弱，无法练习「玉女十九剑」。\n");
        if (!me->query("huashan_newskills/qizong") ||
            me->query("family/family_name")!="华山派") 
                return notify_fail("你不是华山气宗弟子，无法练习「玉女十九剑」。\n");
        me->receive_damage("qi", 30);
        me->add("neili",-7);
        return 1;
}

string perform_action_file(string action)
{
               return __DIR__"yunushijiu-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string attack_skill)
{
	if ( F_KUNGFU->hit_rate( me->query_skill("sword"), victim->query_skill("parry"), 11, me, victim)
		&& !me->query_temp("active_buffer/shenghuo-lingfa.jindou") && !victim->is_busy())
	{
	  message_vision(CYN"$N"+CYN+"运剑如风，连出几招剑法，只见剑法姿式美妙已极，$n一下子不知道该如何抵挡！\n" NOR, me, victim);
		F_KUNGFU->hit_busy( "confuse", 1+random(2), victim );
	  me->add("neili", -50);
	}
}