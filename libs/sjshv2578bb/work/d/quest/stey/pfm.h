void check2() {
  object ob, me, *inv;
  int i, level;
  ob = this_object();
  me = query("owner");
  if (ob->query("question") == "done") me->set_temp("rulai_task", 1);
  else me->delete_temp("rulai_task");
  if (me->query("combat_exp") < 7000000) return;
  if (!living(me) && is_fighting(me)) return;
  level = random(3) + 1;
  if (!me->query("rulaitask")) return;
  if (me->query("kee") < 10 && me->query("sen") < 10) return;
  if (!present(me, environment())) {
    remove_call_out("check2");
    return;
  }

  if (random(100) > 90) command("bian " + me->query("id"));
  if (ob->query("question") == "done") me->set_temp("rulai_task", 1);
  else me->delete_temp("rulai_task");
  switch (random(6)) {
    case 0:
      {
        message_vision(YEL "$N念出一句妖咒，“魔界血箭”，一道血光向$n射来！\n", ob, me);


        if (random(4) == 0) {
          message_vision(HIM "$N被血箭刺中心脏,受到严重伤害！\n" NOR, me);
          me->receive_damage("kee", query("max_kee") / 55, ob);
          me->receive_wound("kee", query("max_sen") / 55, ob);
          me->receive_damage("sen", query("max_kee") / 55, ob);
          me->receive_wound("sen", query("max_sen") / 55, ob);
        } else
          message_vision(YEL "$N急忙往后一跳，及时躲过这道血箭！\n" NOR, me);
      }
      break;

    case 1:
      {
        message_vision(YEL "$N念起招魂咒，顿时万只魔界鬼魂张开大口向$n冲来！\n", ob, me);
        if (random(4) == 0) {
          message_vision(HIR "$N的手手脚脚被魔界鬼魂吞噬了，受到极其恐怖的伤害！\n" NOR, me);
          me->receive_damage("kee", level * query("max_kee") / 25, ob);
          me->receive_wound("kee", level * query("max_sen") / 55, ob);
          me->receive_damage("sen", level * query("max_kee") / 25, ob);
          me->receive_wound("sen", level * query("max_sen") / 25, ob);
        } else
          message_vision(YEL "$N念起法力向前一挥，及时躲过这个劫难！\n" NOR, me);
      }
      break;

    case 2:
      {
        message_vision(HIR "$N手中突然发出一个血红色的火球，火球立即向$n飞过去。\n", ob, me);
        if (random(4) == 3) {
          message_vision(HIR "$N难以及时躲避，被扑面而来的火球打个正着！\n" NOR, me);
          me->receive_damage("kee", 2 * query("max_kee") / 55, ob);
          me->receive_wound("kee", 2 * query("max_sen") / 55, ob);
          me->receive_damage("sen", 2 * query("max_kee") / 55, ob);
          me->receive_wound("sen", 2 * query("max_sen") / 55, ob);
          /*
                        if(random(40)>36)
                        {
                                inv = all_inventory(me);
                                for(i=0; i<sizeof(inv); i++) 
                                {
                                        if(random(4)==1 && inv[i]->query("id") !="saiya zhanyi")
                                        {
                                                message_vision(HIW"$n被火球烧为红烟！\n"NOR,me,inv[i]);
                                                destruct(inv[i]);
                                        }
                                }
                        }
*/
        } else
          message_vision(HIR "$N及时手指一拨，用法力把$n的火球拨开了！\n" NOR, me, ob);
      }
      break;


  }
  if (random(8) == 5 && ob->query("eff_kee") < ob->query("max_kee")) {
    set("eff_kee", query("max_kee"));
    set("eff_sen", query("max_sen"));
    set("kee", query("max_kee"));
    set("sen", query("max_sen"));
    set("force", query("max_force"));
    set("mana", query("max_mana"));
  }
  /*
        if(!ob->query("protect")|| ob->query("kee")< ob->query("max_kee")/5 )
        {

        }
*/
  remove_call_out("check2");

}
