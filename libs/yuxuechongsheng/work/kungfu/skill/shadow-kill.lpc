// shadow-kill written by mtl on May 9th, 1996
// cii change on 8.3 98

#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([ "action":"$N斗然使出『停云催雪，地落八荒』的绝情杀着，气吞万里如虎，剑虹流星坠雨般的向$n罩去，让$n避无可避。",
        "dodge": -30,
        "parry": -20,
          "damage": 60,
        "force": 30,
        "damage_type": "刺伤",
]),
([ "action":"$N喟然叹道：不恨古人吾不见，恨古人、不见吾狂耳～～剑影骤然随着那怅然杀意，使出『云山千叠，骇浪覆顶』向$n层层递去，招招指向要害。",
        "dodge": -30,
        "parry": -25,
          "damage": 70,
        "force":  40,
        "damage_type":  "刺伤",
]),
([ "action":"$N似笑非笑，凄凄念起『弃魂散魄』心诀。只见$N手上的$w一抹紫孽蒸起，不住旋动，激起一道风刃向$n腰间急劈。",
        "dodge": -40,
        "parry": -30,
          "damage": 80,
        "force": 50,
        "damage_type": "内伤",
]),
([ "action":"$N逆踏八卦，使出『乱象错形』的奥秘，陷$n於五行易位之暗黑空间。剑首寂然指向京房卦之血脉卦位，只见$n正向跌跌撞撞地向$w奔去....",
        "dodge": -10,
        "parry": -10,
          "damage": 90,
        "force": 60,
        "damage_type": "刺伤",
]),
([ "action":"$N意念一起一息之间，身形已然『如入不动魔地』，手中$w影如来如去，无声亦无息地递向$n$l....",
        "dodge": -10,
        "parry": -10,
          "damage": 110,
        "force": 50,
        "damage_type": "刺伤",
]),     
([ "action":"$N斗然使出"HIW"『停云催雪，地落八荒』"NOR"的绝情杀着，气吞万里如虎，剑意如虹流星坠雨般的向$n罩去，让$n避无可避。",
        "dodge": -30,
        "parry": -10,
          "damage": 100,
        "force": 30,
        "damage_type": "刺伤",
]),
([ "action":"$N喟然叹道：不恨古人吾不见，恨古人、不见吾狂耳～剑影骤然随着那怅然杀意，使出"HIB"『云山千叠，骇浪覆顶』"NOR"向$n层层递去，招招指向要害。",
        "dodge": -40,
        "parry": -20,
          "damage": 120,
        "force":  40,
        "damage_type":  "刺伤",
]),
([ "action":"$N似笑非笑，凄凄念起"HIM"『弃魂散魄』"NOR"心诀。只见$N手上的$w一抹紫孽蒸起，不住旋动，激起一道风刃向$n腰间急劈。",
        "dodge": -40,
        "parry": -25,
          "damage": 150,
        "force": 30,
        "damage_type": "内伤",
]),
([ "action":"$N逆踏八卦，使出"HIR"『乱象错形』"NOR"的奥秘，陷$n於五行易位之漆黑空间。剑首寂然指向京房卦之血脉卦位，只见$n正向跌跌撞撞地向$w奔去....",
        "dodge": -10,
        "parry": -10,
          "damage": 180,
        "force": 40,
        "damage_type": "刺伤",
]),
([ "action":"$N意念一起一息之间，身形已然"HIY"『如入不动魔地』"NOR"，手中$w影如来如去，无声亦无息地递向$n$l....",
        "dodge": -15,
        "parry": -5,
          "damage": 200,
        "force": 50,
        "damage_type": "刺伤",
]),
([ "action":"$N内照形躯、守窍通关，豁然顿悟了"+BLINK+BOLD+WHT+"『"+HIG+"一切有形剑法"+HIW+"，"+HIY+"如梦幻泡影"+HIW+"，"+HIB+"如露亦如电"+HIW+"』"+NOR+"。\n过去所学的血影剑法，一时之间融会贯通，源源不断在手中使出，化为不可思量之势涌向$n....",
        "dodge": -100,
        "parry": -100,
          "damage": 270,
        "force": 50,
        "damage_type": "刺伤",
]),

});
string perform_action_file(string action)
{
        return __DIR__"shadow-kill/"+action;
}
int valid_learn(object me)
{
        object wea;
        if( !(wea = me->query_temp("weapon"))
          || (string)wea->query("skill_type") != "sword" )
          return notify_fail("你必须先找一把剑才能练剑法。\n");
        if( (int)me->query("max_neili") < 100)
          return notify_fail("你的内力上限不足, 不可以练血影剑法。\n");
/*
        if(me->query_skill("windforce",1)*3<=me->query_skill("shadow-kill",1))
          return notify_fail("你的风影心法技能不足，无法练血影剑法。\n");
        if(me->query_skill("golden-steps",1)*3<=me->query_skill("shadow-kill",1))
          return notify_fail("你的青玄身法技能不足，无法体会血影剑法里，移形换位之精义。\n");
*/
        if(me->query("shen")<=6*me->query_skill("shadow-kill",1) )
          return notify_fail("你的杀气不足，不适合训练更高的血影剑法。\n");
        return 1;
}

int valid_enable(string usage) 
{
        return (usage=="sword"||usage=="parry");
}

mapping query_action(object me, object weapon)
{
        int level;
        level = me->query_skill("shadow-kill",1);
        level = (int) level/10;
        if (level < 6 ) return action[random(level)];
        else
   {     
        if (level > 11 ) level = 11;
    }
        return action[random(level-5)+5];
}
// mapping 一节因过于消耗系统资源改变甚多。
int practice_skill(object me)
{
        object wea;
        if( !(wea = me->query_temp("weapon"))
          || (string)wea->query("skill_type") != "sword" )
          return notify_fail("练血影剑法还是要有把剑吧....\n");
        if( (int)me->query("qi") < 30 )
          return notify_fail("体力不够罗,休息一下再继续练吧.\n");
        me->receive_damage("qi", 30);
        return 1;
}

