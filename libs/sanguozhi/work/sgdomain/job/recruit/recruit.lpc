// recruit.c by fire on Dec 1998
// this is used to store some function for recruit job
#define JOBID "recruit"
int get_recruit_left(string p_id)
{
   object o_id;
   o_id=find_body(p_id);
   if(!objectp(o_id)) return -1;
   if(!CHAR_D->char_exist(p_id)) return -2;
   if(!o_id->query_job(JOBID,"beg_time")) return 0;
   if((CHAR_D->get_char(p_id,"area"))!=
      (o_id->query_job(JOBID,"area"))) return 0;
   return o_id->query_job(JOBID,"left");
}
