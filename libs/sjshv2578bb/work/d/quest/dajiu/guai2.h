void do_copy(object me) {
  int level;
  string family;
  object weapon;
  object env = environment(me);
  object killer = this_object();
  string target = me->query_temp("dajiu/id");

  level = NPC_D->get_skill_level(me);
  level = level + 100 + random(50);
  STATU_D->set_npc_skill(killer, level);
  NPC_D->set_npc_hp(killer, me, 200);

  if (me->query("combat_exp") < 20000000) {
    killer->set_temp("apply/damage", 25);
    killer->set_temp("apply/armor", 350);
  } else {
    killer->set_temp("apply/armor", 450);
    killer->set_temp("apply/damage", 40);
  }

  weapon = STATU_D->family_weapon(killer->query("family/family_name"));
  weapon->move(killer);
  weapon->wield();
  killer->set("owner", me);
  killer->move(env);
  message_vision(killer->query("name") + "突然跳了出来......\n", me);
  killer->command("grin " + target);
  killer->kill_ob(me);
  call_out("leave", random(100) + 600);
  me->set_temp("dajiu/kk", 1);
}

void die() {
  int i, j, k;
  string str;
  object me = owner();
  object guai = this_object();

  me->delete_temp("dajiu");
  me->add("dajiunpc", 1);
  me->clear_condition("baohu_job");
  me->apply_condition("job_busy", 5 + random(5));

  i = (int)me->query("dajiunpc");
  i = 8000 + random(100) + i / 2 + (i % 10) * 100;
  if (i > 2000) i = 2000;
  k = i / 5 + random(50);

  me->add("combat_exp", i);
  me->add("potential", k);

  guai->command("say 算你狠，咱们后会有期！\n");

  str = " dajiu npc got " + i + " exp " + k + " pot";
  tell_object(me, "你得到了"
    +chinese_number(i) + "点武学！"
    +chinese_number(k) + "点潜能的奖励！\n");

  MONITOR_D->mudring_log("baohu", me, str);

  leave();
}
