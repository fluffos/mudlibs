/* <SecCrypt CPL V3R05> */
 

int valid_kill(object killer, object victim)
{    int pk_k, pk_v;   
 
     if(userp(victim) && killer->query_condition("no_pk_time")>240 
       && userp(killer))
       return notify_fail("你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");

     return 1;
}

