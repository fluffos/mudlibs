#include <ansi.h>
inherit __DIR__"song_officer";
#include "/d/song/tasks/sansi.h"
void create()
{
	call_out("npc_to_player",1,"三司使",50,-1);
	::create();
}
int decision(string arg,object me,int result,string check)
{
	if (member_array(arg,({"sign","no"}))==-1)
	{
		write("你只能副署(sign)或者拒绝(no)。\n");
		return input_to((:decision:),me,result,check);
	}
	if (arg=="sign"&&result)
	{
		message_vision("$N认可了条目上的"+check+"，并副署了自己的大名"+me->query("name")+NOR+"。\n",me);
	}
	else if (arg=="no"&&!result)
	{
		message_vision("$N并不认可了条目上的"+check+"。\n",me);
	}
	else
	{
		message_vision("$N胡乱副署三司使的糊涂账，被朝廷申饬了。\n",me);
		return DASONG_D->task_finish(me,-4);
	}
	me->set_temp("songtasks/sansishi/2/finish",1);
	tell_object(me,"度支造册完成，跟三司使复命吧。\n");
	return 1;
}
int question(object me)
{
	int n,surplus,result=0;
	string msg=CYN+"【大宋收支条目】\n"+NOR,check="赤字";
	if (random(100)>80)
	n=50000000+random(10000000);
	if (random(2))
	check="盈余";
	surplus=DASONG_D->query("salary_record/报效/total")+n-DASONG_D->query("salary_record/本俸/文/sum")-DASONG_D->query("salary_record/本俸/武/sum")-DASONG_D->query("salary_record/职贴/文/sum")-DASONG_D->query("salary_record/职贴/武/sum")-(DASONG_D->query("salary_record/本俸/total")-DASONG_D->query("salary_record/本俸/宦/sum"))-(DASONG_D->query("salary_record/职贴/total")-DASONG_D->query("salary_record/职贴/宦/sum"))-DASONG_D->query("salary_record/学士院补贴/total")-DASONG_D->query("salary_record/食邑/total");
	if ((surplus>=0&&check=="盈余")||(surplus<0&&check=="赤字"))
	result=1;
	message_vision("$N递给了$n一张条目，需要$n的副署。\n",this_object(),me);
	msg+=HIC+"【进项】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/报效/total")+n)+"\n";
	msg+=HIR+"【支出一】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/本俸/文/sum"))+"\n";
	msg+=HIR+"【支出二】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/本俸/武/sum"))+"\n";
	msg+=HIR+"【支出三】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/本俸/total")-DASONG_D->query("salary_record/本俸/宦/sum"))+"\n";
	msg+=HIR+"【支出四】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/职贴/文/sum"))+"\n";
	msg+=HIR+"【支出五】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/职贴/武/sum"))+"\n";
	msg+=HIR+"【支出六】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/职贴/total")-DASONG_D->query("salary_record/职贴/宦/sum"))+"\n";
	msg+=HIR+"【支出七】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/学士院补贴/total"))+"\n";
	msg+=HIR+"【支出八】"+NOR+MONEY_D->money_str(DASONG_D->query("salary_record/食邑/total"))+"\n";
	write(msg);
	write("条目上批注着今年"+check+"几个字，你要副署吗(sign/no)？(总收总支为零也记为盈余)");
	input_to((:decision:),me,result,check);
	return 1;
}