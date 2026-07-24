void set_my_killer_list(object killer, object victim);

int valid_kill(object killer, object victim, int no_list)
{    
     if(userp(victim) && userp(killer)) {
         if ((int)killer->query_condition("no_pk_time")>480) 
            return notify_fail(
                    "你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");
   
         if ((killer->query("combat_exp")+killer->query("daoxing"))
                 <5000) 
             return notify_fail(
                     "你自己功夫还没练好，就想要杀人？\n");
      if ((int)victim->query("cantpk"))
           return notify_fail("对方受菩萨保佑，你不能奈何于他。\n");  
  if ((int)killer->query("cantpk"))
            return notify_fail("你正在归依菩萨中，切勿杀生。\n");    
         if(!no_list) 
             set_my_killer_list(killer, victim);
     }
      if ((int)killer->query("no_kill"))
            return notify_fail("你正在归依我佛中，切勿杀生。\n");

         if ((int)victim->query("no_kill"))
            return notify_fail("对方受佛祖保佑，你不能奈何于他。\n");           
     return 1;
}

void set_my_killer_list(object killer, object victim)
{
     string *list, *listk;
     string kill;

         listk=killer->query_temp("my_killer_list");
         if(listk && arrayp(listk)) {
             if(member_array(victim->query("id"),listk)!=-1) {
                 // the victim issued kill on the killer first.
                 // so not mark the killer. mon 10/24/98
                 return;
             }
         }

         // this list contains all the players initiaite killing
         // to the victim.  -mon 8/4/98
         list=victim->query_temp("my_killer_list");
         kill=killer->query("id");
         if(!list) list=({kill});
         else if(member_array(kill, list)==-1)
             list+=({kill});
         if(sizeof(list)>100)
             list=list[1..<1]; // remove the first element.
         victim->set_temp("my_killer_list", list);
}


