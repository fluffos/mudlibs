// linghu-baodian.c 身外化身
// by Doing Lu

inherit SKILL;

#include <ansi.h>

#define LEVEL_PER_LAYER	 30
#define MAX_LAYER	       12

string type() { return "special"; }

int valid_learn(object me)
{
	int layer;
	int lvl;

	lvl = me->query_skill("linghu-baodian", 1);
	if (me->query("gender") == "无性" && lvl >= 50)
		return notify_fail("你默默凝神，试图分心二"
				   "用，可是却觉得阴阳失调，心浮气躁。\n");

	if (lvl >= MAX_LAYER * LEVEL_PER_LAYER)
		return notify_fail("你的三分神功已经修炼"
				   "的炉火纯青，再难进步了。\n");

	layer = lvl / LEVEL_PER_LAYER;
	if (layer > MAX_LAYER) layer = MAX_LAYER;

	if (me->query("int") > 2800000000000000 && !me->query("relife/zhuanshi"))
		return notify_fail("你觉得心烦意乱，难以尝"
				   "试更高深的分心之术。\n");

	return 1;
}
int valid_research(object me)
{
	return notify_fail("三分神功只能通过学习不断提高。\n");
}

int practice_skill(object me)
{
	return notify_fail("三分神功只能通过学习不断提高。\n");
}

void skill_improved(object me)
{
	int lvl;
	int layer;

	lvl = me->query_skill("linghu-baodian", 1);
	layer = lvl / LEVEL_PER_LAYER;
			if(lvl>=99 && lvl <100)
   		                CHANNEL_D->do_channel(find_object(ITEM_D), "rumor",
                              "听说" + me->name() + HIM +
                              "将"HIY"三分神功"HIM"修炼到了第十层。");			
	if (layer > MAX_LAYER) layer = MAX_LAYER;

	if (! layer)
	{
		tell_object(me, HIM "你潜心领悟身外化"
				"身，若有所悟。"NOR"\n");
	} else
	if ((lvl % LEVEL_PER_LAYER) == 0)
	{
		tell_object(me, HIM "你领悟了第" + chinese_number(layer) +
			    "层境界的身外化身的奥妙。"NOR"\n");
	} else
		tell_object(me, HIM "你对第" + chinese_number(layer) +
			    "层境界的身外化身又加深了一点了解。"NOR"\n");
		

}
