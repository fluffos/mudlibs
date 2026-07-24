// shenxing-baibian.c 神行百變

inherit SKILL;

mapping *action = ({
([	"action" : "$n一式「行云流水」，身不傾，腳不移，身體如行云流水般直滑出丈余。\n",
	"dodge"  : 10
]),
([	"action" : "$n一式「潛音夜行」，忽然一彎腰，全身貼地而行，頓時閃過了$N的凌厲攻勢。\n",
	"dodge"  : 20
]),
([	"action" : "$n一式「移步換形」，足不動，手不抬，一轉眼間便繞到了$N的身后。\n",
	"dodge"  : 30
]),
([	"action" : "$n一式「分身化影」，一轉身間，四面八方飄動著無數個$n的身影，令$N手足無措。\n",
	"dodge"  : 40
]),	
([	"action" : "$n一式「凌波微步」，左踏巽，右轉乾，身行一晃，便到几丈遠的地方。\n",
	"dodge"  : 50
]),
([	"action" : "$n一式「更上層樓」，身在空中，左腳在右足上一點，從$N頭頂騰空而過。\n",
	"dodge"  : 60
]),
([	"action" : "$n一式「仙子出水」，長袖一拂，全身化為一道白影，幽幽地從$N頭頂飄落。\n",
	"dodge"  : 70
]),
([	"action" : "$n一式「峰回路轉」，身體如陀螺般急轉，登時一股氣流涌出，令$N難以動彈。\n",
	"dodge"  : 80
]),
([	"action" : "$n一式「臨行秋波」，身行倏的從$N的眼前直繞到身后，$N瞪大了兩眼，不明所以。\n",
	"dodge"  : 90
]),
([	"action" : "$n一式「浪子回頭」，身行倏的從$N的眼前飄過，長發一甩，瀟洒之極。\n",
	"dodge"  : 100
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shenxing-baibian",1);


	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的體力太差了，不能練神行百變。\n");
	me->receive_damage("qi", 20);
	return 1;
}
