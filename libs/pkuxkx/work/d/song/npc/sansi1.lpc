#include <ansi.h>
#include <title.h>
inherit __DIR__"song_officer";
void create()
{
	call_out("npc_to_player",1,"三司户部副使",50,-1);
	::create();
}

void init()
{
	add_action("do_ling","ling");
}
float xufeng_salary(string title)
{
	string *ranks=({"节度使","节度留后","观察使","团练使","防御使","刺使","团练副使","防御副使"});
	float *weights=({1.9,1.65,1.6,1.45,1.45,1.35,1.2,1.2});
	if (title)
	{
		for (int i=0;i<sizeof(ranks);i++)
		{
			if (strsrch(title,ranks[i])!=-1)
			return weights[i];
		}
	}
	return 1.0;
}
int do_ling()
{
	int salary;
	float period,xufeng=1.0;
	object me=this_player();
	if (!DASONG_D->get_my_pin(me)||!me->query("song/pro"))
	return 0;
	if (me->query("song/pro")=="宦")
	{
		command("say 内侍的职贴由内东门司发放。");
		return 1;
	}
	if (!me->get_title(TITLE_SONG1))
	{
		command("say 你现在并无担当任何实际差遣，所以只有本俸可领。");
		return 1;
	}
	if (me->query("song/credit")<=me->query("song/last_zhi_credit"))
	{
		command("say 你都没怎么为朝廷做事，还想什么职贴？");
		return 1;
	}
	if (!me->query("song/zhi_salary"))
	{
		command("say 你的职贴现在计算不清，你去找Zine解决吧。");
		return 1;
	}
	if (me->query("mud_age")-me->query("song/salary_zhi")<10000)
	{
		command("say 你才领过职贴不久，多段时间再来吧。");
		return 1;
	}
	period=to_float(me->query("mud_age")-me->query("song/salary_zhi"))/86400.0;
	salary=to_int(to_float(me->query("song/zhi_salary"))*period*5000.0);
	xufeng=xufeng_salary(COLOR_D->uncolor(me->get_title(TITLE_SONG3)));
	salary=to_int(xufeng*to_float(salary));
	me->set("song/salary_zhi",me->query("mud_age"));
	me->set("song/last_zhi_credit",me->query("song/credit"));
	MONEY_D->pay_player(me, salary);
	DASONG_D->salary_record(me,salary,"职贴");
	CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s领大宋职贴：%s。", me->name(),MONEY_D->money_str(salary)));
	if (me->get_title(TITLE_SONG1))
	tell_object(me,BOLD+HBCYN+HIY+"你领取了"+me->get_title(TITLE_SONG1)+BOLD+HBCYN+HIY+"的职贴钱共计"+MONEY_D->money_str(salary)+"。\n"+NOR);
	else
	tell_object(me,BOLD+HBCYN+HIY+"你领取了职贴钱共计"+MONEY_D->money_str(salary)+"。\n"+NOR);
	if (xufeng>1.0)
	tell_object(me,BOLD+HBCYN+HIY+"根据"+me->get_title(TITLE_SONG3)+BOLD+HBCYN+HIY+"的虚封，你的职贴钱被以"+xufeng+"倍发放。\n"+NOR);
	return 1;
}