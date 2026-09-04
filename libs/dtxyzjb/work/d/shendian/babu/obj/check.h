//added by huarong 2003.10
void self_dest()
{
 
 object env=environment();

 remove_call_out("self_dest");
  if(env)
   {
     if(env->is_character())
      { 
       tell_object(env,"天上忽然传来一声断喝：还我"+this_object()->query("name")+"来！\n");
       tell_object(env,"只见"+this_object()->query("name")+"凌空而去，霎时间不见了踪影。\n");
       }
     else
       {
       tell_object(env,this_object()->query("name")+"钻进地里，霎时间不见了踪影。\n");
       }
    }

  log_file("nosave/shelizi_dest",sprintf("shelizi is destructed from %s on %s\n",env->is_character()?env->query("id"):env->query("short"),ctime(time())));
  destruct(this_object());
//  check_owner();
}

int ji (string target)
{
        object fabao = this_object ();
        object me = this_player();
        string name=fabao->query("name");
        object victim;
        object env=environment();
        if( me->query("combat_exp") > 1000000 || me->query("daoxing") > 1000000 ) 
           {
            tell_object(env,"天上忽然传来一声断喝：还我"+this_object()->query("name")+"来！\n");
            tell_object(env,"只见"+this_object()->query("name")+"凌空而去，霎时间不见了踪影。\n");
            destruct(this_object());
            return 1;
            }

        if (!target)
                return notify_fail("你想对谁祭"+name+"？\n");
        victim=present(target,environment(me));
        return fabao->ji_ob(victim);
}

void init()
{
   if(userp(environment())&&!query("dest_ready"))
      {
         set("dest_ready",1);
         call_out("self_dest",18000);
      }
        check_owner();
}


