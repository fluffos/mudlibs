// panyun-shou.c 排云推手

#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

mapping *action = ({
([	"action" : "$N跨开马步，右掌前出，十指伸缩，虚虚实实地袭向$n的全身要穴",
	"force" : 30,
        "dodge" : 1,
        "parry" : 4,
	"damage": 110,
	"lvl" : 0,
        "damage_type" : "抓伤"
]),
([	"action" : "$N退后一步，双掌一起排出，如钩如戢，插向$n的$l",
	"force" : 40,
	"dodge" : 15,
        "parry" : 5,
	"damage": 110,
	"lvl"   : 15,
	"damage_type" : "刺伤"
]),
([	"action" : "$N忽的一转身，两手环扣，拢成圈状，猛击$n的下颌",
	"force" : 60,
        "dodge" : 18,
        "parry" : 7,
	"damage": 10,
	"lvl" : 30,
        "damage_type" : "内伤"
]),
([	"action" : "$N双手平伸，十指微微上下抖动，戳向$n的$l",
	"force" : 80,
	"dodge" : 25,
        "parry" : 11,
	"damage": 112,
	"lvl"   : 40,
	"damage_type" : "内伤"
]),
([	"action" : "$N左手护胸，腋下含空，右手五指如钩，打向$n的要穴",
	"force" : 100,
	"dodge" : 30,
        "parry" : 14,
	"damage": 15,
	"lvl"   : 50,
	"damage_type" : "内伤"
]),
([	"action" : "$N右腿斜上，上手取目，下手反勾$n的裆部",
	"force" : 115,
	"dodge" : 35,
        "parry" : 17,
	"damage": 119,
	"lvl"   : 60,
	"damage_type" : "内伤"
]),
([	"action" : "$N一手虚指$n的剑诀，劈空抓向$n手中的兵刃",
	"force" : 130,
	"dodge" : 32,
        "parry" : 13,
	"damage": 121,
	"lvl"   : 70,
	"damage_type" : "抓伤"
]),
([	"action" : "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，两面夹击$n",
	"force" : 150,
	"dodge" : 38,
        "parry" : 18,
	"damage": 124,
	"lvl"   : 80,
	"damage_type" : "内伤"
]),
([	"action" : "$N一手撑天，一手指地，劲气笼罩$n的全身",
	"force" : 170,
	"dodge" : 42,
        "parry" : 12,
	"damage": 127,
	"lvl"   : 90,
	"damage_type" : "内伤"
]),
([	"action" : "$N拳掌招若隐若现，若有若无，缓缓地拍向$n的丹田",
	"force" : 190,
        "dodge" : 50,
        "parry" : 15,
	"damage": 130,
	"lvl" : 100,
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }

int valid_combine(string combo)
{
        return  combo == "yitian-zhang";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练排云推手必须空手。\n");

	if ((int)me->query_skill("force") < 40)
		return notify_fail("你的内功火候不够，无法学排云推手。\n");

	if ((int)me->query("max_neili") < 250)
		return notify_fail("你的内力太弱，无法练排云推手。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("paiyun-shou",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练排云推手。\n");
        if ((int)me->query_skill("taiji-quan", 1) < 30)
                return notify_fail("你的「太极拳」火候太浅。\n");

        if ((int)me->query_skill("wudang-mianzhang", 1) < 30)
                return notify_fail("你的武当绵掌火候太浅。\n");
	me->receive_damage("qi", 37);
	me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"paiyun-shou/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg;
    int j,damage;
    j = me->query_skill("paiyun-shou", 1);
   
    if( damage_bonus < 100 ) return 0;
    if(random(3) == 0 && !victim->is_busy() && j > 120 &&
       me->query("neili") > victim->query("neili") &&
        me->query_skill("taiji-shengong", 1) > 150 &&
       me->query_skill_mapped("force") == "taiji-shengong" 
        &&       me->query_skill_mapped("parry") == "paiyun-shou" 
       &&       me->query("neili") > 600 && me->query("max_neili") > 1200 &&
        j > random(victim->query_skill("dodge",1))){
        switch(random(4)){
            case 0 :
               msg = HIC "$N" HIC "面含微笑，双手齐出，向前一推划出了"
                                            "一个圆圈，向竟然让$n" +
                                            HIC "连退数步。\n" NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5+20);
                me->add("neili", -damage/10);
               break;
             case 1 :
               msg = HIC "$N" HIC "左右格档，使出四两拨千斤的手法，一记推手"
                                            "将$n" HIC "退到在地。\n" NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5+20);
                me->add("neili", -damage/10);
                break;
            case 2 :
               msg = HIY "$N" HIY "慢慢出拳"
                                 HIY "，动作缓慢却让$n"
                                 HIY "感到粘滞，紧接着$N"
                                 HIY "出奇招快速进击$n全身!"
                                 HIY "！\n" NOR;
                damage = damage_bonus/4 + random(damage_bonus)/5;
                                if ((int)victim->query("jing")<=damage+10) 
                                 { victim->set("jing",10); }
                                 else {
                 victim->receive_damage("jing", damage); 
                                 }
           if (!victim->is_busy())
{
                victim->start_busy(2);  
}
                me->add("neili", -20);     
               break;
            case 3 :
               msg = HIY "$N" HIY "面含微笑，双手齐出，划出了"
                                 "一个圆圈，然后$N" +
                                 HIY "随手一退挥招直入，进袭$n"
                                 HIY "！\n" NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
                if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5);
                me->add("neili", -damage/10);
               break;
            }
        switch(random(4)){
         case 0 : msg += HIR"结果$n身不由主的向前一冲，跨出几步，方始站定。\n"NOR; break;
         case 1 : msg += HIR"结果$n身不由主的在原地急转了七八下，如转陀螺，如旋纺锤！\n"NOR; break;
         case 2 : msg += HIR"登时便套得$n跌跌撞撞，身不由主的立足不稳，犹如中酒昏迷。\n"NOR; break;
         case 3 : msg += HIR"$n想使出千斤坠之力定住身形，却已满脸胀得通红，身不由己，狼狈万状。\n"NOR; break;
         }
        message_vision(msg, me, victim);
        }
}