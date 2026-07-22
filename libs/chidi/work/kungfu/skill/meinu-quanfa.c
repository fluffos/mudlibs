// meinu-quan 美女拳法
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「貂禅拜月」，右手一挥，向$n的$l绕去，掌缘在$n的$l一斩",
        "force" : 150,
        "dodge" : 30,
        "skill_name" : "貂禅拜月",
        "lvl" : 0,
        "damage_type" : "斩伤"
]),
([      "action" : "$N双拳抱胸，忽地右手使一招「西施捧心」，向$n的$l插去",
        "force" : 250,
        "dodge" : 25,
        "skill_name" : "西施捧心",
        "lvl" : 10,
        "damage_type" : "击伤"
]),
([      "action" : "$N左手斜举，右手五指弹起，仿似弹习琵琶一般，「昭君出塞」五指轮番向
$n弹去", 
        "force" : 300,
        "dodge" : 20,
        "skill_name" : "昭君出塞",
        "lvl" : 20,
        "damage_type" : "搓伤"
]),
([      "action" : "$N侧身一闪，双手合拳向上抬去，一招「麻姑献寿」击向$n的下巴",
        "force" : 320,
        "dodge" : 15,
        "skill_name" : "麻姑献寿",
        "lvl" : 30,
        "damage_type" : "撞伤"
]),
([      "action" : "$N施出「天女织梭」，右手挥左，左手送右，做投梭织布之状，一挥一送，
击向$l",
        "force" : 370,
        "dodge" : 10,
        "skill_name" : "天女织梭",
        "lvl" : 50,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N施出「则天垂帘」，身子前扑，双掌以垂帘之势削将下来，斩向$n的双肩",
        "force" : 150,
        "dodge" : 30,
        "skill_name" : "则天垂帘",
        "lvl" : 70,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N脸露微笑，伸手往头上一梳，手指如「丽华梳妆」，软软挥将出去，拍向$n
的胸口",
        "force" : 250,
        "dodge" : 25,
        "skill_name" : "丽华梳妆",
        "lvl" : 90,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手互拍，闪电般击出，俨然一招「红玉击鼓」，轮番击向$n$l",
        "force" : 300,
        "dodge" : 20,
        "skill_name" : "红玉击鼓",
        "lvl" : 110,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「弄玉吹箫」，一指擎天，一指对地，闭目垂首，忽然手腿齐出，攻向
$n全身要害",
        "force" : 500,
        "dodge" : 5,
        "skill_name" : "弄玉吹箫",
        "lvl" : 120,
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("空手方能练习美女拳法。\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 10)
                return notify_fail("玉女心经领悟不够，无法修习美女拳法。\n");
        if ((int)me->query_skill("dodge", 1) < 20)
                return notify_fail("你的轻功太差，无法练美女拳法。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon,object ob)
{
        int i, level;         
        level = (int) me->query_skill("meinu-quanfa",1);         
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练美女拳法了。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
        int level= (int) me->query_skill("meinu-quanfa",1);  
        if( damage_bonus < 100 ) return 0;
        if ((me->query_per()) > 24 && random(10) > 5 &&
          level > 120 && me->query("neili") > 500 && !victim->is_busy()){
           msg= HIY"\n$N悄退数步，右手支颐，左手轻轻挥出，长叹一声，脸现寂寥之意。\n"NOR;
        if (random(me->query_per()) > random(victim->query_per()) /3 * 2){
           me->add("neili", -30);
           victim->start_busy(random(10));
           msg +=CYN"\n$n受$N的感染，呆在原处，两眼发直，一动不动。\n\n"NOR;
           }
       else {
           me->add("neili", -10);
           me->start_busy(random(2));
           msg +=CYN"\n结果$n对$N的表情无动于衷。\n\n"NOR;
           }
         message_vision(msg, me, victim);
         return;
         }
}

