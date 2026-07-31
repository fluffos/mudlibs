// Shenlong.c 神龙九式
// Cracked by 凌惊雪 5-20-2003

inherit SKILL;

mapping *action = ({
([      "action" : "$N身形一长，朝$n劈面就是一掌。这招「苍龙出海」势若奔雷，锐利无比",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"瘀伤",
        "weapon":               "左掌",
]),
//1
([      "action" : "$N身形一长，朝$n劈面就是一掌。这招「苍龙出海」势若奔雷，锐利无比",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"瘀伤",
        "weapon":               "左掌",
]),
//2
([      "action" : "$N身形向前移动，双掌分使两式「双龙取水」，凌厉的掌风一左一右同时压向$n$l",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"瘀伤",
        "weapon":               "双掌",
]),
//3
([      "action" : "$N左腿微屈，右臂内弯，右掌划了个圆圈，呼的一声，向外推去，正是一招「亢龙有悔」",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"瘀伤",
        "weapon":               "右掌",
]),
//4
([      "action" : "$N突然飞起半空，身形旋转，双掌居高临下一招「飞龙在天」直向身下的$n压去",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"瘀伤",
        "weapon":               "双掌",
]),
//5
([      "action" : "$N一招未完，一招又起，左掌回收，右掌向右一招「见龙在田」，迅捷无比地劈向$n的$l",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"瘀伤",
        "weapon":               "右掌",
]),
//6
([      "action" : "只见$N一旋身，双腿如铁棍一般扫向$n。这一招「神龙摆尾」当真是防不胜防",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"砸伤",
        "weapon":               "双腿",
]),
//7
([      "action" : "$N似退反进，突然欺身向前，五指如钩，一招「潜龙勿用」，对准$n的$l一把抓了过去",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"抓伤",
        "weapon":               "右手五指",
]),
//8
([      "action" : "$N忽发龙吟，使出一招「龙战于野」，啸声中和身而上，向$n直撞而来",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"撞伤",
        "weapon":               "全身",
]),
//9
([      "action" : "$N纵身向前，一招「云龙九现」往$n连劈九掌，每一掌都狂风呼啸，飞沙走石",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"劈伤",
        "weapon":               "掌风",
]),
});

int valid_enable(string usage) 
	{ 
		return (usage == "unarmed") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if (me->query("chushi/chushi_longgong") != "yes" )
                return notify_fail("你没有领悟「神龙九式」的窍门。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「神龙九式」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-shenlong");
	if( !me->query_temp("pfm-shenlong") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if (me->query("chushi/chushi_longgong") != "yes" )
                return notify_fail("你没有领悟「神龙九式」的窍门。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「神龙九式」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「神龙九式」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("chushi") + "/shenlong/" + func;
}
