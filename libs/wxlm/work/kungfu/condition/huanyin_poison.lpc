// huanyin_poison.c


#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "huanyin_poison"; }

string chinese_name() { return "幻阴寒毒"; }

string update_msg_others()
{
       return HIG "$N" HIG "的痛苦的呻吟了一声，脸上笼"
	      "罩了一股淡淡的绿气。"NOR"\n";
}

string update_msg_self()
{
	return HIB "忽然一阵寒气自丹田的而起，逐步渗透到四"
	       "肢百赅，透出阵阵寒意。"NOR"\n";
}

int jing_damage(object me, mapping cnd)
{
	return cnd["level"] / 6;
}

int qi_damage(object me, mapping cnd)
{
	return cnd["level"] / 3;
}
