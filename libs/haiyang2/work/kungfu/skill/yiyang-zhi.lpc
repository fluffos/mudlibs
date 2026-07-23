#include <ansi.h>
#include <skill.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 

mapping *action_finger = ({
([      "action" : "$N右手食指微点，出招"+(order[random(13)])+"「晓天初阳」"NOR"，一股雄浑的一阳指力射向$n，出手沉稳，招数正大",
        "force" : 200,
    "damage" : 220,
        "weapon" : "一阳指力",
     "parry" : 10,
        "dodge" : 15,
        "lvl" : 0,
        "skill_name" : "晓天初阳",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一指"+(order[random(13)])+"「日出霞光」"NOR"，激出的一股罡气涌向$n，看似是温淳平和，但沛然浑厚，无可与抗",
        "force" : 250,
     "parry" : 25,
        "dodge" : 20,
         "damage" : 250,
        "lvl" : 20,
        "skill_name" : "日出霞光",
        "damage_type" : "内伤"
]),
([      "action" : "忽听嗤嗤轻响，一股柔和的气流自$N手指涌出，正是一招"+(order[random(13)])+"「阳春暖融」"NOR"，缓缓点向$n$l",
        "force" : 300,
     "parry" : 10,
        "dodge" : 10,
    "damage" : 245,
        "weapon" : "一阳指力",
        "lvl" : 40,
        "skill_name" : "阳春暖融",
        "damage_type" : "刺伤"
]),
([      "action": "$N一步跨到$n身后，又如闪电般跃回，一式「鲁阳返日」，右手食指疾出，指向$n的$l",
        "force" : 430,
        "attack": 79,
        "dodge" : 65,
        "parry" : 35,
        "damage": 83,
        "lvl" : 60,
        "weapon" : HIR "一阳指力" NOR,
        "skill_name" : "鲁阳返日",
        "damage_type" : "刺伤"
]),
([      "action": "$N左手轻扬，右手食指挟着雄浑内力疾点$n的$l，招式光明坦荡，正是一式「阳春白雪」",
        "force" : 460,
        "attack": 75,
        "dodge" : 91,
        "parry" : 85,
        "damage": 78,
        "lvl" : 80,
        "weapon" : HIR "一阳指力" NOR,
        "skill_name" : "阳春白雪",
        "damage_type" : "刺伤"
]),
([      "action": "$N身影飘起，一式「阳钩挥天」，身形自上而下闪出，右手猛然劲点向$n的$l",
        "force" : 490,
        "attack": 105,
        "dodge" : 35,
        "parry" : 24,
        "damage": 98,
        "lvl" : 100,
        "weapon" : HIR "一阳指力" NOR,
        "skill_name" : "阳钩挥天",
        "damage_type" : "刺伤"
]),
([      "action" : "$N踏前一步，伸指凌空轻轻一点，$n只觉气息一紧，已被"+(order[random(13)])+"「赤日焦阳」"NOR"的刚阳气劲触到$l",
        "force" : 350,
     "parry" : 15,
     "dodge" : 25,
         "damage" : 280,
        "lvl" : 60,
        "weapon" : "纯阳真气",
        "damage" : 240,
        "skill_name" : "赤日焦阳",
        "damage_type" : "刺伤"
]),
([      "action" : "$N衣袖轻摆，罡阳柔气从袖底挥出，涌向$n的$l，正是玄功若神的一招"+(order[random(13)])+"「晓阳云暖」"NOR"",
        "force" : 400,
     "parry" : 25,
     "dodge" : 25,
         "damage" : 300,
        "lvl" : 80,
        "skill_name" : "晓阳云暖",
        "damage_type" : "内伤"
]),
([      "action": "$N左掌斜削，突然间变掌为指，嗤的一式「丹凤朝阳」，使出一阳指力，疾点$n的$l",
        "force" : 528,
        "attack": 119,
        "dodge" : 24,
        "parry" : 23,
        "damage": 98,
        "lvl" : 180,
        "weapon" : HIR "一阳指力" NOR,
        "skill_name" : "丹凤朝阳",
        "damage_type" : "刺伤"
]),
([      "action" : "$N面带微笑，伸出右食指，缓缓点向$n胸口，这招"+(order[random(13)])+"「暮云映日」"NOR"劲气弥漫，却无丝毫破空之声",
        "force" : 450,
       "parry" : 15,
      "dodge" : 30,
        "damage": 350,
        "weapon" : "一阳指力",
        "lvl" : 100,
        "skill_name" : "暮云映日",
        "damage_type" : "刺伤"
]),
([      "action" : "只见$N食指微屈，一指"+(order[random(13)])+"「九天乾阳」"NOR"点出，气象森严，雍容肃穆，于威猛之中不脱王者风度！",
        "force" : 500,
       "parry" : 30,
      "dodge" : 30,
	    "damage":485,
        "weapon" : "纯阳真气",
        "lvl" : 110,
        "skill_name" : "九天乾阳",
        "damage_type" : "内伤"
]),
([ "action" : HIW"$N头顶白气氤氲，渐聚渐浓，便似蒸笼一般，食指伸出，一式"+(order[random(13)])+"「三阳开泰」"NOR"按向$n！"NOR,
        "force" : 560,
      "parry" : 40,
      "dodge" : 30,
         "damage" : 500,
        "lvl" : 130,
        "skill_name" : "三阳开泰",
        "damage_type" : "震伤"
])
});


mapping *action_sword = ({
([      "action" : "$N嘴角轻笑，提$w平胸，看准时机一剑刺出，激起呼呼风声，迅猛无比地直插$n$l",
        "force" : 200,
        "dodge" : 15,
        "damage" : 250,
        "lvl" : 0,
        "damage_type" : "刺伤",
]),
([      "action" : "$N左手捏个剑诀，右腕传动，将一阳指神功化于$w之上，出剑凝重，平平正正地刺向$n",
        "force" : 250,
        "dodge" : 10,
        "damage" : 370,
        "lvl" : 20,
        "damage_type" : "刺伤",
]),
([      "action" : "只见$N屏息凝神，脚步沉着，剑走刀势，一式横劈，砍向$n$l，招式威猛正大",
        "force" : 300,
        "dodge" : 0,
        "damage" : 390,
        "lvl" : 40,
        "damage_type" : "割伤",
]),
([      "action" : "$N脚下步法微变，身随剑走，端凝自重，极飘逸的一剑向$n刺出，轻灵中却也不失王者气象",
        "force" : 250,
        "dodge" : 10,
        "damage" : 320,
        "lvl" : 60,
        "damage_type" : "刺伤",
]),
([      "action" : "$N平推一剑，手中的$w看似渐渐沉重，使动时略比先前滞涩，但实是举轻若重，威猛之极",
        "force" : 300,
        "dodge" : 15,
        "damage" : 340,
        "lvl" : 80,
        "damage_type" : "刺伤",
]),
});
mapping *action_staff = ({
([      "action" : "$N嘴角轻笑，提$w平胸，看准时机一杖挥出，激起呼呼风声，迅猛无比地直插$n$l",
        "force" : 100,
        "dodge" : 15,
        "damage" : 250,
        "lvl" : 0,
        "damage_type" : "刺伤",
]),
([      "action" : "$N左手捏个杖诀，右腕传动，将一阳指神功化于$w之上，出杖凝重，平平正正地打向$n",
        "force" : 150,
        "dodge" : 10,
        "damage" : 270,
        "lvl" : 20,
        "damage_type" : "内伤",
]),
([      "action" : "只见$N屏息凝神，脚步沉着，杖走刀势，一式横劈，砍向$n$l，招式威猛正大",
        "force" : 200,
        "dodge" : 30,
        "damage" : 290,
        "lvl" : 40,
        "damage_type" : "割伤",
]),
([      "action" : "$N脚下步法微变，身随杖走，端凝自重的一杖向$n击出，轻灵中却也不失王者气象",
        "force" : 250,
        "dodge" : 10,
        "damage" : 320,
        "lvl" : 60,
        "damage_type" : "刺伤",
]),
([      "action" : "$N平推一杖，手中的$w看似渐渐沉重，使动时略比先前滞涩，但实是举轻若重，威猛之极",
        "force" : 300,
        "dodge" : 15,
        "damage" : 340,
        "lvl" : 80,
        "damage_type" : "刺伤",
]),
});
int valid_enable(string usage) 
{  
   return usage=="finger" || usage=="parry" || usage=="unarmed" || usage=="sword" || usage == "staff"; 
}

int valid_learn(object me)
{
       
       if ((string)me->query("gender") != "男性") 
                return notify_fail("一阳指乃是纯阳玄功，你如何可以修习？\n");
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练一阳指必须空手。\n");
//       if (!me->query_skill("kurong-changong", 1))
          if((int)me->query_skill("kurong-changong", 1) < 150)
                return notify_fail("你的内功火候不够，无法学一阳指。\n");

        if ((int)me->query_skill("jinyu-quan", 1) < 80)
		return notify_fail("你的金玉拳火候太浅。\n");
        if ((int)me->query_skill("wuluo-zhang", 1) < 80)
		return notify_fail("你的五罗轻烟掌火候太浅。\n");

       if ((int)me->query("neili") < 800)
                return notify_fail("你的内力太弱，无法练一阳指。\n");
        return 1;
}

int valid_combine(string combo) { return combo=="haotian-zhang"; }

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action_finger)-1; i >= 0; i--)
                if(level >= action_finger[i]["lvl"])
                        return action_finger[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("yiyang-zhi",1);

        if (!weapon) {                
             for(i = sizeof(action_finger); i > 0; i--)
                     if(level >= action_finger[i-1]["lvl"])
                             return action_finger[NewRandom(i, 20, level/5)];
            }        
if ((string)weapon->query("skill_type") == "sword")
{
             for(i = sizeof(action_sword); i > 0; i--)
                     if(level > action_sword[i-1]["lvl"])
                             return action_sword[NewRandom(i, 20, level/5)];        
}
if ((string)weapon->query("skill_type") == "staff")
{
             for(i = sizeof(action_staff); i > 0; i--)
                     if(level > action_staff[i-1]["lvl"])
                             return action_staff[NewRandom(i, 20, level/5)];        
}
}

int practice_skill(object me)
{        
        if ((int)me->query("jing") < 80)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练一阳指。\n");
        if ((int)me->query_skill("jinyu-quan", 1) < 80)
		return notify_fail("你的金玉拳火候太浅。\n");
        if ((int)me->query_skill("wuluo-zhang", 1) < 80)
		return notify_fail("你的五罗轻烟掌火候太浅。\n");
                          
        me->receive_damage("jing", 55);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
      return __DIR__"yiyang-zhi/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    string name,weapon;
    name = xue_name[random(sizeof(xue_name))];

	if (random(me->query_skill("yiyang-zhi", 1)) > 150
	&& me->query_skill_mapped("unarmed") == "yiyang-zhi" 
        && me->query_skill_mapped("parry") == "yiyang-zhi" 
        && me->query_skill("kurong-changong",1) > 50
        ) {
		if(!victim->is_busy()) victim->start_busy(3);
		victim->apply_condition("yyz_damage",30);
victim->receive_wound("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);       
		return CYN "$n被$N点中"RED+name+CYN"，！\n" NOR;
	}
    
	if(me->query_skill("yiyang-zhi", 1) > 100
       && me->query("neili") > 500
       && me->query_skill_mapped("parry") == "yiyang-zhi" 
       && victim->query("neili") > 100
       && me->query_skill("kurong-changong",1) > 50){
         victim->add("neili", -random(120));     
        }   
    if(victim->is_busy()) return 0;
	if (!objectp(weapon = me->query_temp("weapon"))) {
	if((!random(5)) && (me->query("neili")>200) && me->query_skill("yiyang-zhi", 1) > 60
		&& me->query_skill_mapped("unarmed") == "yiyang-zhi" 
        && me->query_skill_mapped("parry") == "yiyang-zhi" 
        && me->query_skill("kurong-changong",1) > 50)
      {

  if( !victim->is_busy() )
{ 
		victim->start_busy(3);
}
        me->add("neili",-30);
		if (victim->query("neili") <=(damage_bonus/2+30))
		victim->set("neili",0);
		else
		victim->add("neili",-damage_bonus/2+50);
victim->receive_wound("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);       
		return CYN "$n被$N凌空一指点中"RED+name+CYN"，真气不由得一滞！\n" NOR;
	} 
	} else 
	{
          if((!random(4)) && (me->query("neili")>200) && me->query_skill("yiyang-zhi", 1) > 60
          	&& me->query_skill_mapped("unarmed") == "yiyang-zhi" 
        && me->query_skill_mapped("parry") == "yiyang-zhi" 
        && me->query_skill("kurong-changong",1) > 50)
	   {
  if( !victim->is_busy() )
{ 
	    victim->start_busy(3);
}
        me->add("neili",-30);
		victim->add("neili",-30);
		victim->receive_damage("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);
        victim->receive_wound("qi", me->query_skill("yiyang-zhi",1)/2+damage_bonus/2);       
		return CYN "$n被$N发出的剑气刺中"RED+name+CYN"，真气不由得一滞！\n" NOR;
	}   
	}
 
}



int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("kurong-changong",1);
        skill = me->query_skill("kurong-changong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "kurong-changong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;

if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}

if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}



msg = HIG"$N 深吸一口气！施展开一阳指诀，以纯阳指力遍布全身! 脸色红润多了。\n"NOR;
           if (!ob->is_busy() && random(3)==0)
{
msg += HIY"$n"+HIY+"被$N的纯阳指力反点! 结果点中了 "+ xue_name[random(sizeof(xue_name))] +NOR;
                ob->apply_condition("yyz_damage",30);
                ob->start_busy(3);  
}

//msg += "$n的力道被太极拳借力打力反击回来！\n",  
           message_vision(msg, me, ob);
           return j;
}      
}

