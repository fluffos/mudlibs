//modified by vikee for XLQY
//2001-2-9 20:07

void set_my_killer_list(object killer, object victim);

int valid_kill(object killer, object victim, int no_list)
{    
    if (userp(killer) && !query_heart_beat(killer))
    {
        return notify_fail("由于你没有心跳，请重新登陆!!\n");
    }
/*
    if ((killer->query("nopk") || victim->query("nopk"))
        && userp(victim))
        return notify_fail(HIR"nopk商议中，住手！\n"NOR);
*/
         if(environment(killer)->query("hellfireroom") && (killer->query_temp("position/xx")!=victim->query_temp("position/xx") ||  killer->query_temp("position/yy")!=victim->query_temp("position/yy")) )
              return notify_fail("你不在"+victim->name()+"方位面前,怎么打？\n");
     if(userp(victim) && userp(killer)) {
         if ((int)killer->query_condition("no_pk_time")>600) 
            return notify_fail(
                    "你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");
         if ((killer->query("combat_exp")+killer->query("daoxing"))
                 <5000) 
             return notify_fail(
                     "你自己功夫还没练好，就想要杀人？\n");
         if(!no_list) 
             set_my_killer_list(killer, victim);
     }
           
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
        killer->delete_temp("is_killer");//清楚上次记录。
        killer->set_temp("is_killer/flag",1);//建立新记录
        enemy = target->query("id");//记录敌人名字。
        killer->set_temp("is_killer/enemy_id",enemy);
}


