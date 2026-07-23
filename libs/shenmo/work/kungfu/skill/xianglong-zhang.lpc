// xianglong-zhang.c 降龙十八掌
// modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;  
int sanhui(object me, object victim, object weapon, int damage);
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *parry_msg = ({
"$p不待回身，半招「神龙摆尾」，做势反劈。$P见这招势凶狠，不敢硬接，纵身避开。\n",
"只见$p左掌圆劲，右掌直推，挡在身前。一招纯是防御，却是在双方之间布了一道坚壁。\n",
"$p当下不敢怠慢，双掌当胸平推，将自己全身笼罩在掌力之下。守得稳若渊停岳峙，直无半点破绽。\n",
});

string query_parry_msg(object weapon, object victim) 
{ 
	object me = victim->select_opponent();

if (me && victim
&& victim!=me)
{
	if ( victim->query_temp("weapon") || victim->query_skill("xianglong-zhang", 1) < 100
	|| victim->query_skill_prepared("strike") != "xianglong-zhang" )
		return SKILL_D("parry")->query_parry_msg(weapon);
        else {
        string *slbw = ({
                "$n更不回身，右手一招「神龙摆尾」向后挥去，这是降龙十八掌中的救命绝招，$p在情急之下使将出来，更是威力倍增！！\n",
                "$n避让不及，不待回身，一招「神龙摆尾」，反手向$P还劈一掌！\n",
                "就在这一瞬之间，$p急忙转身，同时一招「神龙摆尾」向$P反手横劈！\n",
        });
		message_vision(YEL"\n"+slbw[random(sizeof(slbw))]+""NOR,me,victim);
		return COMBAT_D->do_attack(victim, me, me->query_temp("weapon")) + "";
                }
}
}


mapping *action = ({
([      "action": "$N突然身形加快，双掌平平推向$n的$l",
    "dodge": -30,
    "parry": 10,
    "force": 400,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N突然身形飞起，双掌居高临下一招"+(order[random(13)])+"「飞龙在天」"NOR"拍向$n的$l",     
    "dodge": -15,
    "parry": -20,
    "force": 280,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N右掌一招"+(order[random(13)])+"「见龙在田」"NOR"，迅捷无比地劈向$n的$l",
    "dodge": -10,
    "parry": -10,
    "force": 220,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N双掌施出一招"+(order[random(13)])+"「鸿渐于陆」"NOR"，隐隐带着风声拍向$n的$l",
    "dodge": -15,
    "parry": -10,
    "force": 260,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N左掌聚成拳状，右掌一招"+(order[random(13)])+"「潜龙勿用」"NOR"缓缓推向$n的$l",
    "dodge": -10,
    "parry": 10,
    "force": 200,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N施出一招"+(order[random(13)])+"「利涉大川」"NOR"，右掌插腰，左掌劈向$n的$l",
    "dodge": -10,
    "parry": 20,
    "force": 250,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「突如其来」"NOR"，右掌从不可能的角度向$n的$l推出",
    "dodge": 0,
    "parry": 10,
    "force": 100,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N大吼一声，双掌使出"+(order[random(13)])+"「震惊百里」"NOR"，不顾一切般击向$n",
    "dodge": -25,
    "parry": -10,
    "force": 300,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「或跃在渊」"NOR"，向$n的$l连拍数掌",
    "dodge": -20,
    "parry": -20,
    "force": 230,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N身形滑动，双掌使一招"+(order[random(13)])+"「双龙取水」"NOR"一前一后按向$n的$l",
    "dodge": -10,
    "parry": 20,
    "force": 160,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「鱼跃于渊」"NOR"，身形飞起，双掌并在一起向$n的$l劈下",     
    "dodge": -20,
    "parry": 30,
    "force": 250,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N双掌立起，使出"+(order[random(13)])+"「时乘六龙」"NOR"向$n连砍六下",
    "dodge": -20,
    "parry": 20,
    "force": 270,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「密云不雨」"NOR"，左掌封住$n的退路，右掌斜斜地劈向$l",     
    "dodge": -15,
    "parry": 20,
    "force": 220,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「损则有孚」"NOR"，双掌软绵绵地拍向$n的$l",
    "dodge": -25,
    "parry": 10,
    "force": 350,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N脚下一转，突然欺到$n身前，一招"+(order[random(13)])+"「龙战于野」"NOR"拍向$n的$l",     
    "dodge": -20,
    "parry": 40,
    "force": 330,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N门户大开，一招"+(order[random(13)])+"「履霜冰至」"NOR"向$n的$l劈去",
    "dodge": -25,
    "parry": 1,
    "force": 320,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「羝羊触蕃」"NOR"，双掌由下往上击向$n的$l",
    "dodge": -15,
    "parry": 40,
    "force": 200,
        "damage": 300,
    "damage_type": "瘀伤"
]),
([      "action": "$N左掌护胸，右掌使一招"+(order[random(13)])+"「神龙摆尾」"NOR"上下晃动着击向$n",     
    "dodge": -10,
    "parry": 40,
    "force": 220,
        "damage": 350,
    "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="strike" ||  usage=="parry"; }  

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练降龙十八掌必须空手。\n");
if ((int)me->query_skill("huntian-qigong",1) < 80)
                return notify_fail("你的混天气功修为不够。\n");
       if (((int)me->query_skill("liuhe-zhang", 1)) < 80)
               return notify_fail("你的六合掌法太低了。\n");
       if (((int)me->query_skill("fengmo-zhang", 1)) < 80)
               return notify_fail("你的疯魔杖法太低了。\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)) < 80)
               return notify_fail("你的逍遥游太低了。\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("你的内力太弱，无法练降龙十八掌。\n");
    return 1;
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 70)
   return notify_fail("你的体力太低了。\n");
if ((int)me->query_skill("huntian-qigong",1) < 80)
                return notify_fail("你的混天气功修为不够。\n");
       if (((int)me->query_skill("liuhe-zhang", 1)) < 80)
               return notify_fail("你的六合掌法太低了。\n");
       if (((int)me->query_skill("fengmo-zhang", 1)) < 80)
               return notify_fail("你的疯魔杖法太低了。\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)) < 80)
               return notify_fail("你的逍遥游太低了。\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("你的内力不够练降龙十八掌。\n");
    me->receive_damage("qi", 50);
    me->add("neili", -15);
    return 1;
}
mapping query_action(object me, object weapon)
{
	int x = 1 + random(8);
	int y = 3 + random(10);
	string *sanhui_msg = 
	({
		HIW"$N大步迈出，左手一划，右掌呼的一声，便向$n击去，正是一招「亢龙有悔」，力自掌生，猛不可当"NOR,
		HIM"$N一掌既出，身子抢前，又是一招「亢龙有悔」，後掌推前掌，双掌力道并在一起，排山倒海的压将过来"NOR,
		HIG"$N跟着又是一招「亢龙有悔」，前招掌力相消，次招掌力又至。竟如怒涛狂涌，势不可挡，又如一堵无形的高墙，向$n身前疾冲"NOR,
	});

	if ( me->query_skill_mapped("force") == "huntian-qigong" )
	{
//             if ( me->query_skill("xianglong-zhang") > 280 && random(me->query_skill("force")) > 200 && me->query("neili") > 1000  )
             if ( random(me->query_skill("xianglong-zhang")) > 280 && random(me->query_skill("force")) > 200 && me->query("neili") > 1000  )
		{
			return ([
			"action": sanhui_msg[random(3)],
			"dodge": 20,
			"parry": 25,
			"force": 650,
			"damage": 520+random(600),
			"damage_type": random(2)?"内伤":"瘀伤" ]);
		}
		else if ( random(me->query_skill("xianglong-zhang")) > 230 && random(me->query_skill("force")) > 200 && me->query("neili") > 1000  )
		{
			me->add("neili", -50);
			return ([
			"action": HIY"$N一招「亢龙有悔」，平推出去。初推出去看似轻描淡写，但一遇阻力，刹时之间连加"+ chinese_number(y) +"道後劲，一道强似一道，重重叠叠，直至无坚不摧，无强不破"NOR,
			"dodge": 20+random(20),
			"parry": 25+random(20),
			"force": 650+random(350),
			"damage": 520+random(400),
			"damage_type": random(2)?"内伤":"瘀伤" ]);
		}
		else if ( random(me->query_skill("xianglong-zhang")) > 200 && random(me->query_skill("force")) > 150 && me->query("neili") > 500)
		{
			me->add("neili", -30);
			return ([
			"action": YEL"$N踏上两步，呼的一声，一招「亢龙有悔」当胸击去。这一掌"+ chinese_number(x) +"分发，"+ chinese_number(10-x) +"分收，劲道去而复回，实是非同小可"NOR,
			"dodge": 20+random(100),
			"parry": 25+random(100),
			"force": 600+random(350),
			"damage": 520+random(300),
			"damage_type": random(2)?"内伤":"瘀伤" ]);
		}
    else    if (random(me->query_skill("xianglong-zhang",1)) > 250 &&		 me->query_skill("huntian-qigong",1) > 200 &&
        me->query("neili") > 200)
{
	me->add("neili", -50);
        return ([
	"action": HIY"$N左腿微屈，右臂内弯，右掌划了个圆圈，呼的一声向外急推，凌厉无比，正是威力最强的"+(order[random(13)])+"「亢龙有悔」"NOR""NOR,
	"dodge": 80,
        "parry": 330,
        "damage": 600,
        "force": 600,
        "damage_type": "瘀伤"]);
}
else	if (random(me->query_skill("xianglong-zhang",1)) > 200 &&		me->query_skill("huntian-qigong",1) > 100 &&
        me->query("neili") > 200)
{
	me->add("neili", -30);
        return ([
	"action": HIC"$N眼见$n招数凶猛。避让不及，急忙转身，同时反手猛劈，正是降龙掌的救命绝招"+(order[random(13)])+"「神龙摆尾」"NOR""NOR,
	"parry": 60,
        "dodge": 80,
        "damage": 600,
        "force": 600,
        "damage_type": "瘀伤"]);
}
	}

	return action[random(sizeof(action))];
}

int ob_hit(object ob, object me, int damage)
{
   int i, neili;
if (me->query_skill_mapped("force") != "huntian-qigong")
return damage;
if (ob && me &&
me!=ob)
{
   if(living(me) &&
      random(me->query("combat_exp")) > ob->query("combat_exp")/3 && 
      me->query_skill("xianglong-zhang", 1) >= 180 
      &&  !me->is_busy()
      &&      me->query("neili") > 600 &&
      me->query("qi") < me->query("max_qi")
      )
      {
        i = me->query("jiali");
        neili = me->query("neili");
        me->set("jiali", me->query_skill("force")*2);
        me->add_temp("apply/attack", 80);
        message_vision(HIC "但见$N硬接了$n这一招，右掌紧接着向后一摆，一招「神龙摆尾」出其不意地按在了$n的$l上！\n" NOR, me, ob );
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        if(me->query("neili") < neili) me->set("neili", neili-50);
        me->set("jiali", i);
        me->add_temp("apply/attack", -80);
      }
      return 1;
}
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("xianglong-zhang", 1);

        if (damage_bonus < 150 || lvl < 150) return 0;
if (me->query_skill_mapped("force") != "huntian-qigong")
return 0;
        if (random(4)==0)
        {
                victim->receive_wound("qi", (damage_bonus - 50) , me);

                return random(2) ? HIR "只听$n" HIR "前胸「咔嚓」一声脆响，竟像是"
                                   "肋骨断折的声音。\n" NOR:

                                   HIR "$n" HIR "一声惨叫，胸前「咔嚓咔嚓」几声脆"
                                   "响，口中鲜血狂喷。\n" NOR;
        }
}
string perform_action_file(string action)
{
    return __DIR__"xianglong-zhang/" + action;
}

