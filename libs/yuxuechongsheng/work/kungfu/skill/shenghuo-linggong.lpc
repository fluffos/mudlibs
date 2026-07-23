// Shenghuo-lingfa  圣火令法,全新版的哦！
// by aohan
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : HIG"$N滚身向左，已然一令打在$n腿上，$n一个踉跄，$N再横令戳向$n后心。"NOR,
        "skill_name" : "应左则前",
        "force" : 650,
        "dodge" : 520,
        "parry" : 520,
        "lvl" : 0,
        "damage" : 1800,
        "damage_type" : "内伤",
]),
([      "action" : MAG"$n右手虚幌一招，左手迅捷无比的伸出来夺$N圣火令，\n岂知$N忽地放手，那圣火令尾端向上弹起，打向$n左手腕。"NOR,
        "skill_name" : "须右乃后",
        "force" : 680,
        "dodge" : 530,
        "parry" : 530,
        "lvl" : 101,
        "damage" : 1850,
        "damage_type" : "内伤",
]),
([      "action" : HIM"$N忽然低头，一个头锤朝$n撞来，竟是将自己的最要紧的部位送向敌人，\n$n正疑惑间，$N却又身形一变，跃身半空，一屁股凌空朝$n坐了下来，\n这一着更是怪异，竟是以臀部攻敌，$n不由一楞，$N趁机以手肘撞向$n胸口。"NOR,
        "skill_name" : "三虚七实",
        "force" : 720,
        "dodge" : 550,
        "parry" : 530,
        "lvl" : 201,
        "damage" : 1900,
        "damage_type" : "淤伤",
]),
([      "action" : HIR"$N突然连翻三个空心筋斗，$n不知有何用意，刚细思量间，\n只见白光急闪，$N圣火令已经砸向$n肩头，这一招更是匪夷所思，\n事先没有半点征兆，而$N却明明在半空中大翻筋斗，怎能突的伸出圣火令来，击向$n肩头？"NOR,
        "skill_name" : "无中生有",
        "force" : 800,
        "dodge" : 600,
        "parry" : 600,
        "lvl" : 301,
        "damage" : 1950,
        "damage_type" : "砸伤",
]),
([      "action" : HIW"$N飞身而前，手中圣火令相互一击，铮的一响，$n心神一荡，\n身形不由一凝，$N圣火令连忙砸向$n腰间。"NOR,
        "skill_name" : "天方地圆",
        "force" : 800,
        "dodge" : 700,
        "parry" : 700,
        "lvl" : 401,
        "damage" : 2000,
        "damage_type" : "砸伤",
]),
([      "action" : HIC"$n眼见$N挥令攻来，连忙格挡，只听得啪的一下，\n如中败革，似击破絮，声音极是难听，$N把捏不定，圣火令脱手向上飞出，$n跃身而起欲待抢夺，\n突然间听得嘶的一声破空轻响，却是$N挥爪抓向$n后心！"NOR,
        "skill_name" : "",
        "force" : 800,
        "dodge" : 750,
        "parry" : 750,
        "lvl" : 501,
        "damage" : 2100,
        "damage_type" : "抓伤",
]),
([      "action" : HIB"$N抢身而上，转至$n背后，重重一拳击向$n背心，\n这一拳来无影，去无踪，$n竟是听不到半点风声。"NOR,
        "skill_name" : "似虚还实",
        "force" : 800,
        "dodge" : 800,
        "parry" : 800,
        "lvl" : 550,
        "damage" : 2200,
        "damage_type" : "内伤",
]),
([      "action" : BLINK+HIY"$N心魔大盛，禁不住仰天一阵哈哈哈狂笑，手舞足蹈起来，\n正舞到心魔极至时，$N一声长啸，猛的弹射到半空，凌空翻了一个筋斗，\n半空中一爪朝$n头顶抓来，这一下变化突然，$N出招又是快捷无比，实在是十分阴险毒辣的杀招！"NOR,
        "skill_name" : "走火入魔",
        "force" : 800,
        "dodge" : 800,
        "parry" : 800,
        "lvl" : 590,
        "damage" : 2500,
        "damage_type" : "内伤",
]),
});


int valid_enable(string usage) { return usage == "sword"; }

int valid_learn(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type") != "sword")
                return notify_fail("你必须使用合适的武器才可能练就圣火令法。\n");
        if ((int)me->query_skill("sword", 1) < 1500)
                return notify_fail("你的旁门左道太差了，练不了圣火令法。\n");
        if ((int)me->query_skill("force", 1) < 1500)
                return notify_fail("你的内功心法的修为不够，无法学习圣火令法。\n");
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
        level   = (int) me->query_skill("shenghuo-lingfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50000)
                return notify_fail("你的体力不够，练不了圣火令法。\n");
        if ((int)me->query("neili") < 600000)
                return notify_fail("你的内力不够练圣火令法。\n");
              if ((int)me->query_skill("shenghuo-lingfa",1) < 1500 )
                return notify_fail("你的圣火令法火侯不够，无法练习圣火令法！\n");
              if ((int)me->query_skill("sword",1) < 1500 )
                return notify_fail("你的旁门左道之术火侯不够，也想练习圣火令法？\n");
        me->receive_damage("qi", 30000);
        me->add("neili", -100000);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenghuo-lingfa/" + action;
}

