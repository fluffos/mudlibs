// localbuy.c by fire on Jan 1999
// this is used to handle job of buy sth for local area
#define JOBID "localbuy"
mixed get_localbuy(string p_id)
{
   object o_id;
   string p_what;
   o_id=find_body(p_id);
   if(!objectp(o_id)) return -1;
   if(!CHAR_D->char_exist(p_id)) return -2;
   if(!o_id->query_job(JOBID,"beg_time")) return 0;
   if((CHAR_D->get_char(p_id,"area"))!=
      (o_id->query_job(JOBID,"area"))) 
          {
                o_id->resign_job(JOBID);
                return 0;
   }
   p_what=o_id->query_job(JOBID,"what");
   if(!(EV_MERCHANT)->query_goods(p_what,"name"))
   {
           o_id->resign_job(JOBID); return 0;
   }
   return p_what;
}
