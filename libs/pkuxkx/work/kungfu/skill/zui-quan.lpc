//醉拳
//by mudy/male
// Modified by iszt@pkuxkx, 2007-03-12

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":  HIB"$N"HIB"一招「醉八仙」，身形忽快忽慢，双眼微闭，双拳如游龙戏珠，直取$n"HIB"的双眼"NOR,
	"dodge": 50,
	"parry": 10,
//	"force": 50,
	"damage_type": "瘀伤"
]),
([      "action": HIG"$N"HIG"在打斗之间竟突然做摔倒状，双腿却似剪刀一般，连环向$n"HIG"踢出数腿"NOR,
	"dodge": 80,
	"parry": 0,
//	"force": 150,
	"damage_type": "瘀伤"
]),
([      "action": HIY"$N"HIY"突然身体前倾，摇摇欲坠，却是一招「武松跌醉」，靠在$n"HIY"身后，一手「洒瓶指」直取$n"HIY"的太阳穴"NOR,
	"dodge": 100,
	"parry": 10,
//	"force": 100,
	"damage_type": "瘀伤"
]),
([      "action": HIR"$N"HIR"乘$n"HIR"袭来之际，竟然就地一倒，连滚带爬一般从$n"HIR"的掌风之下绕到左侧，\n看也不看便用自己的肩部向$n"HIR"撞去"NOR,
	"dodge": 120,
	"parry": 10,
//	"force": 110,
	"damage_type": "瘀伤"
]),
([      "action": HIM"$N"HIM"一招「逆转乾坤」，双手伏地，身体倒立起来，双腿却是以迅雷不及掩耳之势向$n"HIM"面部袭来"NOR,
	"dodge": 150,
	"parry": 10,
//	"force": 150,
	"damage_type": "瘀伤"
]),
([      "action": HIW"$N"HIW"突然一声暴喝,身体跃起丈余！一招"HIR"「醉龙出水」"+HIW"，\n身体成龙形，集全身力量于掌心，向$n"HIW"呼啸而来"NOR,
	"dodge": 180,
	"parry": 100,
//	"force": 200,
	"damage_type": "瘀伤"
]),
});

string *dodge_msg = ({
		HIG"只见$n"HIG"一招「就地十八滚」，身体就势一躺，躲过了$N"HIG"这一招。\n"NOR,
		BLU"只见$n"BLU"一招「就势顺势」，身体不退反进，使用醉拳的缠字诀缠住$N"BLU"，\n让$N"BLU"的进攻无法得逞。\n"NOR,
		  HIW"$n"HIW"双手粘住$N"HIW"双手，一转身用背部对敌。$N"HIW"大骇，不得不停止攻击。\n"NOR,
		  YEL"$n"YEL"突然鬼魅般的一笑，往后一栽，看似随便一倒，却是快如闪电，轻而易举躲开了这一招。\n"NOR,
                  WHT"$n"WHT"突然好似浑身无力，$N"NOR+WHT"打在$n"NOR+WHT"身上感到$n"NOR+WHT"身上软绵绵的将自己的攻势早已化得无影无踪。\n"NOR,
		   HIM"但是$n"HIM"身形飘忽，轻轻一纵，早已避开。\n"NOR,
		   HIY"却见$n"HIY"足不点地，往后一仰，躲了开去。\n"NOR,
		   CYN"却见$n"CYN"身形左右摇晃，让$N"NOR+CYN"无法击中。\n"NOR,
});
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry" || usage=="dodge"||usage=="move"; }

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;
      me=this_player();
	zhaoshu = sizeof(action);
/*
      level=(int)me->query_skill("zui-quan");
       if (level < 800 )
//	if (me->query("zuiquan"))
		zhaoshu--;
*/
	return action[random(zhaoshu)];
}


int valid_learn(object me)
{
		return notify_fail("醉拳只能靠自己领悟!\n");
}

string perform_action_file(string action)
{
	return __DIR__"zui-quan/" + action;
}

string *parry_msg = ({
	"$n掌风一变,只听见「锵」一声，$N被$p格开了。\n",
	"$n身子一侧，用手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
	"但是被$p格开了。\n",
	"结果被$p挡开了。\n",
});

int practice_skill(object me)
{
	return notify_fail("醉拳只能靠喝万年醉来领悟增加熟练度。\n");
}


string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
