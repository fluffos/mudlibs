// xianglong-zhang.c
//Zine for 射雕主线quest，普攻有2%-4%提升
//加入筋斗限制
inherit SKILL;
#include <ansi.h>
mapping *action2 = ({
        ([      "action": HIR+"$N"+HIR+"双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向$n"+HIR+"的$l"+NOR,
         "dodge": 30,
         "parry": 30,
         "force": 520,
         "skill_name" : "亢龙有悔",
         "damage_type": "瘀伤"
         ]),
        ([      "action": "$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l",
         "dodge": 20,
         "parry": 20,
         "force": 360,
         "skill_name" : "飞龙在天",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N右掌一招「见龙在田」，迅捷无比地劈向$n的$l",
         "dodge": 10,
         "parry": 10,
         "force": 330,
         "skill_name" : "见龙在田",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N双掌施出一招「鸿渐于陆」，隐隐带着风声拍向$n的$l",
         "dodge": 20,
         "parry": 10,
         "force": 340,
         "skill_name" : "鸿渐于陆",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N左掌聚成拳状，右掌一招「潜龙勿用」缓缓推向$n的$l",
         "dodge": 10,
         "parry": 10,
         "force": 390,
         "skill_name" : "潜龙勿用",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N施出一招「利涉大川」，右掌插腰，左掌劈向$n的$l",
         "dodge": 10,
         "parry": 20,
         "force": 430,
         "skill_name" : "利涉大川",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「突如其来」，右掌从不可能的角度向$n的$l推出",
         "dodge": 50,
         "parry": 20,
         "force": 300,
         "skill_name" : "突如其来",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N大吼一声，双掌使出「震惊百里」，不顾一切般击向$n",
         "dodge": 30,
         "parry": 10,
         "force": 400,
         "skill_name" : "震惊百里",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「或跃在渊」，向$n的$l连拍数掌",
         "dodge": 20,
         "parry": 20,
         "force": 310,
         "skill_name" : "或跃在渊",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N身形滑动，双掌使一招「双龙取水」一前一后按向$n的$l",
         "dodge": 10,
         "parry": 20,
         "force": 350,
         "skill_name" : "双龙取水",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「鱼跃于渊」，身形飞起，双掌并在一起向$n的$l劈下",
         "dodge": 20,
         "parry": 30,
         "force": 450,
         "skill_name" : "鱼跃于渊",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N双掌立起，使出「时乘六龙」向$n连砍六下",
         "dodge": 20,
         "parry": 20,
         "force": 470,
         "skill_name" : "时乘六龙",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l",
         "dodge": 20,
         "parry": 20,
         "force": 420,
         "skill_name" : "密云不雨",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「损则有孚」，双掌软绵绵地拍向$n的$l",
         "dodge": 30,
         "parry": 10,
         "force": 440,
         "skill_name" : "损则有孚",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l",
         "dodge": 20,
         "parry": 40,
         "force": 420,
         "skill_name" : "龙战于野",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N门户大开，一招「履霜冰至」向$n的$l劈去",
         "dodge": 30,
         "parry": 10,
         "force": 400,
         "skill_name" : "履霜冰至",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「羝羊触蕃」，双掌由下往上击向$n的$l",
         "dodge": 20,
         "parry": 40,
         "force": 440,
         "skill_name" : "羝羊触蕃",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向$n的$l",
         "dodge": 10,
         "parry": 40,
         "force": 400,
         "skill_name" : "神龙摆尾",
         "damage_type": "瘀伤"
         ]),
});
mapping *action = ({
        ([      "action": "$N双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向$n的$l",
         "dodge": 30,
         "parry": 30,
         "force": 500,
         "skill_name" : "亢龙有悔",
         "damage_type": "瘀伤"
         ]),
        ([      "action": "$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l",
         "dodge": 15,
         "parry": 20,
         "force": 360,
         "skill_name" : "飞龙在天",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N右掌一招「见龙在田」，迅捷无比地劈向$n的$l",
         "dodge": 10,
         "parry": 10,
         "force": 320,
         "skill_name" : "见龙在田",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N双掌施出一招「鸿渐于陆」，隐隐带着风声拍向$n的$l",
         "dodge": 15,
         "parry": 10,
         "force": 340,
         "skill_name" : "鸿渐于陆",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N左掌聚成拳状，右掌一招「潜龙勿用」缓缓推向$n的$l",
         "dodge": 10,
         "parry": 10,
         "force": 380,
         "skill_name" : "潜龙勿用",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N施出一招「利涉大川」，右掌插腰，左掌劈向$n的$l",
         "dodge": 10,
         "parry": 20,
         "force": 420,
         "skill_name" : "利涉大川",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「突如其来」，右掌从不可能的角度向$n的$l推出",
         "dodge": 50,
         "parry": 10,
         "force": 300,
         "skill_name" : "突如其来",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N大吼一声，双掌使出「震惊百里」，不顾一切般击向$n",
         "dodge": 25,
         "parry": 10,
         "force": 400,
         "skill_name" : "震惊百里",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「或跃在渊」，向$n的$l连拍数掌",
         "dodge": 20,
         "parry": 20,
         "force": 310,
         "skill_name" : "或跃在渊",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N身形滑动，双掌使一招「双龙取水」一前一后按向$n的$l",
         "dodge": 10,
         "parry": 20,
         "force": 340,
         "skill_name" : "双龙取水",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「鱼跃于渊」，身形飞起，双掌并在一起向$n的$l劈下",
         "dodge": 20,
         "parry": 30,
         "force": 440,
         "skill_name" : "鱼跃于渊",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N双掌立起，使出「时乘六龙」向$n连砍六下",
         "dodge": 20,
         "parry": 20,
         "force": 460,
         "skill_name" : "时乘六龙",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l",
         "dodge": 15,
         "parry": 20,
         "force": 420,
         "skill_name" : "密云不雨",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「损则有孚」，双掌软绵绵地拍向$n的$l",
         "dodge": 25,
         "parry": 10,
         "force": 440,
         "skill_name" : "损则有孚",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l",
         "dodge": 20,
         "parry": 40,
         "force": 410,
         "skill_name" : "龙战于野",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N门户大开，一招「履霜冰至」向$n的$l劈去",
         "dodge": 25,
         "parry": 10,
         "force": 400,
         "skill_name" : "履霜冰至",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「羝羊触蕃」，双掌由下往上击向$n的$l",
         "dodge": 15,
         "parry": 40,
         "force": 440,
         "skill_name" : "羝羊触蕃",
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向$n的$l",
         "dodge": 10,
         "parry": 40,
         "force": 400,
         "skill_name" : "神龙摆尾",
         "damage_type": "瘀伤"
         ]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="shexing-shou"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练降龙十八掌必须空手。\n");
    if ((int)me->query_skill("huntian-qigong", 1) < 20)
        return notify_fail("你的混天气功火候不够，无法练降龙十八掌。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练降龙十八掌。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
	if (me->query("shediaoquest/kanglong/finish"))
	{
		return action2[random(sizeof(action2))];
	}
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 40)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 10)
        return notify_fail("你的内力不够练降龙十八掌。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -15);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"xianglong-zhang/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
        });

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
        });

string query_parry_msg(object weapon)
{
    if( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int hit_ob(object me, object ob, int damage)
{
	int dmg,rate_lv=9;

    if (me->query("neili")<=0) return 0;
//	if (me->query("player_special_contribute/gb")) rate_lv=7;
    if ( me->query("family/family_name")=="丐帮" && !me->query("chushi/done"))
		{
		if (me->query("player_special_contribute/gb")) rate_lv=4;
		}
	else
		{
		if (me->query("player_special_contribute/gb"))
			{
			if ( me->query("family/family_name")=="丐帮")
				rate_lv=6;
			else
				rate_lv=8;
			}
		}
			 //使用筋斗的，命中再次降低1个等级
  if (me->query_temp("active_buffer/shenghuo-lingfa.jindou"))
  {
	 rate_lv += 1;
  }

	//调整2个命中等级 by yhzzyahoo 2015/3/31 提升3个命中等级,纯丐帮提升5个等级
	//纯丐帮，在丐帮和不在丐帮，效果有区别
	if ( F_KUNGFU->hit_rate( me->query_str(), ob->query("str")*3, rate_lv, me, ob) )
	{
        me->add("neili",-dmg/15);
        if (me->query("neili")<0) return 0;
        dmg=me->query_skill("xianglong-zhang",1);
        dmg=dmg/2+random(dmg)/2+random((me->query("str")-20)*80);
		if ((me->query("player_special_contribute/gb")) && (!me->query("betrayer")))
		{
			if(me->query("chushi/done"))
			{
				dmg = dmg*5/4;
			}
			else
			{
				dmg = dmg*3/2;
			}
		}
		if (me->query_temp("active_buffer/shenghuo-lingfa.jindou"))
		{
			  dmg = dmg*4/5;
		}

        F_KUNGFU->hit_wound("qi", dmg, dmg/3, me, ob);
        message_vision(HIR"$N被降龙十八掌罡气一震，不由倒退几步，显是已经受了内伤！\n"NOR,ob);
        COMBAT_D->report_status(ob);
        //if(wizardp(me)) tell_object(me,sprintf("damage is %d\n", dmg));
  }
  return 0;
}
