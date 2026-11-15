// huagu.c


#include <condition.h>

inherit F_CLEAN_UP;
inherit "/inherit/condition/damo";

string name() { return "damo_zheyuan"; }

string chinese_name() { return "折元之扰"; }

string update_msg_others()
{
       return HIC "$N" HIC "脸色忽然大变，黄豆般大的汗珠顺着脸庞涔涔而下！"NOR"\n";
}

string update_msg_self()
{
	return HIR "忽然发现自己丹田一阵火起，忽然又变得冰凉，一定是受到达摩折元剑的干扰。"NOR"\n";
}

int neili_damage(object me, mapping cnd)
{
	int d;

	d = cnd["level"];

	if (d > 300 )
		d = 100 + (d - 300) / 12;
	else
	if (d > 60)
		d = 60 + (d - 60 ) / 6;
	d *= 3;
	if (d < 10) d = 10;

	return d / 2 + random(d);
}
