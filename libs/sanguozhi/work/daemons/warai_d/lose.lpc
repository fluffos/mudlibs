// this is handle the lose of a war
// lose.c
void add_war_lose(int t_id,string p_side,string wat,int num)
{
   string p_name;
   mixed p_lose;
   if(p_side=="a") p_name="att_lose";
   else p_name="def_lose";
   p_lose=TASK_D->get_task(t_id,p_name);
   if(!p_lose)
     p_lose=([]);
   if(!p_lose[wat])
      p_lose[wat]=num;
   else
      p_lose[wat]+=num;
   TASK_D->set_task(t_id,p_name,p_lose);
}
