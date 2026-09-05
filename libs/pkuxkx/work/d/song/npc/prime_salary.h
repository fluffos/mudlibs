#include <ansi.h>
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
	if (me->query("song/suikao/excellent_year")+3600*24>me->query("mud_age"))
	{
		n=2+random(2);
		salary=salary*n;
		command("tell "+me->query("id")+" 因为你今年岁考为全优，本俸被"+chinese_number(n)+"倍发放。");
	}
	MONEY_D->pay_player(me, salary);
	DASONG_D->multi_record(me,salary,"本俸",1);
	CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s领大宋本俸：%s。", me->name(),MONEY_D->money_str(salary)));
	tell_room(env,"户部的小吏给"+me->name()+"送来了今年的本俸。\n",({me}));
	tell_object(me,HBCYN+HIY+"户部派人送来了你今年的本俸，一共是" + MONEY_D->money_str(salary) + "。\n"+NOR);
	arg=sprintf("户部于%s发放本俸%s于你。\n",ctime(time()),MONEY_D->money_str(salary));
	record->record(me,arg);
	return 1;
}
int salary_me()
{
	object *ob=DASONG_D->song_all();
	for (int i=0;i<sizeof(ob);i++)
	{
		if (ob[i]->query("song/pro")!="文"&&ob[i]->query("song/pro")!="武")
		continue;
		if (DASONG_D->get_my_pin(ob[i])>2&&ob[i]->query("song/suikao/time")+3600*24<ob[i]->query("mud_age"))
		continue;
		if (ob[i]->query("mud_age")-ob[i]->query("song/salary")<86399)
		continue;
		if (ob[i]->query("song/credit")<=ob[i]->query("song/lastcredit")&&DASONG_D->get_my_pin(ob[i])>2)
		continue;
		salary(ob[i]);
	}
	return 1;
}