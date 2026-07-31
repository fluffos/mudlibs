// added by snowcat

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/jingjiling") == "done")
    return;
  if (! who->query_temp("obstacle/jingjiling/guzhi gong"))
    return;
  if (! who->query_temp("obstacle/jingjiling/lingkong zi"))
    return;
  if (! who->query_temp("obstacle/jingjiling/shiba gong"))
    return;
  if (! who->query_temp("obstacle/jingjiling/fuyun sou"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/jingjiling","done");
  who->add("combat_exp",i+33000);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"荆棘岭斗智斗武，力挫众仙！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(i+33000)+"点经验"+
               chinese_number(i*8)+"点潜能"+" 十点门派贡献 二点成长上限！！\n");
  who->save();
}

void player_win (object me, object who)
{
  object obj;
  
  who->set_temp("obstacle/jingjiling/"+me->query("id"),1);
  message_vision("$N对$n一鞠躬：不错，不错！\n",me,who);  
  me->announce_success(who);
}

void player_lose (object me, object who)
{
  message_vision("$N对$n一挥手：去吧，去吧！\n",me,who);
}

void check_fight (object who)
{
  object me = this_object();
  int my_kee, whos_kee;
  int my_max_kee, whos_max_kee;

  my_kee = me->query("qi");
  whos_kee = who->query("qi");
  my_max_kee = me->query("max_qi");
  whos_max_kee = who->query("max_qi");

  if (me->is_fighting()){
    remove_call_out("check_fight");
    call_out ("check_fight",1,who);
    return;
  }

  if (!present(who, environment(me)))
    return;

  if ((my_kee*100/my_max_kee) <= 50)
    player_win (me, who);
  else if ((whos_kee*100/whos_max_kee) <= 50)
    player_lose (me, who);
}

void reset_me ()
{
  object me = this_object();
  me->set("eff_qi", (int)me->query("max_qi"));
  me->set("qi", (int)me->query("max_qi"));
  me->set("eff_jing", (int)me->query("max_jing"));
  me->set("jing", (int)me->query("max_jing"));
}

