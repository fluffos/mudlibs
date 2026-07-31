//七修剑法 
// 五马分尸，六亲不认，七窍生烟，
// 八方风雨，九死一生，十面埋伏
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
    ([
      "action": "$N手腕一抖，$w剑尖化为五道白光，分别向$n的咽喉、左右肩、和左右脚腕疾刺。\n",
      "parry_msg": "$n手腕一抖，$W剑尖化为五道白光，将之架住。\n",
      "dodge" : 0,
      "parry" : 0,
      "damage": 35,
      "damage_type": "刺伤",
      "name"  : "「五马分尸」",
      ]),
    ([
      "action": "$N关节僵硬，手中$w如一根树干一般横竖乱扫。$n识得这招"+HIW"「六亲不认」"NOR"的威力，连忙躲避不迭。\n",
      "parry_msg" : "$n关节僵硬，手中$W横竖乱扫。这招"+HIW"「六亲不认」"NOR"逼得$N连忙躲避不迭。\n",
      "dodge" : 10,
      "parry" : -20,
      "damage": 40,
      "damage_type": "割伤",
      "name"  : "「六亲不认」",
      ]),
    ([
      "action": "$N纵身跃起，手中$w带起万道银光，向$n的面门点去。这招"+HIB"「七窍生烟」"NOR"果然把$n逼得手忙脚乱。\n",
      "parry_msg": "结果$n纵身跃起，手中$w带起万道银光，把$N逼得手忙脚乱。\n",
      "dodge" : 5,
      "parry" : -10,
      "damage": 30,
      "damage_type": "刺伤",
      "name"  :  "「七窍生烟」",
      ]),
    ([
      "action": "$N奋不顾身，手中$w如狂风暴雨般向$n乱劈！这招"+HIM"「八方风雨」"NOR"虽然露出若干空门，但$n也不敢不顾自身安危而贸然进攻。\n",
      "parry_msg": "结果$n一招"+HIM"「八方风雨」"NOR"逼得$N也不敢不顾自身安危而贸然进攻。\n",
      "dodge" : 5,
      "parry" : -5,
      "damage": 40,
      "damage_type": "刺伤",
      "name"  :  "「八方风雨」",
      ]),
    ([
      "action": "$N连人带剑猛扑向$n的$l。若是这招"+HIR"「九死一生」"NOR"击不中$n，$N本人就空门大开，任人宰割了。\n",
      "parry_msg": "结果“镗”的一声，被$n连人带剑格开了。\n",
      "dodge" : 10,
      "parry" : -10,
      "damage": 45,
      "damage_type": "刺伤",
      "name"  :  "「九死一生」",
      ]),
    ([
      "action": "$N身随剑走，迅速无伦地在$n周围兜圈。$n只见周围无数人影，随时都有可能有一柄$w从意想不到的位置刺来，实在是危机重重。\n",
      "parry_msg": "结果$n身随剑走，$W从意想不到的位置将它格开了。\n",
      "dodge" :      0,
      "parry" : -15,
      "damage": 45,
      "damage_type": "刺伤",
      "name"  :  "「十面埋伏」",
      ]),
  ([ "name": "「妖雾冲天」",
     "action": MAG"$N"MAG"身化万千，手中的$w"+MAG"亦幻出千条黑影，直罩$n"MAG"全身,使$n难辨直假！$n"MAG"正手忙脚乱间，一道墨光无声无息地直取脑后玉枕穴，$n"MAG"却木然不觉！\n"NOR,
     "parry_msg": MAG"结果“镗”的一声，手中的$w"+MAG"亦幻出千条黑影将之格开了。"NOR"\n",
     "dodge": -90,
     "parry": -90,
     "damage": 120,
     "force": 250,
     "damage_type": "刺伤",
]),
});

int valid_learn(object me)
{
    	object ob;
    	if( me->query("family/family_name") != "陷空山无底洞")
   		return notify_fail("你还未习惯血腥，无法学七修剑。\n");
    	if( (int)me->query_maxforce()<100 )
		return notify_fail("你的真气不足，难以领悟剑法的精妙之处。\n");
    	if( !(ob = me->query_temp("weapon"))
          || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
    	return 1;
}

string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	int i;
	if( !me )
		return 0;
	i = me->query_temp("PERFORM_QXJ");
	if( i<=0 )
	{
		if( random(10)==0 )
			return action[random(6)];
		else if( me->query_level()<40 )
			return action[random(3)];
		else if( me->query_level()<80 )	
			return action[random(5)];
		else	return action[random(6)];
	}
	if( i<1 )
		i = 1;
	if( i>7 )
		i = 7;
	return action[i-1];	
}

varargs int practice_skill(object me,int flag)
{
	if( me->query("family/family_name") != "陷空山无底洞")
   		return notify_fail("你还未习惯血腥，无法练七修剑。\n");
    	if( (int)me->query("kee") < 30)
   		return notify_fail("你的气太低，再练下去会有危险的！\n");
    	if( (int)me->query("force") < 5)
   		return notify_fail("你的内力不够，没有办法运用七修剑。\n");
    	me->receive_damage("kee", 30);
   	me->add("force", -5);
	if(  flag )    write("你按著所学练了一遍七修剑。\n");
    	return 1;
}

string perform_action_file(string action)
{
return CLASS_D("wdd") + "/qixiu-jian/" + action;
}
