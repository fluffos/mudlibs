#include <ansi.h>
#include <skill.h>

inherit SKILL;

string *xue_name = ({ 
"劳宫穴", "膻中穴", "曲池穴", "关元穴", "曲骨穴", "中极穴", "承浆穴", "天突穴", "百会穴",
"幽门穴", "章门穴", "大横穴", "紫宫穴", "冷渊穴", "天井穴", "极泉穴", "清灵穴", "至阳穴", }); 

mapping *action_unarmed = ({
([      "action": "$N使一招「弦外有音」，双手猛然击出，空气中暴响出“呜”的一声，一股气流如风一般卷向$n的$l",
        "force" : 350,
        "attack": 80,
        "dodge" : 75,
        "parry" : 55,
        "damage": 270,
        "lvl" : 0,
        "weapon" : HIW "无形剑气" NOR,
        "skill_name" : "弦外有音",
        "damage_type" : "刺伤"
]),
([      "action": "$N使出一招「吴阳琴音」，弹指向上一刺，接着再向下直划而出，顿时两股剑气如利刀般砍向$n",
        "force" : 370,
        "attack": 81,
        "dodge" : 65,
        "parry" : 65,
        "damage": 272,
        "lvl" : 40,
        "weapon" : HIW "无形剑气" NOR,
        "skill_name" : "吴阳琴音",
        "damage_type" : "刺伤"
]),
([      "action": "$N一声暴喝，陡然一招「天河紫气」，单手向$n凌空一劈，顿时一股劲气伴随着破空之声袭向$p$l",
        "force" : 410,
        "attack": 85,
        "dodge" : 55,
        "parry" : 55,
        "damage": 288,
        "lvl" : 80,
        "weapon" : HIW "无形剑气" NOR,
        "skill_name" : "天河紫气",
        "damage_type" : "刺伤"
]),
([      "action": "$N双掌缤纷拍出，劲气纵横，正是一式「七盘绝刹」，刹时“飕飕”破空声悠然而响，击向$n$l",
        "force" : 430,
        "attack": 79,
        "dodge" : 65,
        "parry" : 35,
        "damage": 183,
        "lvl" : 120,
        "weapon" : HIW "破体无形剑气" NOR,
        "skill_name" : "七盘绝刹",
        "damage_type" : "刺伤"
]),
([      "action": "$N凭空一指，一招「黄龙吐珠」斜斜袭出，手掌陡然生出半寸吞吐不定的青芒刺向$n的$l",
        "force" : 460,
        "attack": 75,
        "dodge" : 91,
        "parry" : 85,
        "damage": 278,
        "lvl" : 160,
        "weapon" : HIW "破体无形剑气" NOR,
        "skill_name" : "黄龙吐珠",
        "damage_type" : "刺伤"
]),
([      "action": "$N双手向外一分，使一招「清心普善」，手若拨琴弄萧，弹射出一股破体剑气，直涌$n$l而去",
        "force" : 490,
        "attack": 105,
        "dodge" : 35,
        "parry" : 24,
        "damage": 298,
        "lvl" : 200,
        "weapon" : HIW "破体无形剑气" NOR,
        "skill_name" : "清心普善",
        "damage_type" : "刺伤"
]),
([      "action": "$N忽然眼中精光四射，一招「星河气旋」使出，顿时数股淳厚无比的剑气从指尖激射而出，直逼$n",
        "force" : 480,
        "attack": 95,
        "dodge" : 75,
        "parry" : 75,
        "damage": 293,
        "lvl" : 240,
        "weapon" : HIW "破体无形剑气" NOR,
        "skill_name" : "星河气旋",
        "damage_type" : "刺伤"
]),
});


mapping *action_sword = ({
([      "action": "$N使一招「弦外有音」，手中$w弹出一股气流，如风一般卷向$n的$l",
        "force" : 140,
        "attack": 60,
        "dodge" : 15,
        "parry" : 25,
        "damage" : 250,
        "lvl" : 0,
        "damage_type" : "刺伤",
]),
([      "action": "$N伸指在$w上一弹，一招「吴阳琴音」，整个剑身顿时发出一声龙吟，呼啸着斩向$n的$l",
        "force" : 150,
        "attack": 80,
        "dodge" : 60,
        "parry" : 5,
        "damage" : 270,
        "lvl" : 40,
        "damage_type" : "内伤",
]),
([      "action": "$N一招「天河紫气」，手中$w剑芒顿时暴长数尺，光华四射，直直削向$n的$l",
        "force" : 200,
        "attack": 80,
        "dodge" : 0,
        "parry" : 10,
        "damage" : 290,
        "lvl" : 80,
        "damage_type" : "割伤",
]),
([      "action": "$N手中$w一式「七盘绝刹」对准$n的$l一连刺出数剑，刹时剑气纵横，势不可挡",
        "force" : 250,
        "attack": 80,
        "dodge" : 10,
        "parry" : 15,
        "damage" : 292,
        "lvl" : 120,
        "damage_type" : "刺伤",
]),
([      "action": "$N的$w凭空一指，一招「黄龙吐珠」直直刺出，剑尖陡然生出半寸吞吐不定的青芒刺向$n的$l",
        "force" : 225,
        "attack": 63,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 203,
        "lvl" : 160,
        "damage_type" : "刺伤",
]),
([      "action": "$N手中$w向外一分，使一招「清心普善」，单手在剑身轻轻弹拨，顿时一股剑气直涌$n$l而去",
        "force" : 250,
        "attack": 80,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 220,
        "lvl" : 200,
        "damage_type" : "刺伤",
]),
([      "action": "$N忽然眼中精光四射，一招「星河气旋」，一股淳厚无比的剑气从$w上激射而出，直逼$n",
        "force" : 300,
        "attack": 100,
        "dodge" : -15,
        "parry" : -15,
        "damage" : 240,
        "lvl" : 240,
        "damage_type" : "刺伤",
]),
});

int valid_enable(string usage) 
{  
        return usage == "unarmed"
            || usage == "parry"
            || usage == "sword"
            ; 
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 270)
                return notify_fail("你的内功火候不够，无法修炼七弦无形剑。\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("你的内力太弱，无法修炼七弦无形剑。\n");

        if ((int)me->query_skill("unarmed", 1) < 180)
                return notify_fail("你的基本拳脚火候不够，无法修炼七弦无形剑。\n");

        if ((int)me->query_skill("sword", 1) < 180)
                return notify_fail("你的基本剑法火候不够，无法修炼七弦无形剑。\n");
        if( (int)me->query_skill("xuantian-wuji", 1) < 160)
                return notify_fail("你的玄天无极功的修为不够，不能使用流云水袖! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 180 )
                return notify_fail("你的迅雷剑法还不到家，无法使用流云水袖！\n");
        if( (int)me->query_skill("liangyi-jian", 1) < 180 )
                return notify_fail("你的两仪剑法还不到家，无法使用流云水袖！\n");

   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("你没有用玄天无极。\n");


        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action_unarmed)-1; i >= 0; i--)
                if(level >= action_unarmed[i]["lvl"])
                        return action_unarmed[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("qixian-jian", 1);

        if ( ! weapon)
        {                
             for(i = sizeof(action_unarmed); i > 0; i--)
                     if(level >= action_unarmed[i-1]["lvl"])
                             return action_unarmed[NewRandom(i, 20, level/5)];
        }        
        else
             for(i = sizeof(action_sword); i > 0; i--)
                     if(level > action_sword[i-1]["lvl"])
                             return action_sword[NewRandom(i, 20, level/5)];        
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力不够练七弦无形剑！\n");

        if ((int)me->query("neili") < 120)
                return notify_fail("你的内力不够练七弦无形剑！\n");
        if( (int)me->query_skill("xuantian-wuji", 1) < 160)
                return notify_fail("你的玄天无极功的修为不够，不能使用流云水袖! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 180 )
                return notify_fail("你的迅雷剑法还不到家，无法使用流云水袖！\n");
        if( (int)me->query_skill("liangyi-jian", 1) < 180 )
                return notify_fail("你的两仪剑法还不到家，无法使用流云水袖！\n");

   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("你没有用玄天无极。\n");
        me->receive_damage("qi", 60);
        me->add("neili", -100);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name, weapon;
        name = xue_name[random(sizeof(xue_name))];
    
        if (me->query_skill("qixian-jian", 1) < 180
           || me->query("max_neili") < 2500
           || me->query("neili") < 500
          )
                return 0;

        if (damage_bonus < 50)
                return 0;
    if(me->query_skill_mapped("force") != "xuantian-wuji" )
        return 0;
if (random(3)==0)
{

        if (!victim->is_busy())
        victim->start_busy(2);
        me->add("neili", -50);
        victim->receive_damage("qi", me->query_skill("qixian-jian", 1) / 3 + damage_bonus / 3);
        victim->receive_wound("qi", me->query_skill("qixian-jian", 1) / 5 + damage_bonus / 5);
                return HIW "只听一阵淳厚的弦音从$N" HIW "处传来，$n" HIY "『" + name + "』"
                       NOR + HIW "顿时受震，两耳轰鸣，全身真气乱窜不止！\n" NOR;
}
}

string perform_action_file(string action)
{
      return __DIR__"qixian-jian/" + action;
}
