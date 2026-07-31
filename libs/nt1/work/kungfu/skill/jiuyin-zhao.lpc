// jiuyin-zhao.c
// by Lonely

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        BLU"$N势若疯虎，形若邪魔，双爪如钢抓铁钩，左手手腕翻处，右手疾伸，五根手指抓向$n$l"NOR,
        BLU"突然人影闪动，$N迫到$n身后，袖中伸出手，五根手指向$n$l插了下去"NOR,
        BLU"$N手臂关节喀喇一响，手臂斗然长了半尺，一掌按在$n$l，五指即要插进"NOR,
        BLU"$N双手微张，十根尖尖的指甲映出灰白光忙，突然翻腕出爪，五指猛地插落"NOR,
        BLU"$N左手突然在$n眼前上围下钩，左旋右转，连变了七八般，蓦地里右手一伸，五根手指直插$n$l"NOR,
        BLU "$N左爪虚晃，右爪蓄力，一招" HIR "「勾魂夺魄」" BLU "直插向$n的$l" NOR,
        BLU "$N双手连环成爪，爪爪钩向$n，" HIR "「九子连环」" BLU "已向$n的$l抓出" NOR,
        BLU "$N身形围$n一转，使出" HIR "「天罗地网」" BLU "，$n的$l已完全笼罩在爪影下" NOR,
        BLU "$N使一招" HIR "「风卷残云」" BLU "，双爪幻出满天爪影抓向$n全身" NOR, 
        BLU "$N吐气扬声，一招" HIR "「唯我独尊」" BLU "双爪奋力向$n天灵戳下" NOR,
});

int valid_enable(string usage) { return usage == "claw" ||  usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练九阴白骨爪必须空手。\n");
        if ((int)me->query_skill("claw", 1) < 41)
                return notify_fail("你的基本爪功火候不够，无法学习。\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力太弱，无法练九阴白骨爪。\n");
        if (me->query("character") != "心狠手辣" && me->query("character") != "国士无双") 
                return notify_fail("你天性不符，受其拘束，无法领会九阴白骨爪的妙旨。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 320 + random(120),
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage_type" : random(2)?"抓伤":"内伤",
        ]);
}

int practice_skill(object me)
{
        object obj;

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 40)
                return notify_fail("你的内力不够练九阴白骨爪。\n");
        if (environment(me)->query("no_fight") )
                return notify_fail("这里练功会误伤他人。\n");
        if (environment(me)->query("sleep_room") )
                return notify_fail("这里练功会打扰别人休息。\n");
        if (! objectp(obj=present("corpse", environment(me))) || ! obj->is_corpse())
                return notify_fail("练九阴白骨抓需有尸体。\n");
        if (me->query_skill("jiuyin-zhao", 1) > 100 && me->query("shen") > -100)
                return notify_fail("这种邪恶武功不是侠义道当练的。\n");
        me->receive_damage("qi", 35);
        me->add("neili", -25);
//        tell_room(environment(me), 
//                HIB"只见"+me->query("name")+"左手上圈下钩、左旋右转，连变了七八般花样，蓦地里右手一伸，噗的"
//                "一响，\n五根手指直插入地上尸体的脑门。随后五根手指"HIR"血淋淋"HIB"的提将起来。\n");

        return 1;
}
void skill_improved(object me)
{
        tell_object(me, HIR "你忽然从心底生出一股恶念：杀、杀、杀！我要杀绝天下人！\n" NOR );
        me->add("shen", -200);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;
        mixed result;

        lvl  = me->query_skill("jiuyin-zhao", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (random(damage_bonus / 2) > victim->query_str()
        &&  victim->affect_by("jy_poison",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "duration" : lvl / 100 + random(lvl / 10) ])))
        {
                result = ([ "damage" : damage_bonus ]); 
                result += ([ "msg" : HIR "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n" NOR ]); 

                return result;
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("jiuyin-zhao", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

string perform_action_file(string action) 
{
        return __DIR__"jiuyin-zhao/" + action; 
}

