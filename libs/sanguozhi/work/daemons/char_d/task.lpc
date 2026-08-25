// task.c
// by fire on Dec 1998
string get_taskstr(string p_id)
{
   int p_task;
   p_task=CHAR_D->get_char(p_id,"task");
  switch(p_task)
  {
    case TASK_NONE: return ("正常");
    case TASK_MEETING: return ("会议");
    case TASK_WAR: return("战争");
   case TASK_TRAIN: return("练兵");
   default: return ("未知");
  }
}
int get_task(string p_id)
{
        mixed task;
        int ret;
        task=TASK_D->get_char_task(p_id);
        switch(task[1])
        {case 0: return TASK_NONE;
         case TT_LOCALMEETING: return TASK_MEETING;
         case TT_WAR: return TASK_WAR;
        case TT_TRAIN: return TASK_TRAIN;
         default: return TASK_UNKNOW;
        }
}
