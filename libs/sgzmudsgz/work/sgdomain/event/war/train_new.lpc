// train_new.c by fire on Dec 1998
#include <train.h>
// get a new question
string auto_start_point(string p_area,string p_side);
mixed new_question(int task_id)
{
   mixed question,f_question;
   int *troops,troop_num;
   question=TASK_D->get_task(task_id,"question");
   if(!question)
     return "arrange";
   f_question=TASK_D->get_task(task_id,"f_question");
   if(!f_question) f_question=([]);
   if(!f_question[question])
       f_question[question]=1;
   else
       f_question[question]++;
   TASK_D->set_task(task_id,"f_question",f_question);
   troops=TASK_D->get_task(task_id,"def_army");
   troop_num=sizeof(troops);
   if(f_question["moveme"]<MAXTIMES_MOVEME)
      return "moveme";
   if((troop_num>1)&&(f_question["moveother"]<MAXTIMES_MOVEOTHER))
     return "moveother";
   if((troop_num>1)&&(f_question["moveall"]<MAXTIMES_MOVEALL))
     return "moveall";
   if((troop_num>1)&&(f_question["followme"]<MAXTIMES_FOLLOWME))
     return "followme";
   if((troop_num>1)&&(f_question["stay"]<MAXTIMES_STAY))
     return "stay";
   if((troop_num>1)&&(f_question["guard"]<MAXTIMES_GUARD))
     return "guard";
   if((f_question["question"]<MAXTIMES_QUESTION))
     return "question";
   if((f_question["defence"]<MAXTIMES_DEFENCE))
     return "defence";
   if((f_question["attack"]<MAXTIMES_ATTACK))
     return "attack";
   return 0;
}
void question_new(int task_id,string question)
{
   int maxtime,question_num;
   int *troops,my_troop;
   string p_leader,p_area,s_point;
   mixed trainpara=0;
   object o,o_troop;
   
   troops=TASK_D->get_task(task_id,"def_army");
   p_area=TASK_D->get_task(task_id,"def_area");
   p_leader=TASK_D->get_task(task_id,"def_leader");
   o=CHAR_D->find_char(p_leader);
   if (o == 0) return;
   o_troop=environment(o);
   my_troop=o_troop->get_id();
   question_num=TASK_D->get_task(task_id,"question_num")+1;
   switch(question)
   {
     case "arrange" :
       maxtime=30; // five min
       break;
     case "moveme" :
       maxtime=60; // ten min
       s_point=auto_start_point(p_area,"a");
       trainpara=s_point;
       break;
     case "moveother" :
       maxtime=60; // ten min
       s_point=auto_start_point(p_area,"a");
       troops-=({my_troop});
       trainpara=([]);
       trainpara[troops[random(sizeof(troops))]]=s_point;
       break;
     case "moveall" :
       maxtime=60; // ten min
       trainpara=([]);
       { int i,sum;
         sum=sizeof(troops);
         for(i=0;i<sum;++i)
         {
           s_point=auto_start_point(p_area,"a");
           trainpara[troops[i]]=s_point;
         }
       }
       break;
     case "followme" :
       maxtime=60; // ten min
       troops-=({my_troop});
       trainpara=([]);
       trainpara[troops[random(sizeof(troops))]]=my_troop;
       break;
     case "stay" :
       maxtime=6; // one min is enough
       troops-=({my_troop});
       trainpara=troops[random(sizeof(troops))];
       break;
     case "guard" :
       maxtime=18;  // give three mins
       troops-=({my_troop});
       trainpara=([]);
       trainpara[troops[random(sizeof(troops))]]=random(4);
       break;
     case "question":
       maxtime=6;
       trainpara=get_train_question();
       break;
     case "defence":
       maxtime=60;
       train_arrange_defence(task_id);
       break;
     case "attack":
       maxtime=60;
       train_arrange_attack(task_id);
       break;
     default:
   }
   TASK_D->set_task(task_id,"question_num",question_num);
   TASK_D->set_task(task_id,"question",question);
   TASK_D->set_task(task_id,"maxtime",maxtime);
   TASK_D->set_task(task_id,"curtime",0);
   TASK_D->set_task(task_id,"trainpara",trainpara);
   announce_task(task_id);
   switch(question)
   {
     case "arrange" :
       new("/sgdomain/menu/warinput")->man_input(p_leader,task_id,"d");
       return;
     case "question":
       show_question(p_leader,task_id);
       return;
   }
}
void announce_task(int task_id)
{
   int maxtime,curtime,question_num,*troops,my_troop;
   string mess;
   string p_leader,p_area,s_point,question;
   mixed trainpara=0;
   maxtime=TASK_D->get_task(task_id,"maxtime");
   curtime=TASK_D->get_task(task_id,"curtime");
   question=TASK_D->get_task(task_id,"question");
   troops=TASK_D->get_task(task_id,"def_army");
   p_area=TASK_D->get_task(task_id,"def_area");
   p_leader=TASK_D->get_task(task_id,"def_leader");
   trainpara=TASK_D->get_task(task_id,"trainpara");
   question_num=TASK_D->get_task(task_id,"question_num");
   switch(question)
   {
     case "arrange" :
       mess="将兵分好，领入战场。";
       break;
     case "moveme" :
       s_point=WARAI_D->get_pos_disp
          (WARAI_D->point_toint(trainpara));
       mess="行军到"+s_point+"。";
       break;
     case "moveother":
       my_troop=keys(trainpara)[0];
       s_point=trainpara[my_troop];
       s_point=WARAI_D->get_pos_disp
          (WARAI_D->point_toint(s_point));
       mess="指挥"+TROOP_D->get_troops(my_troop,"name")+
          "行军到"+s_point+"。";
       break;
     case "moveall":
       mess="完成以下行军任务：\n";
       troops=keys(trainpara);
       { int i,sum;
         sum=sizeof(troops);
         for(i=0;i<sum;++i)
         {
           s_point=trainpara[troops[i]];
           s_point=WARAI_D->get_pos_disp
              (WARAI_D->point_toint(s_point));
          mess+=TROOP_D->get_troops(troops[i],"name")+
          "到"+s_point+"。\n";
         }
       }
       break;
     case "followme":
       my_troop=keys(trainpara)[0];
       mess="指挥"+TROOP_D->get_troops(my_troop,"name")+
          "追击方式行军到你自己的部队所在地。\n";
       break;
     case "stay" :
       my_troop=trainpara;
       mess="指挥"+TROOP_D->get_troops(my_troop,"name")+
          "在原地待命。";
       break;
     case "guard" :
       my_troop=keys(trainpara)[0];
       mess="指挥"+TROOP_D->get_troops(my_troop,"name")+
          "在原地防守，防守范围为："+
          CHINESE_D->chinese_number(trainpara[my_troop])+"。\n";
       break;
     case "question":
       mess="回答下面问题，不清楚用help看帮助信息。\n";
       break;
     case "defence":
       mess="消灭敌军。";
       break;
     case "attack":
       mess="消灭所有敌军。";
       break;
     default:
   }
   mess="%^H_WHITE%^任务"+chinese_number(question_num)+"："+
     "请在"+CHINESE_D->chinese_period((maxtime)*10)+"内"+               
mess+"目前剩余时间："+
       CHINESE_D->chinese_period((maxtime-curtime)*10)+"。%^RESET%^\n";
   tell_user(p_leader,mess);
}
