

int valid_kill(object killer, object victim)
{    int pk_k, pk_v;   
 
if(userp(victim) &&time()-killer->query("TIME_PKS_TIME")<killer->query("TIME_PKS")*1800&&killer->query("pker")
       && userp(killer))
       return notify_fail("你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");

if(userp(victim)&&userp(killer)&&killer->query("pk_target_id")==victim->query("id")&&time()-killer->query("pk_target_id_time")<3600*12)
return notify_fail("你暂时不能连续杀同一个玩家！\n");
     return 1;
}

