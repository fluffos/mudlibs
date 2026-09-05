//  auto_fight()
//
//  This function is to start an automatically fight. Currently this is
//  used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
  // Don't let NPC autofight NPC.
  if( !userp(me) && !userp(obj) ) return;
  
  // Because most of the cases that we cannot start a fight cannot be checked
  // before we really call the kill_ob(), so we just make sure we have no
  // aggressive callout wating here.
  if( me->query_temp("looking_for_trouble") ) return;
  me->set_temp("looking_for_trouble", 1);
  
  // This call_out gives victim a chance to slip trough the fierce guys.
  call_out( "start_" + type, 0, me, obj);
}

protected void start_berserk(object me, object obj)
{
  int shen;
  
  if( !me || !obj ) return;        // Are we still exist( not becoming a corpse )?
  
  me->set_temp("looking_for_trouble", 0);
  
  if(  me->is_fighting(obj)        // Are we busy fighting?
    ||  !living(me)              // Are we capable for a fight?
    ||  environment(me)!=environment(obj)  // Are we still in the same room?
    ||  environment(me)->query("no_fight")   // Are we in a peace room?
    )  return;
  
  shen = 0 - (int)me->query("shen");
  message_vision("$N用一种异样的眼神扫视著在场的每一个人。\n", me);
  
  if( !userp(me) || (int)me->query("neili") > (random(shen) + shen)/10 ) return;
  
  if( shen > (int)me->query("score")
    &&  !wizardp(obj) ) {
    message_vision("$N对著$n喝道：" + RANK_D->query_self_rude(me)
      + "看你实在很不顺眼，去死吧。\n", me, obj);
    me->kill_ob(obj);
  } else {
    message_vision("$N对著$n喝道：喂！" + RANK_D->query_rude(obj)
      + "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n",
      me, obj);
    me->fight_ob(obj);
  }
}

protected void start_hatred(object me, object obj)
{
  if( !me || !obj ) return;        // Are we still exist( not becoming a corpse )?
  
  me->set_temp("looking_for_trouble", 0);
  
  if(  me->is_fighting(obj)        // Are we busy fighting?
    ||  !living(me)              // Are we capable for a fight?
    ||  environment(me)!=environment(obj)  // Are we still in the same room?
    ||  environment(me)->query("no_fight")   // Are we in a peace room?
    )  return;
  
  // We found our hatred! Charge!
  message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
  me->kill_ob(obj);
}

protected void start_vendetta(object me, object obj)
{
  if( !me || !obj ) return;        // Are we still exist( not becoming a corpse )?
  
  me->set_temp("looking_for_trouble", 0);
  
  if(  me->is_fighting(obj)        // Are we busy fighting?
    ||  !living(me)              // Are we capable for a fight?
    ||  environment(me)!=environment(obj)  // Are we still in the same room?
    ||  environment(me)->query("no_fight")   // Are we in a peace room?
    )  return;
  
  // We found our vendetta opponent! Charge!
  me->kill_ob(obj);
}

protected void start_aggressive(object me, object obj)
{
  if( !me || !obj ) return;        // Are we still exist( not becoming a corpse )?
  
  me->set_temp("looking_for_trouble", 0);
  
  if(  me->is_fighting(obj)        // Are we busy fighting?
    ||  !living(me)              // Are we capable for a fight?
    ||  environment(me)!=environment(obj)  // Are we still in the same room?
    ||  environment(me)->query("no_fight")   // Are we in a peace room?
    )  return;
  
  // We got a nice victim! Kill him/her/it!!!
  me->kill_ob(obj);
}