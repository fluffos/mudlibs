#include <ansi.h>
#include <title.h>
inherit __DIR__"song_officer";
void create()
{
	call_out("npc_to_player",1,"太常寺少卿",40,-1);
	::create();
}

void init()
{
	add_action("do_ling","ling");
}

int do_ling()
{
	int salary,period;
	object me=this_player();
	if (me->query("song/xunjue/rank")<1||me->query("song/xunjue/rank")>12)
	return notify_fail("你尚未被封爵，没有食邑俸禄可领。\n");
	if (!me->get_title(TITLE_SONG5))
	return notify_fail("你尚未被封爵，没有食邑俸禄可领。\n");
	period=me->query("mud_age")-me->query("song/salary_jue");
	if (period<10000)
	return notify_fail("你封爵时间尚短或距离上次领取食邑俸禄太近，暂时没有新的食邑俸禄。\n");
	me->set("song/salary_jue",me->query("mud_age"));
	salary=DASONG_D->salary(me,period);
	MONEY_D->pay_player(me, salary);
	DASONG_D->multi_record(me,salary,"食邑",1);
	CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s领大宋食邑俸禄：%s。", me->name(),MONEY_D->money_str(salary)));
	tell_object(me,BOLD+HBCYN+HIY+"你领取了"+me->get_title(TITLE_SONG5)+"的食邑共计"+MONEY_D->money_str(salary)+"。\n"+NOR);
	return 1;
}
