#include <ansi.h>
#include "/d/song/commands/cmd_assist.h"
void init()
{
	add_action("do_govern","govern");
}
int decision(string arg,object me,int the_answer,string msg)
{
	int answer;
	if (!arg||sscanf(arg,"%d",answer)!=1)
	{
		message_vision("$N算来算去，发现自己还是算错了。\n",me);
		DASONG_D->delete("gov_detail");
		return 1;
	}
	if (answer==the_answer)
	{
		message_vision("$N在宗卷上填写了"+HIR+"“"+chinese_number(answer)+"次”"+NOR+"，并令人张贴在政事堂的门口。\n",me);
		DASONG_D->set("gov_detail",msg);
		if (DASONG_D->identification(me,({"同中书门下平章事"})))
		return DASONG_D->task_finish(me,1+random(3));
		else
		return DASONG_D->task_finish(me,1+random(2));
	}
	else
	{
		message_vision("$N算来算去，发现自己还是算错了。\n",me);
		DASONG_D->delete("gov_detail");
		return 1;
	}
}
int do_govern()
{
	int n,*answers=({DASONG_D->query("gov_record/给出/total"),DASONG_D->query("gov_record/完成/total"),DASONG_D->query("gov_record/提升/total")});
	string *desc=({"政事堂共计发放任务","文官总计完成任务","文武官员获得提升"});
	object me=this_player();
	string msg=HBBLU+HIR+"今岁大宋政务\n"+NOR,msg2=msg;
	string benefit="zhengshitang",type="day";
	if (!wizardp(me)&&!DASONG_D->identification(me,({"同中书门下平章事","参知政事"})))
	return 0;
	msg2+=HIW+"【任务发放】"+NOR+chinese_number(DASONG_D->query("gov_record/给出/total"))+"次\n";
	msg2+=CYN+"【任务完成】"+NOR+chinese_number(DASONG_D->query("gov_record/完成/total"))+"次\n";
	msg2+=MAG+"【官员提升】"+NOR+chinese_number(DASONG_D->query("gov_record/提升/total"))+"次\n";
	n=random(sizeof(answers));
	write(msg2);
	song_cycle(me,type,benefit);
	if (me->query("song/"+benefit+"/times")>=1)
	return 1;
	me->add("song/"+benefit+"/times",1);
	write("今岁"+desc[n]+"的次数？(请用阿拉伯数字回答)");
	input_to((:decision:),me,answers[n],msg2);
	return 1;
}