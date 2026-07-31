// luowang-club.c 紧那罗王棍
// 横扫千军

inherit SKILL; 

mapping *action = ({ 
([      "action" : "$N双目精光暴长，神情怒不可遏，一式[横扫千军]带动无数道黑影,\n"
                    "$w直击$n的$l不待$n做出反应，$w竟然毫无章法似的向$n全身乱劈过去，\n"
                    "速度极快$n只觉眼前尽是棍影而不见人",     
        "dodge"  : 65, 
        "parry"  : 60, 
        "attack" : 60, 
        "damage" : 140, 
        "damage_type": "刺伤" 
]), 
}); 

string main_skill() { return "luowang-club"; } 

int valid_enable(string usage) { return usage == "club" ||  usage == "parry"; }   

int valid_learn(object me) 
{ 
        object weapon;
        
        if (! objectp(weapon = me->query_temp("weapon"))
        ||  (string)weapon->query("skill_type") != "club")
                return notify_fail("你手中无棍怎么学习啊。\n");
                
        if ((int)me->query("str") < 25 &&
            (int)me->query("con") < 25)
                return notify_fail("就你这身子骨还练紧那罗王棍？小心身体吃不消。\n"); 
                
        if ((int)me->query_skill("hunyuan-yiqi") < 200) 
                return notify_fail("你的混元一气功火候不够,无法学习紧那罗王棍。\n"); 
                
        if ((int)me->query_skill("force") < 200) 
                return notify_fail("你的内功火候不够,无法学习紧那罗王棍。\n"); 
                
        if ((int)me->query_skill("buddhism") < 200) 
                return notify_fail("你的禅宗心法火候不够,无法学习于禅宗息息相关紧那罗王棍。\n"); 
                
        if ((int)me->query("max_neili") < 2000) 
                return notify_fail("你的内力太差,无法学习紧那罗王棍。\n"); 

        if ((int)me->query_skill("club", 1) < 200) 
                return notify_fail("你的基本棍法火候不够，无法学习紧那罗王棍。\n"); 

        if ((int)me->query_skill("club", 1) < (int)me->query_skill("hengsao-qianjun", 1)) 
                return notify_fail("你的基本棍法水平有限，无法领会更高深的紧那罗王棍。\n"); 

        return 1; 
} 

mapping query_action(object me, object weapon) 
{ 
        return action[random(sizeof(action))]; 
} 
int practice_skill(object me)  
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
        ||  (string)weapon->query("skill_type") != "club")
                return notify_fail("你使用的武器不对。\n");
                
        if ((int)me->query("qi") < 70)  
                return notify_fail("你的体力太低了。\n"); 

        if ((int)me->query("neili") < 70) 
                return notify_fail("你的内力不够练紧那罗王棍。\n"); 

        me->receive_damage("qi", 60); 
        me->add("neili", -60); 
        return 1; 
} 

