//by yekai
int valid_kill(object killer, object victim, int no_list)
{
  int your_idle, my_exp, your_exp;

  if(playerp(victim) && playerp(killer))
  {
    if( uptime()-killer->query_temp("last_kill_time")<2)
      return notify_fail("为了系统负担请勿进行刷屏kill,你的kill指令时间必须大于2秒钟。\n");

    if (killer->query("age")<18 )
      return notify_fail("你小小年纪，就想要杀人？\n");
    if (victim->query("age")<18)
      return notify_fail("为了明天的世界更美好，放过新手吧!\n");

    your_idle = (int)victim->query_idle();
    my_exp = (int)killer->query("combat_exp")/3 ;
    my_exp += (int)killer->query("daoxing")/3*2 ;
    your_exp = (int)victim->query("combat_exp")/3 ;
    your_exp += (int)victim->query("daoxing")/3*2 ;
    if(my_exp<(your_exp/8) )
      return notify_fail(sprintf("你不是%s的对手，不要白白去送死了。\n",victim->name()));
    my_exp /= 8;
    if( my_exp > your_exp )
    {
      tell_object(victim,"一种杀气笼罩了你的全身。。。\n");
      return notify_fail(sprintf("你看了看%s，觉得他不是对手！"
                                 "算了吧，得饶人处且绕人！\n",victim->name()));
    }
    if( your_idle > 600 && !victim->is_fighting()
      && !environment(victim)->query("fight_room"))
    {
      write("你想对"+victim->query("name")+"下杀手，但是看着他那呆若木鸡的样子，你始终狠不下心来。\n");
      tell_object(victim,"一种不详的感觉笼罩着你全身。。。\n");
      tell_object(victim,killer->query("name")+"("+killer->query("id")+")"+"想对你下毒手，还在考虑中，你还是快逃吧！\n");
      killer->start_busy(2);
      return 0;
    }

    if( victim->query("doing") )
      return notify_fail("对正在离线练功的玩家下手，似乎不是什么英雄好汉吧？\n");
    if(killer==victim)
      return notify_fail("用 suicide -f 指令会比较快些。\n");

    if( victim->is_brother(killer))
      return notify_fail("你要杀你的结义金兰？！\n");

    log_file( "kill_log", sprintf("(%s)%s(%s) tried to kill %s(%s)\n",
        log_time(), killer->query("name"),
        killer->query("id"), victim->query("name"),victim->query("id")));
  }

  else if( !userp(victim) && victim->query("no_kill"))
    return notify_fail("你不能攻击这个人！\n");
  return 1;
}

