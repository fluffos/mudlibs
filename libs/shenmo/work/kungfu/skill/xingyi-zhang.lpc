// xingyi-zhng 斗转星移掌
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「幻形变影」，双手划了个半圈，按向$n的$l",
        "force" : 260,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 180,
        "lvl" : 0,
        "skill_name" : "幻形变影",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手虚按，右手使一招「星星点点」，向$n的$l推去",
        "force" : 350,
        "dodge" : 10,
        "damage" : 180,
        "lvl" : 40,
        "skill_name" : "星星点点",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手握拳，向前向后划弧，一招「漫天星斗」打向$n的$l",
        "force" : 400,
        "dodge" : 15,
        "parry" : 5,
        "damage" : 180,
        "lvl" : 80,
        "skill_name" : "漫天星斗",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手虚划，右手一记「五斗星辰」击向$n的腰部",
        "force" : 450,
        "dodge" : 20,
        "parry" : 0,
        "damage" : 180,
        "lvl" : 100,
        "skill_name" : "五斗星辰",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N施出「北斗七星」，右手击向$n的$l，左手攻向$n的裆部",
        "force" : 480,
        "dodge" : 20,
        "lvl" : 110,
        "damage" : 180,
        "skill_name" : "北斗七星",
        "damage_type" : "瘀伤"
]),                                                   
([      "action" : "$N跃起在半空，双掌卷起数道罡风，一式「追星赶月」迅捷无比地劈向$n",
        "force" : 500,
        "dodge" : 35,
        "damage" : 180,
        "parry" : -10,
        "lvl" : 150,
        "skill_name" : "追星赶月",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
/*
int valid_combine(string combo,object me) { 
         object me;
         me = this_player();
       if ((me->query("family/family_name") == "姑苏慕容") && (me->query("family/generation") == 2))
     return combo=="canhe-zhi"; 
}
*/
int valid_combine(string combo)  
{
         object me = this_player();
         mapping myfam = (mapping)me->query("family");

                 return combo=="canhe-zhi";
}
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练斗转星移掌必须空手。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("你的神元功火候不够，无法学斗转星移掌。\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力太弱，无法练斗转星移掌。\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        string msg;
        level   = (int) me->query_skill("xingyi-zhang",1);
        
        if (me->query_skill("xingyi-zhang",1) > 200
             && me->query_skill("parry",1) > 80
             && random(10) >7){
                switch(random(4)){
                        case 3: msg = HIR"$N双掌收在胸前，移形换步闪电般将「"HIW"气旋"HIR"」击向$n的檀中穴"NOR; break;
                        case 2: msg = HIG"紧接着$N抽出左掌，身形一矮，由下而上猛袭向$n的小腹"NOR; break;
                        case 1: msg = HIR"只见$N右掌随后而至，凌空一跃，犹如晴空霹雳拍向$n的头部"NOR; break;
                        case 0: msg = HIY"$N在空中一个回转，携「"HIR"日月之光"HIY"」, 双掌按向$n的丹田"NOR; break;
                      
                }    
                return([      
                        "action": msg,        
                        "force" : 600+random(150),
                        "dodge" : 20,
                        "damage" : 600+random(150),
                        "damage_type" : me->query_temp("mr_riyue")?"内伤":"瘀伤",
                ]);
        }
            
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练斗转星移掌。\n");
        me->receive_damage("jing", 25);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"xingyi-zhang/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shenyuan-gong",1);
        skill = me->query_skill("shenyuan-gong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenyuan-gong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "shenyuan-gong" || me->query_skill_mapped("force") == "shenyuan-gong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"凝神运气向$n猛攻快打，使出的招数好似$n的成名绝技，把$n的招数化于无行！\n"NOR;
ob->start_busy(3);
if (random(2)==0)
{
msg += HIC"$N"+HIC+"使出星移斗转，$n这招莫名其妙的在中途转了方向，直奔自己袭来!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}

}

           message_vision(msg, me, ob);
           return j;
}      
}