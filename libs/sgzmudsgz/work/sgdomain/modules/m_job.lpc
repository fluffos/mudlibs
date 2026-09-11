// by fire on November 27 1998
// m_job.c this is used for Job system
#define FULLDAY 43200  // HALF DAY
private mapping jobs = ([]);
int count_lasttimes(string j_id);
string *list_job();
string paraname(string j_id);
// this function is used to check current situation of one player's
// job information, just for online debug useage
mixed remove_job(string j_id)
{
        if(!jobs[j_id])return "fail\n";
        else map_delete(jobs, j_id);
}
mixed set_job(string j_id,string para,mixed value)
{
        if(!jobs[j_id])
                return "fail";
        jobs[j_id][para]=value;
        return value;
}
mixed query_job(string j_id,string para)
{
        if((j_id=="")||(!j_id))
                return jobs;
        switch(j_id)
        {   
           case "list":
                return list_job();
        }
       if(!jobs[j_id])
              return 0;
        switch(para)
        {
        case "count_lasttimes":
               return count_lasttimes(j_id);
	    case "lasttimes" : 
               count_lasttimes(j_id);
        		return jobs[j_id]["lasttimes"];
        case "":
                return jobs[j_id];
        default :
                if(!jobs[j_id][para])
                        return 0;
               return jobs[j_id][para];
        }
}
mixed add_job(string j_id)
{
  mixed p_job;
  p_job=query_job(j_id,"");
  if(!p_job)
    p_job=([]);
  if(!p_job["beg_time"]) // this is used to demonstrate the  begining
  { // of the job and also means, now we are undertaking this kind of job
    p_job["beg_time"]=time(); 
    jobs[j_id]=p_job;                           
   JOB_D->assign_job(j_id);

    return 1; // a new job has been added
  }
  return 0; // we are doing this job already so can't 
            // add the job again
}
mixed resign_job(string j_id)
{
   int p_count,*p_lasttimes;
   int p_time=time();
   if(!query_job(j_id,"beg_time")) return;

   p_count=query_job(j_id,"count");
   set_job(j_id,"count",p_count+1);
   p_lasttimes=query_job(j_id,"lasttimes");

   if(!p_lasttimes)
     p_lasttimes=({});
   p_lasttimes+=({p_time});
   set_job(j_id,"lasttimes",p_lasttimes);
   set_job(j_id,"beg_time",0);
   return 1;
}
mixed finish_job(string j_id)
{
   int p_time=time();
   int p_count;
   array p_lasttimes;
   int p_beg_time;
   p_beg_time=query_job(j_id,"beg_time");
   if(!p_beg_time)
        return 0; // not doing this job at all
   set_job(j_id,"finish_time",p_time);
   p_count=query_job(j_id,"count");
   set_job(j_id,"count",p_count+1);
   p_lasttimes=query_job(j_id,"lasttimes");
   if(!p_lasttimes)
     p_lasttimes=({});
   p_lasttimes+=({p_time});
   set_job(j_id,"lasttimes",p_lasttimes);
   set_job(j_id,"beg_time",0);
   JOB_D->finish_job(j_id);
   return 1;
}
int count_lasttimes(string j_id)
{
   int p_time=time();
   array p_lasttimes;
   array n_lasttimes;
	p_lasttimes=jobs[j_id]["lasttimes"];
//   p_lasttimes=query_job(j_id,"lasttimes");
   if(!p_lasttimes)
     p_lasttimes=({});
   // remove count more than one day
   n_lasttimes=filter_array
    (p_lasttimes,(: $(p_time)-($1)<FULLDAY :));
   set_job(j_id,"lasttimes",n_lasttimes);
   return sizeof(n_lasttimes);
}
string* list_job()
{
   return keys(jobs);
}
