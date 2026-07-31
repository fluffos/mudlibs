// six-finger.c 六脉神剑之商阳剑
inherit SKILL; 

mapping *action = ({ 
([      "action": "$N食指连动，手腕园转，“商阳剑”一剑又一剑的刺出，轻灵迅速，奇巧活泼，剑气纵横，$n根本无法看清来路",
        "force" : 350,
        "dodge" : 90,    
        "attack": 90,
        "parry" : 90,                        
        "damage": 100,
        "damage_type":  "刺伤"
]),
}); 

string main_skill() { return "six-finger"; } 

int valid_enable(string usage) { return usage=="finger" ||  usage=="parry"; }   

int valid_learn(object me) 
{ 
       if (me->query_skill("six-finger", 1) > 0) 
               return notify_fail("你已经学全六脉神剑了，不必再单独学习。\n"); 

       if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 

       if ((int)me->query("int") < 25)  
               return notify_fail("就你这猪脑子还练六脉神剑？别叫人笑掉大牙。\n"); 

       if ((int)me->query_skill("force") < 90) 
               return notify_fail("你的内功火候不够无法学习六脉神剑。\n"); 

       if ((int)me->query("max_neili") < 600) 
               return notify_fail("你的内力太差无法学习六脉神剑。\n"); 

       if ((int)me->query_skill("finger", 1) < 30) 
               return notify_fail("你的基本指法火候不够，无法学习六脉神剑。\n"); 

       if ((int)me->query_skill("finger", 1) < (int)me->query_skill("shangyang-jian", 1)) 
               return notify_fail("你的基本指法水平有限，无法领会更高深的六脉神剑。\n"); 

       return 1; 
} 

mapping query_action(object me, object weapon) 
{ 
        return action[random(sizeof(action))]; 
} 

int practice_skill(object me)  
{ 
       if ((int)me->query("qi") < 100)  
               return notify_fail("你的体力太低了。\n"); 

       if ((int)me->query("neili") < 100) 
               return notify_fail("你的内力不够练六脉神剑。\n"); 

       me->receive_damage("qi", 90); 
       me->add("neili", -90); 
       return 1; 
} 

string perform_action_file(string action) 
{ 
       return __DIR__"shangyang-jian/" + action; 
} 
