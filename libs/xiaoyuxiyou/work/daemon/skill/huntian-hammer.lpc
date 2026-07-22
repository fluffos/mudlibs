
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//【混天锤】??

/*
  dodge  15    parry  -15    damage  30
其锤法直来直去，招招为实，势大力猛，招架抵挡
甚为不易，一但碰上则伤害极大。但不足是不够轻
盈。
*/

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N一招",
        "$N双手一震，发出一招",
        "$N一提气，使出一招",
        "$N一声龙吟长啸，使出",
        "$N使出",
        "$N趁$n防御之际，一招",
});

string* skill_tail =({
        "，手中$w夹带着闷雷般的响声，劈头盖脸地就向$n砸了下来。",
        "，对$n劈头盖脸的砸了下来。",
        "，手中$w斜斜地砸向$n的$l",
        "，手中$w一阵横扫，直逼$n",
        "，直震的$n节节后退。",
        "，手中$w飘渺不定，$n顿时手忙脚乱！",
});

mapping *action = ({
   ([   
   	"action"   : "$N手中$w一转，卷着一股强劲的风力挥向$n的$l，这一下又急又猛，势大力狠，眼见就到了$n身前。\n",
   	"parry_msg": "结果$n手中$W一转，卷着一股强劲的风力将之格开。\n",
	"dodge"    : 10,
	"parry"    : -10,
	"damage"   : 50,
     "damage_type" : "砸伤",
   ]),
   ([   "action"   : "$N双手一震，手中$w夹带着闷雷般的响声，劈头盖脸地就向$n砸了过去。\n",
	"parry_msg": "结果$n双手一震，手中$W夹带着闷雷般的响声，轰的一声将其格开。\n",
	"dodge"    : 15,
	"parry"    : -15,
	"damage"   : 55,
     "damage_type" : "砸伤",
   ]),
   ([   "action"   : "$N将$w高举过肩，蓄紧力发，对准$n的$l发出雷霆一击！\n",
   	"parry_msg": "结果“轰”的一声被$n用$W格开。\n",
	"dodge"    : 20,
	"parry"    : -20,
	"damage"   : 60,
     "damage_type" : "砸伤",
   ]),
   ([   "action"   : "$N身走轻灵，手中$w忽上忽下，令人捉摸不清去路，就在$n一恍惚间，“唰”地砸向$n的$l！\n",
	"parry_msg": "结果“轰”的一声被$n用$W格开。\n",
	"dodge"    : 0,
	"parry"    : -10,
	"damage"   : 65,
     "damage_type" : "砸伤",
   ]),
   ([   "action"   : "$N趁与$n错身之机，倒转$w，锤把戳向了$n，这一下如白蛇吐芯，悄无声息的点上了$n的$l。\n",
   	"parry_msg": "结果被$n用锤把镗的一声，格开。\n",
	"dodge"    : 10,
	"parry"    : -10,
	"damage"   : 70,
     "damage_type" : "戳伤",
   ]),
   ([   "action"   : "$N紧握$w猛挥了个大圆，卷的周身长内沙土尘扬，趁$n不能辨物之记，手中$w斜斜地砸向$n的$l。\n",
   	"parry_msg": "结果$n$W卷的周身长内沙土尘扬，将$N攻击尽数逼回。\n",
	"dodge"    : 20,
	"parry"    : -25,
	"damage"   : 70,
     "damage_type" : "砸伤",
   ]),
   ([
   	"action" : "$N一声龙吟长啸,大锤直击$n右肩，此招毫无花巧,但胜在力道雄浑，相传源自盘古开天时所用的混沌一破。\n",
   	"parry_msg": "结果“轰”的一声被$n用$W格开。\n",
    	"dodge" : 10,
    	"parry"    : -50,
    	"damage" : 100,
    	"skill_name" : "混天一破",
    	"damage_type" : "砸伤"
  ]),
});

int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练混天锤。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你必须先找一柄大锤才能练混天锤。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	int i;
	if( random(20)==0 )
		return action[random(sizeof(action))];
	else
	{
		i = me->query_skill("huntian-hammer",1)/100;
		if( i<1 ) i = 1;
		if( i>7 ) i = 7;
		return action[random(i)];
	}
}

varargs int practice_skill(object me,int flag)
{
        if( (int)me->query("kee") < 50
        ||  (int)me->query("force") < 50 )
		return notify_fail("你的内力或气不够，没有办法练习混天锤。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
	if ( flag )        write("你按着所学练了一遍混天锤。\n");
        return 1;
}

string perform_action_file(string action)
{
return CLASS_D("dragon") + "/huntian-hammer/" + action;
}

