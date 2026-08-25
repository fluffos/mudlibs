// input.c by fire on Dec 11,1998
// this is used to handle the manual arrange for war
// inherited by ev_war.c
#define MAX_TIME 30
#define MAX_TOO_LONG 300
int input_arrange(int task_id,string p_side,string str);
void input_process(string p_id,int t_id,string p_side,string str);
string get_def_val_str(int task_id);
string def_prompt(int task_id);
mixed check_def_answer(int task_id,string str);
// the player's id and the task id and the side


private int is_toolong=0;
private string p_leader;
private int start_time=0;
void clean_me() {
        object o;
        remove_call_out("too_long");
        remove_call_out("no_answer");

        if(sizeof(p_leader)) {
                o=find_user(p_leader);
                if(objectp(o)) 
              o->modal_pop();
        }
        destruct(this_object()); 
        return;

}
string query_prompt(int t_id,string p_side)
{
   if(p_side=="d") 
   {
      return (EV_WAR)->def_prompt(t_id);
   }
   if(p_side=="a") 
   {
        return (EV_WAR)->att_prompt(t_id);
   }
   return "query_prompt\nnot finished\n";
}
mixed check_answer(int t_id,string p_side,string str)
{
    if(p_side=="d")
        return (EV_WAR)->check_def_answer(t_id,str);
    if(p_side=="a")
        return (EV_WAR)->check_att_answer(t_id,str);
    return 0;
}
string query_def_answer(int t_id,string p_side)
{
    if(p_side=="d")
        return (EV_WAR)->get_def_val_str(t_id);
    if(p_side=="a") 
        return (EV_WAR)->get_att_val_str(t_id);
   return "right";
}
void finan_arrange(int task_id,string p_side)
{
  if(p_side=="d") 
        (EV_WAR)->def_arrange_left(task_id);
  if(p_side=="a") 
        (EV_WAR)->att_arrange_left(task_id);
  remove_call_out("too_long");
  remove_call_out("no_answer");
  clean_me();
}
void man_input(string p_id,int t_id,string p_side)
{
   object o,ob;
   string p_prompt;
        p_leader=p_id;
        if(!TASK_D->task_exist(t_id)) {
                clean_me();
                return;
        }
        o=find_user(p_id);
   ob=find_body(p_id);
   if(start_time==0) start_time=time();
   if((!objectp(o))||(!objectp(ob))||is_toolong||((time()-start_time)>MAX_TOO_LONG)) 
   {

        if(p_side=="a") 
        {       (EV_WAR)->atack_abort(p_id,t_id); 
                clean_me();

                return;
        }
        call_out("no_answer",2,p_id,t_id,p_side);
        return;
   }

   p_prompt=query_prompt(t_id,p_side);

   call_out("no_answer",MAX_TIME,p_id,t_id,p_side);
   tell_user(p_id,p_prompt);
   o->modal_push((: input_process,p_id,t_id,p_side :),"",0,0);
}
int input_arrange(int task_id,string p_side,string str)
{
   if(p_side=="d")
      return (EV_WAR)->input_arrange_def(task_id,str);
   if(p_side=="a")
      return (EV_WAR)->input_arrange_att(task_id,str);
   return 0;  
}
void input_process(string p_id,int t_id,string p_side,string str)
{
   mixed ret;
   object o;
        if(!TASK_D->task_exist(t_id)) {
                clean_me();
                return;
        }

   remove_call_out("no_answer");
   if((!str)||(str==""))
     str=query_def_answer(t_id,p_side);
   ret=check_answer(t_id,p_side,str);
   if(stringp(ret))
   {    tell_user(p_id,ret); 
        call_out("no_answer",5,p_id,t_id,p_side);
        return; 
    }// illegual answer 
   o=find_user(p_id);
   if(objectp(o))
      o->modal_pop();
/*
// this part need carefully examine
   if(str=="-1") 
   {  finan_arrange(t_id,p_side);
      return;
   } 
*/
   if(input_arrange(t_id,p_side,str)==0) {
        finan_arrange(t_id,p_side);
        return;  
   }
   man_input(p_id,t_id,p_side);
   return;
}
void no_answer(string p_id,int t_id,string p_side)
{

   string p_defanswer;
   p_defanswer=query_def_answer(t_id,p_side);
   input_process(p_id,t_id,p_side,p_defanswer);
}
void too_long() {
        is_toolong=1;
}
void setup() {
    is_toolong=0;
	start_time=time();
        call_out("too_long",MAX_TOO_LONG);
}


