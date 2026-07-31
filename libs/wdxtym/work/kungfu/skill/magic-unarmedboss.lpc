//npc武功，不开放!!
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
//inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([  "action" : "\n$N打出一道 "HIC"审判之圣雷"NOR" 一记勾拳，勾向$n的$l。\n",
        "force" : 8620,
        "dodge" : 100,
        "parry" : 100,
        "damage": 8600,
        "damage_type" : "抓伤",
]),
([      "action" : "$N打出一道 "HIY"大阳之箭"NOR" 一记直拳，直捣$n的$l。",
        "force" : 8620,
        "dodge" : 100,
        "parry" : 100,
        "damage": 8600,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N打出一道 "HIB"暗黑核融术"NOR" 一记摆拳，直摆$n的$l。",
        "force" : 8620,
        "dodge" : 100,
        "parry" : 100,
        "damage": 8600,
        "damage_type" : "瘀伤"
]),
([      "action" : "\n$N打出一道 "HIW"绝对零冰冻"NOR" 一记重拳，击向$n的$l。",
        "force" : 8620,
        "dodge" : 100,
        "parry" : 100,
        "damage": 8600,
                "damage_type" : "内伤"
]),
([      "action" : "$N打出一道 "HIM"地狱力场"NOR" 一套组合拳， 直攻$n的要害部位。",
        "force" : 8620,
        "dodge" : 100,
        "parry" : 100,
        "damage": 8600,
        "damage_type" : "瘀伤",
]),

([      "action" : "$N打出一道 "HIR"琰魔焦热地狱"NOR"  直攻$n的要害部位。",
        "force" : 8620,
        "dodge" : 100,
        "parry" : 100,
        "damage": 8600,
        "damage_type" : "瘀伤",
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"|| usage=="hand"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练拳击必须空手。\n");
        if ((int)me->query("max_force") < 200)
                return notify_fail("你的内力太弱，无法练拳击。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("magic-unarmedboss", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 300)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 300)
                return notify_fail("你的内力不够练拳击。\n");
        me->receive_damage("qi", 300);
        me->add("neili", -300);
        return 1;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("magic-unarmedboss",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(2)==1 && random(level) > 160)
	{
        if (userp(victim))
        victim->start_busy(3+random(2));
else    victim->start_busy(3);
        return HIC "「冰晶术!!」！$N突然念咒,用了一个魔法，$n被冰冻住暂时不能动了!!\n" NOR;
	}
  	if( random(2)==1 && random(level) > 160)
	{
        if (userp(victim) && victim->query("eff_qi") > 50
        && victim->query("qi") > 50)
{
if (victim->query("qi")/12 > 20)
        victim->add("qi",-victim->query("qi")/12);
if (victim->query("eff_qi")/12 > 20)
        victim->add("eff_qi",-victim->query("eff_qi")/12);
}else 
{
        victim->add("qi",-200);
        victim->add("eff_qi",-200);
}
        return HIB "「暗黑核融术!!」！$N突然念咒,用了一个魔法，$n被炸得飞了起来!!\n" NOR;
	}
 	if( random(2)==1 && random(level) > 150)
	{
        if (userp(victim) && victim->query("jing") > 50
        && victim->query("eff_jing") > 50)
{
if (victim->query("jing")/12 > 20)
        victim->add("jing",-victim->query("jing")/12);
if (victim->query("eff_jing")/12 > 20)
        victim->add("eff_jing",-victim->query("eff_jing")/12);
}
else {
        victim->add("jing",-1000);
        victim->add("eff_jing",-1000);
}
        return HIW "「流星光矢!!」！$N突然念咒,用了一个魔法，$n被打中后觉得头痛无比!!\n" NOR;
	}
if (damage_bonus < 100) damage_bonus=100;
        if( damage_bonus > 200 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );
        return HIR "勾拳!!一阵拳影！！！一股鲜血从$n的身子喷出\n" NOR;	
}
        if( damage_bonus < 120 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return YEL "直拳!!一阵拳影！！！$n闷哼一声,身子晃了两晃！\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus );	
        victim->receive_wound("qi", damage_bonus );	
        return HIM "冲拳!!一阵拳影！！！你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;
}

}
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("magic-unarmed", 1);

//        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 150  && random(2) ==1   ){
         msg = RED"$N面对$n的攻势。身形一闪，突然施放魔法!!!。\n"NOR;
            message_vision(msg, me, ob);
            if ( random(2) == 0 && random(level) > 150){
         msg = YEL"「 地精附身! 」。$N突然念咒,用了一个魔法，$n感觉被大地吸住不能动了!!。\n"NOR;
//             if (!ob->is_busy())
        if (userp(ob) && ob->query("qi") > 50 && ob->query("jing") > 50
        && ob->query("eff_qi") > 50 && ob->query("eff_jing") > 50){
             ob->start_busy(3+random(2));
if (ob->query("qi")/12 > 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}
else
{
             ob->start_busy(3);
             ob->add("qi",-1000);
             ob->add("eff_qi",-1000);
}
msg += damage_msg(damage, "瘀伤");
            }
else  if (random(2)==1&& random(level) > 150){
         msg = HIR"「火炎球!」。$N突然念咒,用了一个魔法，$n被一个火球打中了!!\n"NOR;
        if (userp(ob) && ob->query("qi") > 50 
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/15);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/25);
}
else {
             ob->add("qi",-2000);
             ob->add("eff_qi",-2000);
}
msg += damage_msg(damage, "瘀伤");
            }
else  if (random(2)==2&& random(level) > 150){
         msg = HIC"「霹雳闪电!」。$N突然念咒,用了一个魔法，$n被一个闪电打中了!!\n"NOR;
        if (userp(ob) && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50)
{
if (ob->query("qi")/12 > 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
if (ob->query("jing")/12 > 20)
             ob->add("jing",-ob->query("jing")/12);
if (ob->query("eff_jing")/12 > 20)
             ob->add("eff_jing",-ob->query("eff_jing")/12);
}
else
{
             ob->add("qi",-1000);
             ob->add("eff_qi",-1000);
             ob->add("jing",-1000);
             ob->add("eff_jing",-1000);
}
msg += damage_msg(damage, "瘀伤");
            }
else
           msg = HIG"$n抢先出招，使$N的念咒失败了!。\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
