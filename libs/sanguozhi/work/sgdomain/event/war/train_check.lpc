// train_check.c by fire on Dec 1998
#include <train.h>
int check_question(int task_id)
{
   mixed question;
   int curtime,maxtime,my_troop,*troops;
   string p_id,s_point;
   object o_id,o_troop;
   mixed tmp,trainpara;
   p_id=TASK_D->get_task(task_id,"def_leader");
   
   question=TASK_D->get_task(task_id,"question");
   if(!question)  return NO_QUESTION;
   curtime=TASK_D->get_task(task_id,"curtime");
   maxtime=TASK_D->get_task(task_id,"maxtime");
   if(curtime>maxtime) return QUESTION_OVER_DUE;
   o_id=CHAR_D->find_char(p_id);
   if(objectp(o_id)) o_troop=environment(o_id);
   trainpara=TASK_D->get_task(task_id,"trainpara");

   switch(question)
   {
      case "arrange": 
         tmp=TASK_D->get_task(task_id,"def_stage");
         if(tmp=="enter_warfield")
         {
            if(o_troop->is_troop()) return QUESTION_SUCCESS;
            return QUESTION_FAIL;
         }
         break;
     case "moveme":
         tmp=o_troop->get_id();
         tmp=TROOP_D->get_troops(tmp,"position");
         tmp=WARAI_D->point_tostring(tmp);
         if(tmp==trainpara) return QUESTION_SUCCESS;
         break;
     case "moveother":
       my_troop=keys(trainpara)[0];
       s_point=trainpara[my_troop];
       tmp=TROOP_D->get_troops(my_troop,"position");
       tmp=WARAI_D->point_tostring(tmp);
       if(tmp==s_point) return QUESTION_SUCCESS;
       break;
     case "moveall":
       troops=keys(trainpara);
       { int i,sum,f=0;
         sum=sizeof(troops);
         for(i=0;i<sum;++i)
         {
           
           my_troop=keys(trainpara)[i];
           s_point=trainpara[my_troop];
           tmp=TROOP_D->get_troops(my_troop,"position");
           tmp=WARAI_D->point_tostring(tmp);
           if(tmp!=s_point) f=1;
         }
         if(f==0) return QUESTION_SUCCESS;
       }
       break;
     case "followme" :
       {  int you_troop;
          you_troop=keys(trainpara)[0];
          my_troop=trainpara[you_troop];
          tmp=WARAI_D->point_tostring
                (TROOP_D->get_troops(my_troop,"position"));
          s_point=WARAI_D->point_tostring(
               TROOP_D->get_troops(you_troop,"position"));
          if(s_point==tmp)
          {
             tmp=TROOP_D->get_troops(you_troop,"command");
             if(mapp(tmp)&&(tmp["action"]=="pursue")&&(tmp["aim"]==my_troop))
                 return QUESTION_SUCCESS;
          }
       }
       break;
     case "stay" :
       my_troop=trainpara;
       tmp=TROOP_D->get_troops(my_troop,"command");
       if(mapp(tmp)&&tmp["action"]=="stay") return QUESTION_SUCCESS;
       break;
     case "guard" :
       my_troop=keys(trainpara)[0];
       tmp=TROOP_D->get_troops(my_troop,"command");
	if(mapp(tmp))
           if((tmp["action"]=="guard")&&
              (tmp["range"]==trainpara[my_troop]))
                  return QUESTION_SUCCESS;
       break;
     case "question":
       if(trainpara["right"])
       return QUESTION_SUCCESS;
       break;
     case "defence":
		if(CHAR_D->get_char(p_id,"troop")==0)
			return QUESTION_OVER_DUE;
		 tmp=TASK_D->get_task(task_id,"att_army");
       if(!sizeof(tmp)) return QUESTION_SUCCESS;
       break;
     case "attack":
		if(CHAR_D->get_char(p_id,"troop")==0)
			return QUESTION_OVER_DUE;
       tmp=TASK_D->get_task(task_id,"att_army");
       if(!sizeof(tmp)) return QUESTION_SUCCESS;
       break;
     default:
   }
   if((curtime%6)==0)
       announce_task(task_id);
   return QUESTION_PROCESS;
}
