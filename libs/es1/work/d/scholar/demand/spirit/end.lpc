void summon_delay(object me)
{
  me->delete_temp("summon_rest");
}

void can_summon_again(object me,int delay)
{
        call_out("summon_delay",random(delay),me);
        return;
}

int bye_bye(object master,object spirit,int level,string str1,string str2,string str3)
{
    spirit->init_attack();
    spirit->cease_all_attacks();
    tell_object(master,set_color(str1,str3));
    tell_room(environment(),set_color(str2,str3,master),master);
    if ( !wizardp(master) ) 
      call_out("summon_delay",random(level),master);	
    else
      master->delete_temp("summon_rest");	
    spirit->remove();
    return 1;
}
