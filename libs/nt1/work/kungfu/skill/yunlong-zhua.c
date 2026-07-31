// yunlong-zhua.c -云龙爪
// by Lonely

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N全身拔地而起，半空中一个筋斗，一式「凶鹰袭兔」，迅猛地抓向$n的$l",
        "$N单腿直立，双臂平伸，一式「雄鹰展翅」，双爪一前一后拢向$n的$l",
        "$N一式「拔翅鹰飞」，全身向斜里平飞，右腿一绷，双爪搭向$n的肩头",
        "$N双爪交错上举，使一式「迎风振翼」，一拔身，分别袭向$n左右腋空门",
        "$N全身滚动上前，一式「飞龙献爪」，右爪突出，鬼魅般抓向$n的胸口",
        "$N伏地滑行，一式「顶天立地」，上手袭向膻中大穴，下手反抓$n的裆部",
        "$N左右手掌爪互逆，一式「搏击长空」，无数道劲气破空而出，迅疾无比地击向$n",
        "$N腾空高飞三丈，一式「鹰扬万里」，天空中顿时显出一个巨灵爪影，缓缓罩向$n",
        "$N忽的拨地而起，使一式「苍龙出水」，身形化作一道闪电射向$n",
        "$N微微一笑，使一式「万佛朝宗」，双手幻出万道金光,直射向$n的$l",
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo) { return combo=="yunlong-shou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练云龙爪必须空手。\n");
        if ((int)me->query_skill("yunlong-shengong", 1) < 50)
                return notify_fail("你的云龙神功火候不够，无法学云龙爪。\n");
        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("你的基本内功火候不够，无法学云龙爪。\n");
        if ((int)me->query("max_neili") < 350)
                return notify_fail("你的内力太弱，无法练云龙爪。\n");
        if ((int)me->query_skill("claw",1) <40)
                return notify_fail("你的基本爪法火候不够，无法学云龙爪。\n");
        if (2*(int)me->query_skill("yunlong-xinfa",1) <(int)me->query_skill("yunlong-zhua",1))
                return notify_fail("你的云龙爪法火候不够，无法继续学云龙爪。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 320 + random(30),
                "attack": 70 - random(20),
                "dodge" : 70 - random(20),
                "parry" : 70 - random(20),
                "damage_type" : random(2)?"抓伤":"内伤",
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练云龙爪。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunlong-zhua/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("yunlong-zhua", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
            victim->affect_by("zhua_poison",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "remain": -1,
                                 "duration" : lvl / 100 + random(lvl / 10) ])))
        {
                return HIW "$n" HIW "的身子突然一阵颤抖,牙关咬得咯咯作响，看来是中了$N" HIW "抓上的凝血神抓毒。\n" NOR;
        }
}

int query_effect_parry(object attacker, object me) 
{
        int lvl;
        if (objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("yunlong-zhua", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}
