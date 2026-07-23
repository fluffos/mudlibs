//Cracked by Kafei

//wzfeng@xkx 2000 6
//job_syatem

#define JOB_DIR "/clone/obj/job/"
int JOB_TICK=5;
int JOB_PRODUCE=120;
int PRODUCE_TEMP=0;
object ob;
int start_job()
{
	
	object ob,job_data;
	PRODUCE_TEMP+=5;
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return notify_fail ("数据库程序编译出错。\n");
	job_data->restore();
	if(!job_data->query_job_start())
		return 0;
	if(!ob=find_object(JOB_DIR+"job_produce"))
		ob=new(JOB_DIR+"job_produce");
	if(!objectp(ob))
	{
		call_out("start_job",JOB_TICK);
		return 1;
	}
	if(!objectp(find_object(JOB_DIR+"job_produce")))
		ob=new(JOB_DIR+"job_produce");
	else
		ob=find_object(JOB_DIR+"job_produce");

		if(!objectp(ob))
		{
		call_out("start_job",JOB_TICK);
		return 1;
		}
		
	//Produce a job every one JOB_PRODUCE 
		if (PRODUCE_TEMP>JOB_PRODUCE)
	{
		
		ob->produce_job(0);
		
		PRODUCE_TEMP=0;
	}
		ob->check_player_place();
		call_out( "start_job",JOB_TICK); 
		return 1;
}

void check_callout()
{
	
	if(find_call_out("start_job")==-1)
	{
		remove_call_out("start_job");
		call_out("start_job",JOB_TICK);
	}
	remove_call_out("check_callout");
	call_out( "check_callout",JOB_TICK+3); 
	return;
}


void create()
{		seteuid(getuid()); 
		remove_call_out("start_job");
		call_out( "start_job",JOB_TICK); 
		remove_call_out("check_callout");
		call_out( "check_callout",JOB_TICK+3); 
}
