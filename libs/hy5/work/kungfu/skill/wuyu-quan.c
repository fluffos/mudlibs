//侠客神功之五狱拳
//      共分六式：
//           闲过信陵饮
//           五狱倒为轻
//           眼花耳热后
//           千秋二壮士
//           纵死侠骨香
//           持觞劝侯嬴    

//wuyu-quan.c.五狱拳 
//date:1997.9.11
//by dan
#include <ansi.h>
inherit SKILL;

mapping *action = ({
    ([   "action"  :"$N使出一招「闲过信陵饮」，双拳一错，幻出数十个拳影向$n全身罩去",
         "lian"    :"$N使出一招「闲过信陵饮」，双拳一错，幻出数十个拳影向假象敌全身罩去",
         "zhaoshi" : "「闲过信陵饮」",
         "sen"   : 8,
         "parry" : 20,
         "dodge" : 20,
         "jibie" : 0,
         "wound" : 10,    
         "damage": 250,
         "damage_type":  "瘀伤"
    ]),
    ([   "action"  :"$N一招「五狱倒为轻」，腾空而起，和身双拳向$n击去",
         "lian"    :"$N一招「五狱倒为轻」，腾空而起，和身双拳向假象敌击去",
         "zhaoshi" : "「五狱倒为轻」",
         "damage" : 250,
         "wound"  : 15, 
         "sen"    : 9,
         "parry"  : 20,
         "dodge"  : 20,
         "jibie"  : 30,   
         "damage_type":  "瘀伤"
    ]),
    ([   "action"  :"$N使出，「眼花耳热后」一声大喝，趁$n未有反应，双拳分袭$n的胸腹",
         "lian"    :"$N使出，「眼花耳热后」一声大喝，趁$n未有反应，双拳分袭假象敌的胸腹",
         "zhaoshi" : "「眼花耳热后」",
         "sen"   : 10,
         "jibie" : 60,
         "parry" : 30,
         "dodge" : 20,
         "damage": 370,
         "damage_type":  "瘀伤"
    ]),
    ([   "action": "$N双拳一错，使出「千秋二壮士」，对准$n连续击出，",
         "lian"  :"$N双拳一错，使出「千秋二壮士」，对准假象敌连续击出，",
         "zhaoshi" : "「千秋二壮士」",
         "damage":  280,
         "wound" :  15, 
         "sen"  :  8,
         "parry" : 30,
         "dodge" : 20,
         "jibie":    100,
         "damage_type":  "瘀伤"
    ]),
    ([   "action": 
"$N鼓起全部气力于左拳，只听见骨节爆响的声音，一招「纵死侠骨香」迅猛地向$n击去",
         "lian"  : 
"$N鼓起全部气力于左拳，只听见骨节爆响的声音，一招「纵死侠骨香」迅猛地向$n击去",
         "zhaoshi" : "「纵死侠骨香」",
         "sen"  : 10,
         "jibie": 120,
         "parry" : 10,
         "dodge" : 40,
         "damage": 320,
         "damage_type":  "瘀伤"
    ]),
    ([   "action":"$N使出「持觞劝侯嬴 」，化出数道身形同时击向$n的$l",
         "lian" :"$N使出「持觞劝侯嬴 」，化出数道身形同时击出。",
         "zhaoshi" : "「持觞劝侯嬴 」",
         "sen"   : 8,
         "jibie" : 140,
         "damage": 300,
         "wound" : 20, 
         "parry" : 10,
         "dodge" : 25,
         "damage_type":  "瘀伤"
    ]),   
});

string * parry_msg = ({
    "$n一招「持觞劝侯嬴 」，双掌翻舞，$N眼前一花，失去了$n的踪影。\n",
    "$n两手握拳，一招「千秋二壮士」，格开了$N的一击。\n",
    "但见$n一招「闲过信陵饮」，跟上一步，化开了$N的攻势。\n",
});
    
int valid_learn(object me)
{
    if ( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
    {    
        write("练五狱拳必须空手。\n");
        return 0;
    }
   
    if ( me->query("max_neili") < 200 )
    {   
        write("你的内力太弱，无法练五狱拳\n");
        return 0;
    }
    return 1;
}

string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="cuff";
}

int valid_combine(string combo) { return combo=="xiuli-qiankun"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}






int practice_skill(object me)
{
	if( (int)me->query("jing") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("neili") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);

	return 1;
}

string perform_action_file(string func)
{
	return __DIR__"wuyu-quan/"+func;
}




int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        string result;
        int ap, dp, mp;
        ap = (int)me->query("combat_exp");
        dp = (int)ob->query("combat_exp");
j=damage;
if (me->query_skill_mapped("force") != "taixuan-gong")
return damage;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return damage;

        if ((int)me->query_skill("literate", 1)> 5 )	
return damage;

if (me->query("neili") < 500)
return damage;
 if (objectp(weapon = me->query_temp("weapon"))
        )
return damage;

             
  if (random(ap) < dp/2  
  && random(2)==0)
        {

                switch (random(2))
                {
                case 0:
                        result =  HIR "$n" HIR "默念太玄功口诀，太玄内"
                                            "劲齐聚于全身，$N" HIR "只觉这招攻在"
                                            "$n" HIR "身上\n，犹如碰到铜墙铁壁一般，"
                                            "丝毫不起作用。\n"NOR;
                        break;
                case 1:
                        result =  HIR "$N" HIR "一招击中$n" HIR "上身"
                                            "，可却犹如击在铜墙铁壁上一般\n，力道顿时"
                                            "消失得无影无踪。\n" NOR;
                        break;
                default:
                        result =  HIR "但见$n" HIR "一声轻啸，浑若无事"
                                            "的接下了$N" HIR "这一招，\n却没有受到"
                                            "半点伤害。\n" NOR;
                        break;
                }
message_vision(result,ob,me);
                                    if (!ob->is_busy()) ob->start_busy(3);
if ((int)me->query("qi") < (int)me->query("eff_qi")*2)
me->add("qi",damage/5+200);
if ((int)me->query("eff_qi") < (int)me->query("max_qi")*2)
me->add("eff_qi",damage/5+200);
            damage=100;
            j=100;
            damage=-(damage/2);
j=damage;
            return j;

        }

}




mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("taixuan-gong", 1);
        if (random(me->query_skill("taixuan-gong",1)) < 60 ||		             me->query_skill("force",1) < 100 )
        return 0;


if (me->query_skill_mapped("force") != "taixuan-gong")
return 0;
if (me->query("neili") < 500)
return 0;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return 0;

        if ((int)me->query_skill("literate", 1)> 5 )	
return 0;
	jiali = me->query("jiali");

if (!jiali) jiali=90;
	if( damage_bonus > 20 && random(me->query_skill("taixuan-gong",1))>120 
	) {
	victim->receive_wound("qi", (random(jiali)+80));
return random(2) ? HIW "$N" HIW "一招攻出，竟卷起千层气浪，太玄内劲"
                                   "顿时源源不绝涌入$n" HIW "体内！\n" NOR:
                                   HIW "$N" HIW "太玄内劲迸发，$n" HIW "只感全身一"
                                   "震，登时“喀喀喀”断了数根肋骨！\n" NOR;
}
}