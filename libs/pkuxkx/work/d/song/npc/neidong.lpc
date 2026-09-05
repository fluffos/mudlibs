#include <ansi.h>
#include <title.h>
inherit __DIR__"song_officer";
#include "/d/song/tasks/neidongmen.h"
void create()
{
	call_out("npc_to_player",1,"勾管内东门司",40,-1);
	::create();
}

void init()
{
	add_action("do_ling","ling");
}

int do_ling()
{
	int salary;
	float period;
	object me=this_player();
	if (!DASONG_D->get_my_pin(me)||!me->query("song/pro"))
	return 0;
	if (me->query("song/pro")!="宦")
	{
		command("say 外臣的职贴由三司户部副使发放。");
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
	me->set("song/salary_zhi",me->query("mud_age"));
	me->set("song/last_zhi_credit",me->query("song/credit"));
	MONEY_D->pay_player(me, salary);
	DASONG_D->multi_record(me,salary,"职贴",1);
	CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s领大宋职贴：%s。", me->name(),MONEY_D->money_str(salary)));
	if (me->get_title(TITLE_SONG1))
	tell_object(me,BOLD+HBCYN+HIY+"你领取了"+me->get_title(TITLE_SONG1)+BOLD+HBCYN+HIY+"的职贴钱共计"+MONEY_D->money_str(salary)+"。\n"+NOR);
	else
	tell_object(me,BOLD+HBCYN+HIY+"你领取了职贴钱共计"+MONEY_D->money_str(salary)+"。\n"+NOR);
	return 1;
}

int salary(object me)
{
	string arg;
	object env=environment(me),record;
	int salary,i,n;
	mapping *salary_list;
	if (!env)
	return 1;
	if (!me->query("song/pro"))
	return 2;
	salary_list=DASONG_D->sanjie_list(me->query("song/pro"));
	for (i=0;i<sizeof(salary_list);i++)
	{
		if (me->get_title(TITLE_SONG2)==salary_list[i]["title"])
		{
			salary=salary_list[i]["salary"];
			break;
		}
	}
	if (!salary)
	return 3;
	record=load_object("/d/song/record/other");
	me->set("song/salary",me->query("mud_age"));
	command("tell "+me->query("id")+" 你今年的本俸应为"+MONEY_D->money_str(salary)+"。");
	MONEY_D->pay_player(me, salary);
	DASONG_D->multi_record(me,salary,"本俸",1);
	CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s领大宋本俸：%s。", me->name(),MONEY_D->money_str(salary)));
	tell_room(env,"内东门司的小黄门给"+me->name()+"送来了今年的本俸。\n",({me}));
	tell_object(me,HBCYN+HIY+"内东门司派人送来了你今年的本俸，一共是" + MONEY_D->money_str(salary) + "。\n"+NOR);
	arg=sprintf("内东门司于%s发放本俸%s于你。\n",ctime(time()),MONEY_D->money_str(salary));
	record->record(me,arg);
	return 1;
}
int salary_me()
{
	object *ob=DASONG_D->song_all();
	for (int i=0;i<sizeof(ob);i++)
	{
		if (ob[i]->query("song/pro")!="宦")
		continue;
		if (ob[i]->query("mud_age")-ob[i]->query("song/salary")<86399)
		continue;
		salary(ob[i]);
	}
	return 1;
}