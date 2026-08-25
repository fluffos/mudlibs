// resign.c 
// by row on May 29, 1999
// used for player char to risign a job
#include <ansi.h>
string job_id;
string job_memo1;
void confirm_resign(mixed p_input)
{
	string p_id;
	int rep,cut_rep;
	p_id=this_object()->query_id()[0];
	cut_rep=random(50);
	if(p_input=="yes")
	{
	if( !COUNTRY_D->nation_exist(CHAR_D->get_char(p_id,"nation")) )
	{
	this_user()->finish_job(job_id);
	write("你决定放弃""HIY"+job_memo1+"的工作。\n");
	return;
	}
	rep=CHAR_D->get_char(p_id,"reputation");
	
if ((rep-cut_rep)<10)
	{
	write("你决定放弃""HIY"+job_memo1+"的工作。\n");
	return;
	}
	rep=rep-cut_rep;
	write("你决定放弃""HIY"+job_memo1+"的工作。\n");
	write("你的声望下降了"+chinese_number(rep)+"点。\n");
	return;
	}
	else
	write("工作是不能随便放弃的呀。\n");
	this_user()->modal_pop();
	return; 
}
void start(string arg)
{
	string job_id,job_memo;
	int beg_time,time;
	time=time();
	if((!arg)||(arg==""))
	{
	write("用法: cmd resign <job_id>\n");
	write("例子：cmd resign whisper (放弃策反敌将的工作)\n");
	return;
	}
	beg_time=this_user()->query_job(arg,"beg_time");
	if (beg_time=0)
	{
	write("你并没有领过这项工作。\n");
	return;
	}
	job_memo=this_user()->query_job(arg,"memo");
	job_memo1=job_memo;
	job_id=arg;
	if ((time-beg_time)/60<5)
	{
	write("你刚刚才接受工作，至少先试试再考虑放弃吧。\n");
	return;
	}
	else
	{
	write("你决定了要放弃""HIY"+job_memo+"NOR""这项工作吗？（将会有一定损失）\n确定请输入yes，任意键回车后退出。\n");
	this_user()->modal_push((: confirm_resign :),"",0,0);
	}
}
