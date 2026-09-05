#include <ansi.h>
inherit __DIR__"song_officer";
#include "/d/song/tasks/hanlin.h"
#include <title.h>
void create()
{
	call_out("npc_to_player",1,"翰林学士",60,1+random(6));
	::create();
}

int dest(object book)
{
	if(book)
	destruct(book);
	return 1;
}

int accept_object(object me, object book)
{
    if (me->query_temp("songtasks/hanlinyuan/task")!=1)
        return notify_fail("我说过要你帮忙吗？\n");
	if (book->query("ming/history")!=me->query_temp("songtasks/hanlinyuan/target"))
	    return notify_fail("你找回来的是"+me->query_temp("songtasks/hanlinyuan/book")+"吗？\n");
	message_vision("$N接过$n手里的"+book->query("name")+"，放在鼻边嗅嗅，高兴地道：不错不错，就是它了。\n",this_object(),me);
	me->add_busy(1);
	call_out("dest",1,book);
    me->set_temp("songtasks/hanlinyuan/1/finish",1);
	tell_object(me,"你觉得"+this_object()->name()+"兴奋得有点忘乎所以了，都把你的奖励忘了，还是提醒他一下吧(ask finish)。\n");
	return 1;
}

void init()
{
	add_action("do_ling","ling");
}

int do_ling()
{
	int salary;
	object me=this_player(),ob=load_object("/d/song/record/positions");
	mapping *tz;
	if (!me->get_title(TITLE_SONG3)||me->query("song/pro")!="文")
	return notify_fail("你在学士院没有贴职，没有额外俸禄可领。\n");
	if (!ob->query("tiezhi_list"))
	return notify_fail("你在学士院没有贴职，没有额外俸禄可领。\n");
	else
	tz=ob->query("tiezhi_list");
	for (int i=0;i<sizeof(tz);i++)
	{
		if (tz[i]["name"]==me->query("id"))
		{
			salary=tz[i]["salary"]*10000;
		}
	}
	if (!salary)
	return notify_fail("你在学士院没有贴职，没有额外俸禄可领。\n");
	if (DASONG_D->get_my_pin(me)>2&&me->query("song/suikao/time")+3600*24<me->query("mud_age"))
	{
		command("say 你很久没有参加磨勘了，无法领取学士院俸禄。\n");
		return 1;
	}
	if (DASONG_D->get_my_pin(me)>2&&(me->query("song/suikao/overall")<-4||me->query("song/suikao_longtime_not_in")))
	{
		command("say 你长期未参加磨勘，或被连续记大过，无法领取学士院俸禄。");
		return 1;
	}
	if (me->query("mud_age")-me->query("song/salary_xueshi")<86399)
	{
		command("say 你今年已经领过学士院俸禄了，明年再来吧。\n");
		return 1;
	}
	me->set("song/salary_xueshi",me->query("mud_age"));
	MONEY_D->pay_player(me, salary);
	DASONG_D->multi_record(me,salary,"学士院补贴",1);
	CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s领大宋学士院俸禄：%s。", me->name(),MONEY_D->money_str(salary)));
	tell_object(me,BOLD+HBCYN+HIY+"你领取了"+me->get_title(TITLE_SONG3)+BOLD+HBCYN+HIY+"的补贴共计"+MONEY_D->money_str(salary)+"。\n"+NOR);
	return 1;
}
