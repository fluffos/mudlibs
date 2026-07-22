//【轮回杖】lunhui-zhang.c
inherit SKILL;
#include <ansi.h>;

mapping *action = ({
        ([      "name"  : "报应不爽",
                "action": "$N口宣佛号，面色庄严，一招"+HIR"「报应不爽」"NOR"手中$w长驱直入，迳刺$n$l。\n",
                "parry_msg": "结果$n口宣佛号，面色庄严，$W长驱直入，将之格开。\n",
                "dodge" : 20,
     		"parry" : -10,
                "damage": 100,
                "damage_type":  "刺伤"
        ]),
        ([      "name"  : "大限将至",
                "action": "$N手中$w一荡，使出"+HIB"「大限将至」"NOR"，但见一道杖影隐隐约约，若有若无地向$n压下。\n",
                "parry_msg": "结果只见$n手中$W杖影隐隐约约，“镗”的一声将之格开。\n",
                "dodge" : 15,
     		"parry" : -15,
                "damage": 110,
                "damage_type":  "砸伤"
        ]),
        ([      "name"  : "回头是岸",
                "action": "只见$N手中$w疾横，斗地点出！这招"+HIM"「回头是岸」"NOR"轻灵飘逸，$n眼见杖风袭来，竟不知如何是好。\n",
                "parry_msg": "结果只见$n手中$W疾横，一招"+HIM"「回头是岸」"NOR"将之挡开。\n",
                "dodge" : 20,
     		"parry" : -20,
                "damage": 120,
                "damage_type":  "刺伤"
        ]),
        ([      "name"  : "在劫难逃",
                "action": "$N大喝一声，手中$w向$n兜头击落，兵器未至，已将$n各处退路封死，好一招"+HIC"「在劫难逃」"NOR"。\n",
                "parry_msg": "结果$n大喝一声，手中$W已将$N各处攻势封死，好一招"+HIC"「在劫难逃」"NOR"。\n",
                "dodge" : 15,
     		"parry" : -10,
                "damage": 130,
                "damage_type":  "砸伤"
        ]),   
        ([      "name"  : "天网恢恢",
                "action": "$N倒提$w，轻轻一纵，一招"+HIW"「天网恢恢」"NOR"从$n意想不到的地方刺出，$n顿时手足无措，狼狈万分。\n",
                "parry_msg": "结果$n一招"+HIW"「天网恢恢」"NOR"逼得$N顿时手足无措，狼狈万分。\n",
                "dodge" : 10,
     		"parry" : -15,
                "damage": 145,
                "damage_type":  "刺伤"
        ]),   
        ([      "name"  : "再堕轮回",
                "action": "$N脸上突现煞气，举起手中$w，猛向$n$l击落，这招"+RED"「再堕轮回」"NOR"出手又快又狠！\n",
                "parry_msg": "结果$n脸上突现煞气，$W猛的架回这招，一式"+RED"「再堕轮回」"NOR"出手又快又狠！\n",
                "dodge" : 20,
     		"parry" : -15,
                "damage": 100,
                "damage_type":  "砸伤"
        ]), 
        ([      "name":   "渡劫",
    		"action" : HIW"$N"HIW"默吟佛号，手中的$w"+HIW"带一层淡淡的白雾直直拍向$n"+HIW"的胸前！这第一招名唤「渡劫」！"NOR,
    		"dodge" :  -15,
    		"damage" : 100,
    		"force"  : 50,
    		"parry"  : -30,
    		"damage_type" : "砸伤"
	]),
	([      "name":   "渡难",
    		"action" : HIW"$N"HIW"手中$w"+HIW"一振，白色劲气已然布满全身，风雷之声渐起，这第二式「渡难」猛然拍出！"NOR,
    		"dodge" : -20,
    		"damage" : 150,
    		"parry"  : -40,
    		"force"  : 60,
		"damage_type" : "砸伤"
	]),
	([      "name":   "渡厄",
    		"action" : HIW"$N"HIW"梵唱又起，$w"+HIW"象鼓满了风的劲帆，汹涌而出！「渡厄」一式之凶险显见佛家动嗔也会做“狮子吼”！"NOR,
    		"dodge" : -25,
    		"damage" : 160,
    		"parry"  :-50,
    		"force"  : 70,
    		"damage_type" : "砸伤"
	]),
	([      "name":   "慈光普渡",
    		"action" : HIC"$N"HIC"轻声禅唱“回头是岸”，周身七尺劲气涌动，这普陀佛门禅功的无上功力终化作「慈光普渡」澎湃而出！"NOR,
    		"dodge" : -30,
    		"damage" : 180,
    		"parry"  : -60,
    		"force"  : 80,
		"damage_type" : "砸伤"
	]),  
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query_maxforce()<100 )
                return notify_fail("你的内力不够，没有办法学轮回杖，等内力提高了再来吧。\n");
	if( !(ob = me->query_temp("weapon"))
         || (string)ob->query("skill_type") != "staff" )
		return notify_fail("你必须先找一条禅杖才能学轮回杖。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
	int i;
	if( !intp(i= me->query_temp("PERFORM_sandu"))
	 || i<1 )
	{
		i = (me->query_skill("lunhui-zhang",1)-100)/100+1;
		if( i>6 )
			i = 6;
		return action[random(i)];	
	}
	else
	{
		if( i>10 ) i = 10;
		return action[i-1];
	}	 
}

string query_parry_msg(object me,object target)
{
	mapping act;
	if( !me || !target )
		return 0;
	if( !me->query_temp("weapon") )
		return 0;
	act = query_action(me,me->query_temp("weapon"));
	return act["parry_msg"];
}

varargs int practice_skill(object me,int flag)
{
        if( (int)me->query("kee") < 20
        ||  (int)me->query("force") < 30 )
                return notify_fail("你的内力或气不够，没有办法练习轮回杖。\n");
        me->receive_damage("kee", 20);
        me->add("force", -5);
	if ( flag )        write("你按着所学练了一遍轮回杖。\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("putuo") + "/lunhui-zhang/" + func;
}

