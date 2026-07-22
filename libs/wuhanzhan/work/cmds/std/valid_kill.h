// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by mon

  void set_my_killer_list(object killer, object victim);
int valid_kill(object killer, object victim)
{    int pk_k, pk_v;   
 
     if(userp(victim) && killer->query_condition("no_pk_time")>240 
       && userp(killer))
       return notify_fail("你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");

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
  
  int set_to_killer(object killer,object target)
  {
          string enemy;   
          killer->delete_temp("is_killer");//^G^E^S^^^I^O^T^N^\^G^B^\^A^C
          killer->set_temp("is_killer/flag",1);//^]^H^A^B^P^B^\^G^B^\
          enemy = target->query("id");//^\^G^B^\^U^P^H^K^C^[^W^V^A^C
          killer->set_temp("is_killer/enemy_id",enemy);
  }

