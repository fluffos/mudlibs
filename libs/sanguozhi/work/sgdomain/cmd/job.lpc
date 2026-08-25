// job.c used for player to check the job stuation
// by fire on November 14, 1998
// Modified by flee on 25 NOV 1998, change some parameters
string show_all_job(int p_lev)
{
  string* list; 
  string ret;
  string nam,s_lev;
  int num=1;
  int assign_job,finish_job,lev;
  list=JOB_D->list_jobs();
  ret=
"序号 工作ID        工作名称  等级  申请次数  完成次数\n"+
"=====================================================\n";
foreach(string t in list)
{
	nam=JOB_D->query_job(t,"name");
	lev=JOB_D->query_job(t,"level");
	if((p_lev!=-2)&&(p_lev!=lev)) continue;
	assign_job=JOB_D->query_job(t,"assign_job");
	finish_job=JOB_D->query_job(t,"finish_job");
        switch (lev) {
		case -1:
			s_lev="特殊";
			break;
		case 0: 
			s_lev="初级";
			break;
		case 1: s_lev="中级";
			break;
		case 2: s_lev="高级";
			break;
		default :
			s_lev="未知";
	}
    ret+=sprintf("%3d  %-12s  %-8s  %4s  %6d    %6d\n",num++,t,nam,s_lev,assign_job,finish_job);
  }
  return ret;
}

string show_job(object o_id, int level) { // -2 means all level
	string *jobs;
	string ret;
        int num=1;
	jobs=o_id->query_job("list");
  	if(sizeof(jobs)==0)
      		return "未查到任何工作纪录。\n";
	ret =
"                                   当天 目前  上次开始      \n"+
"序号 工作名称  工作ID       总次数 次数 状态 或完成时间   备注 \n"+
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
	foreach(string jb in jobs)
  	{
      		string name,statue,lasttimes,s_time;
	  	mixed memo;
      		int p_time,lev,count,lastcount;
		lev=JOB_D->query_job(jb,"level");
		if((level!=-2)&&(level!=lev)) continue;
      		name=JOB_D->query_job(jb,"name");
	    	if(!name) continue;

      		count=o_id->query_job(jb,"count");
	      	lastcount=o_id->query_job(jb,"count_lasttimes");
	      	p_time=o_id->query_job(jb,"beg_time");     
      		statue=(p_time>0 ? "执行" : "完成");
	      	if(!p_time)
        		p_time=o_id->query_job(jb,"finish_time");
		p_time=time()-p_time;
		p_time/=60;

		if( p_time > 24 * 60 * 30 )
        		s_time= chinese_number(p_time/(24 * 60 * 30))+"月";
		else if( p_time > 24 * 60 * 7 )
        		s_time= chinese_number(p_time/(24 * 60 * 7))+"周";
		else if( p_time > 24 * 60 )
        		s_time= chinese_number(p_time/(24 * 60))+"天";
		else if( p_time > 60 )
        		s_time= chinese_number(p_time/60)+"小时";
		else
        		s_time= chinese_number(p_time)+"分钟";

		s_time+="前";

	  	memo=o_id->query_job(jb,"memo");
	  	if(!memo) memo="____";
         	ret+=sprintf("%3d  %-10s%-12s%6d%5d  %4s %-12s %s\n",
			num++,name,jb,count,lastcount,statue,s_time,memo);
	}
	return ret;
}

void start(string arg)
{
  object o_id;
  string *jobs;
  string msg;
  string who,what;
  int n;
  if(!arg) arg="";
  if(find_body(arg)) {
        who=arg;
        what="";
  }
  else {
  	n=sscanf(arg,"%s %s",who,what);
  	if(n==0) // just one 
  	{
		who=this_body()->query_primary_id();
		what=arg;
  	}

  }

  o_id=find_body(who);

  if(!wizardp(this_body()) && objectp(o_id) && (o_id!=this_body()) ) {
        write("只有巫师才可检查他人的工作情况。\n");
        return;
  }

  if(!objectp(o_id)) {write("找不到："+who+"。\n"); return; }

  if((what=="")||!what) what="all";
  switch (what) {
      case "all" : 
	msg=show_job( o_id, -2); // -2 means 2
	break;
      case "basic" :	
	msg=show_job( o_id, 0); // -2 means 2
	break;
      case "middle" :	
	msg=show_job( o_id, 1); // -2 means 2
	break;
      case "high" :	
	msg=show_job( o_id, 2); // -2 means 2
	break;
      case "special" :	
	msg=show_job( o_id, -1); // -2 means 2
	break;
      case "stat" : 
	msg=show_all_job(-2);
	break;
      case "statb" : 
	msg=show_all_job(0);
	break;
      case "statm" : 
	msg=show_all_job(1);
	break;
      case "stath" : 
	msg=show_all_job(2);
	break;
      case "stats" : 
	msg=show_all_job(-1);
	break;

      default :
        msg="没有这个参数：请参阅 help job。\n";
  }
  write (msg);
  return ;
}