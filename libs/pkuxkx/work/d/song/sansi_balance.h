#include <ansi.h>
#include "/d/song/commands/cmd_assist.h"
void init()
{
	add_action("do_balance","balance");
	if (base_name(this_object())!="/d/song/sansishi1")
	return;
	add_action("do_zaoce","zaoce");
	add_action("do_write","write");
}
int decision(string arg,object me,int surplus,string msg)
{
	if (arg=="盈余"&&surplus>=0)
	{
		message_vision("$N在宗卷上签下了"+HIR+"“"+arg+"”"+NOR+"二字，并令人张贴在三司使衙门的门口。\n",me);
		DASONG_D->set("balance_detail",msg);
		return DASONG_D->task_finish(me,1+random(2));
	}
	else if (arg=="赤字"&&surplus<0)
	{
		message_vision("$N在宗卷上签下了"+HIR+"“"+arg+"”"+NOR+"二字，并令人张贴在三司使衙门的门口。\n",me);
		DASONG_D->set("balance_detail",msg);
		return DASONG_D->task_finish(me,1+random(2));
	}
	else
	{
		message_vision("$N看着账目，一头雾水，完全打不定主意了。\n",me);
		DASONG_D->delete("balance_detail");
		return 1;
	}
}
int do_balance()
{
	int surplus;
	object me=this_player();
	string msg=HBBLU+HIR+"今岁大宋各项收支\n"+NOR,msg2=msg;
	string benefit="sansi_balance",type="day";
	if (!wizardp(me)&&!DASONG_D->identification(me,({"三司使","三司度支副使","三司户部副使","三司盐铁副使"})))
	return 0;
	msg2+=HIC+"【官员报效】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/报效/total"))+"\n";
	msg2+=HIR+"【本俸支出】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/本俸/total")-DASONG_D->query("salary_record/本俸/宦/sum"))+"\n";
	msg2+=HIR+"【职贴支出】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/职贴/total")-DASONG_D->query("salary_record/职贴/宦/sum"))+"\n";
	msg2+=HIR+"【学士院支出】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/学士院补贴/total"))+"\n";
	msg2+=HIR+"【宗室食邑】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/食邑/total"))+"\n";
	if (wizardp(me)||DASONG_D->identification(me,({"三司使",})))
	{
		msg+=HIC+"【官员报效】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/报效/total"))+"\n";
		msg+=HIR+"【文官本俸】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/本俸/文/sum"))+"\n";
		msg+=HIR+"【武官本俸】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/本俸/武/sum"))+"\n";
		msg+=HIR+"【本俸支出】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/本俸/total")-DASONG_D->query("salary_record/本俸/宦/sum"))+"\n";
		msg+=HIR+"【文官职贴】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/职贴/文/sum"))+"\n";
		msg+=HIR+"【武官职贴】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/职贴/武/sum"))+"\n";
		msg+=HIR+"【职贴支出】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/职贴/total")-DASONG_D->query("salary_record/职贴/宦/sum"))+"\n";
		msg+=HIR+"【学士院支出】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/学士院补贴/total"))+"\n";
		msg+=HIR+"【宗室食邑】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/食邑/total"))+"\n";
		surplus=DASONG_D->query("salary_record/报效/total")-(DASONG_D->query("salary_record/本俸/total")-DASONG_D->query("salary_record/本俸/宦/sum"))-(DASONG_D->query("salary_record/职贴/total")-DASONG_D->query("salary_record/职贴/宦/sum"))-DASONG_D->query("salary_record/学士院补贴/total")-DASONG_D->query("salary_record/食邑/total");
		write(msg);
		song_cycle(me,type,benefit);
		if (me->query("song/"+benefit+"/times")>=1)
		return 1;
		me->add("song/"+benefit+"/times",1);
		write("请批注收支是"+HIC+U+"盈余"+NOR+"还是"+HIR+U+"赤字"+NOR+"？(总收总支为零也记为盈余)");
		input_to((:decision:),me,surplus,msg2);
		return 1;
	}
	else
	{
		write(msg2);
		return 1;
	}
}