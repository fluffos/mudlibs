// zileidao.c 【紫雷刀法】

#include <ansi.h>

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string* skill_head =({
        "$N身形稍退，使出一招 惊雷爆五岳",
        "$N仰天长笑，看也不看，一招 沉雷地狱",
        "$N轻轻一跃，使了个 春雷暴极",
        "$N神态悠闲，一招 冬雷霹雳",
        "$N身形转个不停，突然一招 狂雷震九宵",
        "$N脚下踏了个朝阳步，一招 雷霆霹雳",
});

string* skill_tail =({
        "，手中$w势若飞瀑向$n拦腰一斩",
        "，手中$w对准$n的$l凌空一斩",
        "，反手将$w对准$n$l一剑劈去",
        "，手中$w轻妙地划向$n的$l",
        "，反手对准$n$l一刀劈去",
        "，趁$n转身之际，挥出一刀",
});


mapping *action = ({
        ([      "action":		"$N轻抚手中的$w，突然间只见刀光一闪，再闪，又一闪！\n使出一招"YEL"「春雷暴极」"NOR"，三道刺骨的寒气已然袭上了$n的$l",
     		"dodge":     15,
     		"parry":     5,
     		"damage":    325,
     		"damage_type":     "割伤"
        ]),
        ([      "action":		"只见$N倒提$w，身形急冲，就在与$n错身之际，一招"HIR"「沉雷地狱」"NOR"突然反手一刀从$n后脑斜劈而下",
     		"dodge":     15,
     		"parry":     5,
                "damage":    330,
                "damage_type":     "劈伤"
        ]),
        ([      "action":		"$N斜身飞起，带出一片匹练也似的刀光卷向$n的$l，好一招"HIG"「天旋地转」"NOR"。",
                "dodge":     15,
     		"parry":     5,
                "damage":    335,
                "damage_type":     "劈伤"
        ]),
        ([      "action":		"$N突然一脚踢出，使出"HIY"「冬雷霹雳」"NOR"，手中的$w划出一道轻妙的圆弧，\n淡淡的刀光封住了$n的头脸，切断了$n的呼吸",
                "dodge":     15,
     		"parry":     5,
                "damage":    330,
                "damage_type":     "割伤"
        ]),
        ([      "action":		"只见$N脸色一寒，一招"HIB"「狂雷震九宵」"NOR"使出，从眉捷到脚跟，\n$n周身的血液都似被这无尽的刀势冻住，而生命也仿佛要离体而去",
                "dodge":     15,
     		"parry":     5,
                "damage":    340,
                "damage_type":     "劈伤"
        ]),   
        ([      "action":		""HIM"「惊雷爆五岳」"NOR"使出，$N刀势渐慢，而$w上带出的寒气却越来越浓。\n就在这时，$n的心头一紧，一道比针尖还要锐利的寒气已刺上了$n$l",
                "dodge":     15,
     		"parry":     5,
                "damage":    350,
                "damage_type":     "刺伤"
        ]),   
        ([      "action":		"$N也不管三七二十一，高举$w呼！地就是一刀向$n迎面斩下！\n虽然只有一刀，可怕的刀势却似万古不化的寒冰封死了$n的一切退路，\n这招"HIC"「怒雷撕天裂地」"NOR"好狠那",
                "dodge":     15,
     		"parry":     5,
                "damage":    560,
                "damage_type":     "劈伤"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的内力不够，没有办法练紫雷刀法，多练些内力再来吧。\n");


  if( (string)me->query_skill_mapped("force")!= "lengyue-shengong")
     return notify_fail("必须冷月神功才能学。\n");

if ((int)me->query_skill("baisheng-daofa", 1) < 200)
		 return notify_fail("你的百胜刀法 火候不够，无法学。\n");

if ((int)me->query_skill("daojian-guizhen", 1) < 100)
		 return notify_fail("你的刀剑归真火候不够，无法学手。\n");


if( (int)me->query_skill("martial-cognize",1) < 200 )
		return notify_fail("你的武学修养不够。\n");

	if( (int)me->query_skill("sixiang-bufa",1) < 200 )
		return notify_fail("你的四象步法不够。\n");


   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "blade" )
     return notify_fail("你必须先找一把刀才能练刀法。\n");

        return 1;
}

int valid_enable(string usage)
{
  return usage =="blade" || usage=="parry";
}



int practice_skill(object me)
{
        if( (int)me->query("qi") < 60 || (int)me->query("neili") < 50 || (int)me->query("jing") < 60 )
                return notify_fail("你的内力或气不够，没有办法练习紫雷刀法。\n");

       if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的内力不够，没有办法练紫雷刀法，多练些内力再来吧。\n");


  if( (string)me->query_skill_mapped("force")!= "lengyue-shengong")
     return notify_fail("必须冷月神功才能学。\n");

if ((int)me->query_skill("baisheng-daofa", 1) < 200)
		 return notify_fail("你的百胜刀法 火候不够，无法学。\n");

if ((int)me->query_skill("daojian-guizhen", 1) < 100)
		 return notify_fail("你的刀剑归真火候不够，无法学手。\n");


if( (int)me->query_skill("martial-cognize",1) < 200 )
		return notify_fail("你的武学修养不够。\n");

	if( (int)me->query_skill("sixiang-bufa",1) < 200 )
		return notify_fail("你的四象步法不够。\n");


        me->receive_damage("qi", 30);
        me->receive_damage("jing", 30);
//        write("你按着所学练了一遍紫雷刀法。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("zileidao",1);
         lvl = (int)me->query_skill("zileidao", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
        string msg;
        int ap,dp;
	
	weapon = me->query_temp("weapon");	
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("lengyue-shengong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("zileidao",1))+50;
if (damage > 1600) damage=1600;

if (random(12)==0 && level2>=300 && me->query_skill_mapped("force") == "lengyue-shengong")
{
        ap = me->query_skill("blade");
        ap += 20+(me->query_str())*2;
        dp =  victim->query_skill("parry");
        
        weapon = victim->query_temp("weapon");	

   if(objectp(weapon) && me->query_skill("blade")>300){ 
        if( random(ap+dp) > dp && random(2)>0){
        if(me->query("neili") > random(victim->query("neili"))){
                         if(random(2)==0){  
                               weapon->unequip();       
                               victim->start_busy(3);
                               victim->receive_damage("qi", ap);  
                               victim->receive_wound("qi", ap);      
         msg = MAG"只听“铛”的一声，$n手中的$w已被你挑飞。$n也被你的魔气所伤。\n"NOR ;
                                msg = replace_string(msg, "$w", weapon->name());    
                               }
                        else{
                               victim->start_busy(3);
msg = HIM"只听“嗡”地一声大响，$n手中的$w在无形霸气的冲击下不住颤抖！\n"NOR ;
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{
  msg = MAG"$N念动真言：“噫嘛啦萨！！”只听“啪”的一声响，$n手中$w已被你震成两段。\n"NOR ;
                                msg = replace_string(msg, "$w", weapon->name());

                                weapon->unequip();
                                //weapon->move(environment(victim));
                                weapon->set("name", "断掉的"+weapon->query("name"));
                                weapon->set("value", 0);
                                weapon->delete("long");
                                weapon->set("weapon_prop", 0);
}                                
                                }
                                }
                   else {       
         msg = HIM"只听“嗡”地一声大响，$n手中的$w在无形霸气的冲击下不住颤抖，险些脱手！\n"NOR ;
                            msg = replace_string(msg, "$w", weapon->name()); 
                                                           }
                }

                return msg; 
    }
	
}		

if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "lengyue-shengong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("zileidao",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}



}


string perform_action_file(string action)
{
	return __DIR__"zileidao/" + action;
}


