// train_beg.c by fire on Dec 1998
// this is used to handle the the begin and over train
#include <train.h>
void release_army(int p_id);
void def_pre_arrange(int task_id,string def_area);

//Train_arrange() function have moved to train.c instead of this file.
/*void train_arrange(int task_id)
{
   string def_area,def_leader,*def_general;
   def_area=TASK_D->get_task(task_id,"def_area");

   def_general=TASK_D->get_task(task_id,"def_party");
   def_leader=TASK_D->get_task(task_id,"def_leader");
   def_general-=({def_leader});
   TASK_D->set_task(task_id,"def_general_left",def_general);

   def_pre_arrange(task_id,def_area);*/
/*   int p_soldier,p_people,p_horse,p_bow;
   int p_infantry,p_cavalry,p_bowman,p_commando;
   mixed def_general;   
   string def_leader;
   p_soldier=AREA_D->get_area(def_area,"soldier");
   p_horse=AREA_D->get_area(def_area,"horse");
   p_bow=AREA_D->get_area(def_area,"bow");
   p_cavalry= bmin(p_soldier,p_horse);
   p_soldier-=p_cavalry;
   p_bowman=bmin(p_soldier,p_bow);
   p_infantry=p_soldier-p_bowman;
   TASK_D->set_task(task_id,"def_bowman_left",p_bowman);
   TASK_D->set_task(task_id,"def_infantry_left",p_infantry);
   TASK_D->set_task(task_id,"def_cavalry_left",p_cavalry);
   TASK_D->set_task(task_id,"def_commando_left",p_commando);
   TASK_D->set_task(task_id,"def_arrange_troop",0);
   TASK_D->set_task(task_id,"def_arrange_step","newtroop");
   TASK_D->set_task(task_id,"def_curent_arrange_troop",([]));
   def_general=TASK_D->get_task(task_id,"def_party");
   def_leader=TASK_D->get_task(task_id,"def_leader");
   def_general-=({def_leader});
   return; */
//}

void train_collect(int task_id)
{
   string def_leader,def_area;
   string p_flyroom,p_short;
   string *def_party;
   string *def_general_left;
   object o_char;
   def_leader=TASK_D->get_task(task_id,"def_leader");
   o_char=CHAR_D->find_char(def_leader);
   def_area=TASK_D->get_task(task_id,"def_area");
   p_flyroom=AREA_D->get_area(def_area,"path")+
      AREA_D->get_area(def_area,"fly");
   p_short=load_object(p_flyroom)->short();
   if(objectp(o_char))
   { o_char->simple_action("$N道：诸位将军、大人，速到"+
      p_short+"点兵训练。\n");
      CHAR_D->put_char(def_leader,p_flyroom);
      o_char->simple_action("$N来到了"+p_short+"。\n");
      o_char->resign_job("train");
      o_char->add_job("train");
   }
   CHAR_D->put_char(def_leader,p_flyroom);
   def_party=TASK_D->get_task(task_id,"def_general_left");
   if(sizeof(def_party))
   foreach(string p_id in def_party)
   {
      o_char=CHAR_D->find_char(p_id);
      CHAR_D->put_char(p_id,p_flyroom);
      if(objectp(o_char))
      {
         o_char->simple_action("$N来到了"+p_short+"。\n");
      }
   }
}
