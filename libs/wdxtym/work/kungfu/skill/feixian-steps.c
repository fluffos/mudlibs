// feixian-steps.c
// by jeeny
 
#include <ansi.h> 
      
inherit SKILL; 
	
string *parry_msg = ({
	"$n只见落叶纷飞，$N此情此景迷乱了双眼，招式也偏离了轨迹。\n",
	"$n云雾缭绕，$N如白云远上，招式只差一丝之距。\n",
        "$n如谪仙下凡，$N竟分不清虚幻，招式已破，却浑然不觉。\n",
        "$n脚踏落花，$N如凌空飞舞的蝴蝶，躲开了招式。。\n",
        "$n潇洒从容，脚步一转，轻轻松松躲开招式。\n",
	"$n如九天玄女，一舞轻纱，片叶未粘身。\n",
	"$n定身不动，身绽光华，犹如圆月。$N的致命一击竟然悠悠的消散了。\n",
	"$n轻轻一转，$N一招却打在了空地上，只打得尘土飞扬。\n",
});

string *dodge_msg = ({
	"$n只见落叶纷飞，$N此情此景迷乱了双眼，招式也偏离了轨迹。\n",
	"$n云雾缭绕，$N如白云远上，招式只差一丝之距。\n",
        "$n如谪仙下凡，$N竟分不清虚幻，招式已破，却浑然不觉。\n",
        "$n脚踏落花，$N如凌空飞舞的蝴蝶，躲开了招式。。\n",
        "$n潇洒从容，脚步一转，轻轻松松躲开招式。\n",
	"$n如九天玄女，一舞轻纱，片叶未粘身。\n",
	"$n定身不动，身绽光华，犹如圆月。$N的致命一击竟然悠悠的消散了。\n",
	"$n轻轻一转，$N一招却打在了空地上，只打得尘土飞扬。\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}
       
int valid_learn(object me) 
{ 
	int lvl, q; 

        q = me->query("per");
	lvl = me->query_skill("feixian-steps", 1); 
	if (lvl > 300) lvl = 300; 
       
	if (me->query("max_neili") < 200 + lvl * 2 + q * 25) 
		return notify_fail("内力不足，难以修炼我派身法。\n");

 	if (me->query("per") < 30)
		return notify_fail("你如此丑陋相貌也想学我派身法？。\n"); 

	if (me->query("dex") < 20)
		return notify_fail("你身法不佳如何学会我派身法。\n"); 

	return 1; 
} 
       
string query_dodge_msg(string limb) 
{ 
	return dodge_msg[random(sizeof(dodge_msg))]; 
} 
       
mixed valid_damage(object ob, object me, int damage, object weapon) 
{ 
	mixed result; 
	int ap, dp; 
       
	if ((int)me->query_skill("feixian-steps", 1) < 100 || 
	    ! living(me)) 
		return; 
	
	ap = ob->query_skill("dodge") + ob->query("per") * 20;
	dp = me->query_skill("dodge", 1) / 2 + me->query_skill("feixian-steps", 1) + me->query("per") * 30; 
       
	if (ap / 2 + random(ap) < dp) 
	{ 
		result = ([ "damage": -damage ]); 
       
		switch (random(4)) 
		{ 
		case 0: 
			result += (["msg" : "$n只见落叶纷飞，$N此情此景迷乱了双眼，招式也偏离了轨迹。"NOR"\n"]); 
			break; 
		case 1: 
			result += (["msg" : HIW "$N" HIW "$n轻轻一带，$N发现自己的攻击没起到半点作用，面露惊色"NOR"\n"]); 
			break; 
		case 2: 
			result += (["msg" : HIW "$N" HIW "这一招迅疾无比，然而$n" 
					    HIW "身子一扭，似乎不费半点力气，却将" 
					    HIW "$N这一招躲了开去。"NOR"\n"]); 
			break; 
		default: 
			result += (["msg" : HIW "$N" HIW "$n轻轻一带，$N发现自己的攻击没起到半点作用，面露惊色"NOR"\n"]);  
			break; 
		} 
		return result; 
	}
 
} 
      
int query_effect_dodge(object attacker, object me) 
{ 
	int lvl; 
      
	lvl = me->query_skill("feixian-steps", 1); 
	if (lvl < 50)  return 0; 
	if (lvl < 100) return 50; 
	if (lvl < 150) return 70; 
	if (lvl < 200) return 100; 
	if (lvl < 250) return 120; 
	if (lvl < 300) return 140; 
	if (lvl < 350) return 160; 
	if (lvl < 650) return 190; 
	return 200; 
} 
      
int practice_skill(object me) 
{ 
	int cost;

	cost = 60 + (int) me->query_skill("feixian-steps", 1) / 3;
	if ((int)me->query("qi") < 70) 
		return notify_fail("你的体力太差了，难以练习飞仙步法。\n"); 
     
	if ((int)me->query("neili") < cost) 
		return notify_fail("你的内力不够了，无法练习飞仙步法。\n"); 
      
	//me->receive_damage("qi", 50); 
	//me->add("neili", -cost);
	cost = cost>=180?180:cost;
	return cost*30/100; 
} 
      
string perform_action_file(string action) 
{ 
	return __DIR__"feixian-steps/" + action; 
} 

void skill_improved(object me)
{
	int lvl;
	lvl = me->query_skill("feixian-steps", 1);

	if (lvl < 270)
	{
		me->apply_condition("yihua-except", lvl / 2 +
				    (int)me->query_condition("feixian-steps"));
	}
}	     
