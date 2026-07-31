// by mon

int valid_kill(object killer, object victim)
{    int pk_k, pk_v;   

     if(userp(victim) && killer->query_condition("no_pk_time")>480 
       && userp(killer))
       return notify_fail("你最近杀人太多，此时忽然觉得下不去手．．．\n");

     return 1;
/*
     pk_k=killer->query("combat_exp");
     pk_v=victim->query("combat_exp");

     if(pk_k>pk_v*20 && userp(victim) && userp(killer))  return notify_fail(
       "欺负手无缚鸡之力的弱者，你不害臊吗！？\n");
       
     return 1; //mon 8/11/97, remove limitation on pk group.

     if(!userp(victim) || !userp(killer)) return 1;

     if(pk_k && !pk_v) return notify_fail(
       "你只能杀死(who -k)所显示的玩家。\n");

     if(!pk_k && pk_v) return notify_fail(
       "你需要得到二郎真君同意才能杀死这名玩家。\n");

     if(!pk_k && !pk_v &&
         (victim->query("combat_exp") < 1000 && 
          victim->query("age")<15)) return notify_fail(
	   "欺负手无缚鸡之力的弱者，你不害臊吗！？\n"); 

     return 1;
*/
}

