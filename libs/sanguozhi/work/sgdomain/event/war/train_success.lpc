// train_success.c by fire on Dec 1998
void def_arrange_left(int task_id);
#include <train.h>
void question_fail(int task_id)
{
   string p_leader;
   p_leader=TASK_D->get_task(task_id,"def_leader");
   tell_user(p_leader,"%^H_YELLOW%^你已经不在战场了，训练任务失败。\n");
   TASK_D->set_task(task_id,"result","fail");
   return;
}
void question_success(int task_id)
{
   string p_leader;
   int *ts;
   TASK_D->set_task(task_id,"successtimes",
     TASK_D->get_task(task_id,"successtimes")+1);
   p_leader=TASK_D->get_task(task_id,"def_leader");
   tell_user(p_leader,
"%^H_GREEN%^恭喜你完成一项训练任务，请准备下一项训练任务吧。%^RESET%^\n");
   ts=TASK_D->get_task(task_id,"def_army");
   TROOP_D->add_train(ts, 1);
   TROOP_D->add_morale(ts, 1);

}
void question_wrong(int task_id)
{
   string p_leader;
   p_leader=TASK_D->get_task(task_id,"def_leader");
   tell_user(p_leader,
  "%^YELLOW%^训练系统有BUG，赶快汇报，不然损失自负。%^RESET%^\n");
}
void question_overdue(int task_id)
{
   string question;
   string p_id;
   int *ts;

   TASK_D->set_task(task_id,"overduetimes",
     TASK_D->get_task(task_id,"overduetimes")+1);
   p_id=TASK_D->get_task(task_id,"def_leader");
tell_user(p_id,
  "%^H_RED%^上一项训练任务超时，但愿下一项能完成得快些。%^RESET%^\n");

   ts=TASK_D->get_task(task_id,"def_army");
//   TROOP_D->add_morale(ts, 1);

   question=TASK_D->get_task(task_id,"question");
   switch(question)
   {
      case "arrange":
        def_arrange_left(task_id);
        break;
     case "question":
       quit_question(task_id);
      break;
   }
}
