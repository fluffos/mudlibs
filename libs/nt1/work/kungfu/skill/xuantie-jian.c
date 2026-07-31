// 玄铁剑法
// Updated by Lonely

#include <ansi.h>;

inherit SKILL;

string *xue_name = ({ 
        HIC"劳宫穴"HIW,HIR"膻中穴"HIW,HIY"曲池穴"HIW,MAG"关元穴"HIW,HIM"曲骨穴"HIW,
        YEL"中极穴"HIW,WHT"承浆穴"HIW,RED"天突穴"HIW,HIB"百会穴"HIW,
        CYN"幽门穴"HIW,BLU"章门穴"HIW,GRN"大横穴"HIW,HIR"紫宫穴"HIW,HIM"冷渊穴"HIW,
        HIC"天井穴"HIW,HIY"极泉穴"HIW,RED"清灵穴"HIW,HIB"至阳穴"HIW,
});

string  *action_msg = ({
        "$N当胸平平刺出一剑，实在是毫无任何变化，而却有轰轰之声，$n只觉一股大力由$w直逼周身",
        "$N剑势如虹，无可当锋，$n惊怖中更觉剑力有如海潮一般，一波一浪阵阵涌来，绵延不绝",
        "$N连出十余剑，一时迅疾如流星划空，一时凝重迟缓，招招无迹可寻，平淡至极又匪思至极",
        "$N手中$w向前挑出，看似无甚劲力，启知剑势将老，内力却如海潮一般汹涌，向$n袭去",
        "$N一凝神，$w居然发出淡淡的一层暗青色光芒，如狂风怒潮一边，向$n卷去",
        "$N凌空跃起，身随剑起，借助下行之势向下猛劈一剑，将$n周身笼于剑气之下",
        "$N轻叹一声，随手横劈一剑，缓缓指向$n，看似无丝毫变化，却尽得剑法精髓，当真平淡中蕴涵所有变化，无招胜有招",
        "$N迅疾挑出一剑，但见剑势如虹，快似闪电，无可当锋！此剑之快，匪夷所思，无法分辨剑路去来",
        "$N祭起$w，左手捏成剑诀置于胸前，空中满是剑影，宛若千道银链，只在$n身边游动",
        "$N连出十余剑，一时迅疾如流星划空，一时凝重迟缓，招招无迹可寻，平淡至极又匪思至极",
        "$N顺刺，逆击，横削，倒劈，无不是剑法的入门，当真返朴归真，却已不再存任何破绽",
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        
        /*
        if (random(me->query_skill("sword", 1)) > 200 
        &&  me->query_skill("force", 1) > 60 
        &&  me->query("neili") > 200 
        && (string)weapon->query("id") == "xuantie jian") 
        {
                me->add("neili", -100);
                return ([
                        "action": HIB "$N手中的长剑一声龙吟，顿时狂风大做，电闪雷鸣，漫天剑气化似巨龙状直射$n" NOR,
                        "attack": 100,
                        "damage": 180,
                        "dodge" : 100,
                        "parry" : 100,
                        "damage_type": "内伤"
                ]);
        }
        */
        return ([
                "action" : action_msg[random(sizeof(action_msg))],
                "damage" : 140 + random(40),
                "dodge"  : 70 + random(10),
                "parry"  : 70 + random(10),
                "attack" : 70 + random(20),
                "damage_type" : random(2) ? "刺伤" : "割伤",                
        ]);
}

int valid_learn(object me)
{
        if ((int)me->query("str") < 26)
                return notify_fail("你的先天臂力不够，还是不要强学了。\n");
                
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力不够。\n");
                
        if ((int)me->query_skill("yunv-xinfa", 1) < 40
        &&  (int)me->query_skill("nuhai-kuangtao", 1) < 40)
                return notify_fail("你的古墓的内功火候太浅。\n");
                
        if (me->query_skill("sword", 1) <= me->query_skill("xuantie-jian", 1))
                return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) || 
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力不够练玄铁剑法。\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练玄铁剑法。\n");

        me->receive_damage("qi", 70);
        me->add("neili", -70);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuantie-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
        string name, weapon;
        mixed result;
        name = xue_name[random(sizeof(xue_name))];
    
        if (victim->is_busy()) return 0;
        
        if (random(damage / 2) > 30)  
        {
                victim->start_busy(3);
                me->add("neili", -30);
                result = ([ "damage" : damage ]);     
                result += (["msg" : HIW "$n突然觉得一阵麻木感从" + name + 
                                    "慢慢的扩散到全身各处，原来被$N" 
                                    HIW "发出的剑气刺中了穴道！\n" NOR]);                   
                return result;
        } 
}

int query_effect_parry(object attacker, object me) 
{ 
        object weapon; 
        int lvl; 
        
        if (! objectp(weapon = me->query_temp("weapon")) || 
            (string)weapon->query("skill_type") != "sword") 
                return 0; 
        
        lvl = me->query_skill("xuantie-jian", 1); 
        if (lvl < 90)  return 0; 
        if (lvl < 100) return 50; 
        if (lvl < 125) return 55; 
        if (lvl < 150) return 60; 
        if (lvl < 175) return 65; 
        if (lvl < 200) return 70; 
        if (lvl < 225) return 75; 
        if (lvl < 250) return 80; 
        if (lvl < 275) return 90; 
        if (lvl < 325) return 100; 
        if (lvl < 350) return 110; 
        return 120; 
} 
