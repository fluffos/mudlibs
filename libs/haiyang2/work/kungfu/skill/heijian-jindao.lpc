//heijian-jindao
#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

string  *sword = ({
"$N右脚向前一步，左膝提起，$w向前，从上方划出一招「后羿射日」，刺向$n的$l",
"$N一招「妲姬笑」，双脚轻点，向前两步跃落，右手$w由上向前劈下，飘逸地点向$n的$l",
"$N提起左腿，转身垫步，接着右脚跟进，一招「虚式分金」，$w中宫直进，刺向$n的$l",
"$N右脚后撤一步，一转身，右手$w向后反击，一招「荆轲刺秦」，抹向$n的$l",
"$N虚步提腰，一招「四面楚歌」，手中$w轻轻颤动，一剑剑点向$n的全身大穴",
"$N向前跨上一步，左手剑诀，右手$w使出一式「定阳针」，剑尖直刺$n的$l",
"$N一招「李代桃僵」，$w自上而下划出一个道寒光，平平地向$n的$l挥去",
"$N叫道：“看剑！”$w颤动，当胸刺去，可是剑尖并非直进，却是在$n身前乱转圈子",
"$N出手快极，$n后跃退避，$w划成的圆圈又已指向$n身前，剑圈越划越大",
"$N回身拧腰，右手虚抱，一招「九品莲台」，$w中宫直进，中正平和地刺向$n的$l"
});

string  *blade = ({
"$N神色肃杀手中刀光闪烁不定，「气吞六合」一片刺骨的刀风将$n团团围住，另一只手剑法蓄势无穷!",
"$N一招「乾坤倒转」，手中$w在空中虚劈数下本是刀法，突然变成剑法下划割向$n的$l",
"$N身随刀进，青光闪跃，一招「苍鹰望月」，直攻$n右肩，半徒刀锋兜了个半圆，另一只手剑法却攻向$n的$l",
"$N将手中$w向右一立，一手剑法圈转虚划，随即刀光一闪以「猛虎下山」之势扑向$n",
"$N挥动$w本以剑法轻轻刺出，突然中途横砍直削使出刀法中一招「飞沙走石」$w一道电光劈向$n",
"$N手腕微震，$w斗地弯弯的绕了过去，正中$n的$l，鲜血迸出。",
"$N口中突然暴喝，左手画了个圆圈，右手以刀柄抵住手掌，一招「气吞山河」向$n猛压下去"
});
void weapon_attack(object me, object victim);
int valid_enable(string usage) { return (usage == "sword") ||(usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 800)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("sword", 1) < 20)
		return notify_fail("你的基本剑法火候太浅。\n");
	if ((int)me->query("jing") < 80)
		return notify_fail("你的体力不够学黑剑金刀。\n");
	me->receive_damage("jing", 10);

	return 1;
}
mapping query_action(object me, object weapon)
{
        object target;
        int i, level, n;
        string msg,str;
        level = me->query_skill("heijian-jindao",1);
	if (objectp(weapon)) {
	if (me->query_temp("heijian-jindao/luanren",1)&&!me->query_temp("heijian-jindao/doublt_attack",1)&& objectp(target = me->select_opponent())) {
		me->set_temp("heijian-jindao/doublt_attack",1);
		weapon_attack(me,target);
		me->delete_temp("heijian-jindao/doublt_attack");
	}
      if (me->query_temp("heijian-jindao/nizhuan",1)) {
        if(weapon->query("skill_type") == "blade" ) {
          	str = HIB+sword[random(sizeof(sword))]+NOR;
     		str = replace_string(str, "$w", weapon->name()+HIB);       
                return ([
                        "action": str+"!\n$N手中$w刺挑削洗，反而全走的剑法轻灵路子",
                        "damage": level*3/2+100,
                        "damage_type": "刺伤",
                        "dodge": random(level/10)*2-20,
                        "parry": random(level/10)*2-10,
                        "force": level*2/3,
                ]);  }
        if(weapon->query("skill_type") == "sword" ) {
          	str = HIY+blade[random(sizeof(blade))]+NOR;
     		str = replace_string(str, "$w", weapon->name()+HIY);       
                return ([
                        "action": str+"!\n$N手中$w硬砍猛斫，竟然使上了阳刚的刀法",
                        "damage": level*2/3+100,
                        "damage_type": "割伤",
                        "dodge": random(level/10)*2+20,
                        "parry": random(level/10)*2+10,
                        "force": level*3/2,
                ]);  }
	} else {
        if(weapon->query("skill_type") == "sword" ) {
          	str = sword[random(sizeof(sword))];
                return ([
                        "action": "$N手中$w刺挑削洗轻灵无比。\n"+str,
                        "damage": level+100,
                        "damage_type": "刺伤",
                        "dodge": random(level/20)-20,
                        "parry": random(level/20)-10,
                        "force": level/3,
                ]);  }
        if(weapon->query("skill_type") == "blade" ) {
          	str = blade[random(sizeof(blade))];
                return ([
                        "action": "$N手中$w硬砍猛斫刚烈绝伦。\n"+str,
                        "damage": level/3+100,
                        "damage_type": "割伤",
                        "dodge": random(level/20)+20,
                        "parry": random(level/20)+10,
                        "force": level,
                ]);  }
  }
}
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用的武器不对。\n");
       if(weapon->query("skill_type") !="sword"&&weapon->query("skill_type") !="blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("heijian-jindao",1) < 200)
		return notify_fail("必须要有一定基础才能练!。\n");
	if ((int)me->query("neili") < 180)
		return notify_fail("你的体力不够练黑剑金刀。\n");

	if ((int)me->query("jing") < 80)
		return notify_fail("你的体力不够练黑剑金刀。\n");
	me->receive_damage("jing", 50);
	me->add("neili", -50);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
       	if ( me->query("max_neili") > 1200 && me->query("neili") > 1000 && random(10) >= 7
		&&!me->query_temp("heijian-jindao/nizhuan",1)
		&&!me->query_temp("heijian-jindao/luanren",1)
		&&!me->query_temp("heijian-jindao/doublt_attack",1)
       	&& random(me->query_int()) > 10 
       	&& !me->is_busy()
       	&& random(me->query("combat_exp")) > victim->query("combat_exp")/3){
			weapon_attack(me,victim);
		}

}
/*
int ob_hit(object ob, object me, int damage)
{
       	          
}
*/
void weapon_attack(object me, object victim)
{
	object weapon,weapon2;
	object *inv;
	int i,damage,level,j;
	string msg;
	if (!me || !victim || !me->is_fighting(victim))
		return;
	if (me->is_busy())
	return;
	weapon = me->query_temp("weapon");
	level=me->query_skill("heijian-jindao",1);
       inv = all_inventory(me);
	i = 1;
       for(i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
		if (weapon->query("skill_type") == "blade") {
        	   if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   i = 3;
			   break;
		   }
		}
		if (weapon->query("skill_type") == "sword") {
   	        if( inv[i]->query("skill_type") == "blade" ) 
		   {
			   weapon2 = inv[i];
			   i = 2;
			   break;
		   }
		}
       }

	if(me->query_temp("heijian-jindao/doublt_attack") && !me->query_temp("heijian-jindao/doublt_attack1")
	&& objectp(weapon2)
	&& !me->is_busy()
	) {
		me->set_temp("heijian-jindao/doublt_attack1", 1);
              weapon->unequip();
              weapon2->wield();
		COMBAT_D->do_attack(me, victim, weapon2, i);
		COMBAT_D->do_attack(me, victim, weapon2, i);
              weapon2->unequip();
              weapon->wield();
		me->delete_temp("heijian-jindao/doublt_attack1");
	} else if (!me->query_temp("heijian-jindao/doublt_attack1")){
		
		switch(i) {
			case 1: msg = "$N"+weapon->name() + HIG"一抖招数转变，";break;
			case 2: msg = "$N"+weapon->name() + HIG"剑招突然变成刀法，随即探出"+weapon2->name()+HIG"使了一招剑法，";damage = level*2;break;
			case 3: msg = "$N"+weapon->name() + HIG"刀法突然变成剑招，随即探出"+weapon2->name()+HIG"使了一招刀法，";damage = level+random(level);break;
			default: msg = "$N"+weapon->name() + HIG"一抖招数转变，";damage = level;break;
		}
		message_vision(HIG+msg+ "正是“阴阳倒乱刃法”端的凌厉无比！\n"HIR"$n来不及应付被攻得措手不及连连倒退。\n"NOR,me,victim);
 		if (!victim->is_busy()) victim->start_busy(4-i+random(2)+1);
      if (i>1&&weapon2
      && !me->is_busy()) {
         	victim->receive_damage("qi", damage , me);
              victim->receive_wound("qi", damage , me);
              j = (int)victim->query("eff_qi") * 100 / (int)victim->query("max_qi");
              msg = damage_msg(damage, "割伤") + "( $n"+eff_status_msg(j)+" )\n";
        	msg = replace_string(msg, "$l", "胸口");
        	msg = replace_string(msg, "$w", weapon2->name());
		message_vision(msg,me,victim);
	}
	}
}
string perform_action_file(string action)
{
        return __DIR__"heijian-jindao/" + action;
}
