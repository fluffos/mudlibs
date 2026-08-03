void set_my_killer_list(object killer, object victim);

int valid_kill(object killer, object victim, int no_list)
{    
    if(userp(victim)&&userp(killer)&&!wizardp(killer)&&(!killer->query_temp("pkgame"))&&(!victim->query_temp("pkgame")))
    {
	if( victim->query_level()<30 )
		return notify_fail("不能对小于30级的玩家进行攻击。\n");
	if( killer->query_level()<30 )
        	return notify_fail("30级之前不能PK。\n");
	if( killer->query("PKS")>killer->query("MKS")/500 )
		return notify_fail("你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");
     	if(killer->query_condition("no_pk_time"))
        	return notify_fail("你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");
     	if(!killer->query("env/PK"))
        	return notify_fail("你已经设定了不对Player下kill命令,\n如果确实有深仇大恨,请用unset PK解除!\n");
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
                 return;
             }
         }
         list=victim->query_temp("my_killer_list");
         kill=killer->query("id");
         if(!list) list=({kill});
         else if(member_array(kill, list)==-1)
             list+=({kill});
         if(sizeof(list)>100)
             list=list[1..<1]; 
         victim->set_temp("my_killer_list", list);
}
