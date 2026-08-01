// poison_bugs.h
// 用于各种毒虫: scorpins, scolopendra, toad, snake, spider
// 需要在引用的npc/毒虫里加 poison = 毒, poison_amout = 毒量, die_ob = 死后变成什么.
int init() {
  object me, who;
  ::init();
  who = this_object();
  if (interactive(me = this_player())) {
    if (me->query("id") == who->query_temp("kill_name")) {
      remove_call_out("kill_ob");
      call_out("kill_ob", 1, me);
    }
  }
  add_action("do_attack", "attack");
  add_action("do_stop", "stop");
  add_action("do_send", "sendto");
  add_action("do_sha", "sha");
  add_action("do_guard", "guard");
  add_action("do_hit", "hit");
  add_action("do_hit", "kill");
  add_action("do_hit", "touxi");
}



int do_attack(string arg) {
  object ob;

  object me = this_player();
  object who = this_object();

  if (me->query("id") != (who->query("host_id")))
    return notify_fail(who->query("name") + "连理都不理你！\n");
  if (!arg || !objectp(ob = present(arg, environment(me))))
    return notify_fail(who->query("name") + "傻傻地望着你，不明白你的意思。\n");
  if (ob->query("id") == me->query("id"))
    return notify_fail(who->query("name") + "急忙把头一低，似乎不愿意去干。\n");
  if (!living(ob))
    return notify_fail(who->query("name") + "说:"
      +ob->query("name") + "已经这样啦你还要...??!!\n");
  message_vision(who->query("name") + "吱吱怪叫一声冲了出去.\n", me);
  fight_ob(ob);
  return 1;
}

int do_stop() {
  object who = this_object();

  object me = this_player();
  if (me->query("id") != (who->query("host_id")))
    return notify_fail(who->query("name") + "连理都不理你！\n");
  who->set_leader(me);
  message_vision("$N对" + who->query("name") + "喝道：别打了，跟我来。\n", me);
  command("halt");
  who->delete_temp("kill_name");
  message_vision(who->query("name") + "乖乖的回到$N身边。\n", me);
  return 1;
}

int do_sha(string arg) {
  object who = this_object();
  object me, ob;

  me = this_player();
  if (me->query("id") != (who->query("host_id")))
    return notify_fail(who->query("name") + "连理都不理你！\n");
  if (!arg || !objectp(ob = present(arg, environment(me))))
    return notify_fail("你要" + who->query("name") + "杀谁？\n");
  if (ob->query("id") == me->query("id"))
    return notify_fail(who->query("name") + "急忙把头一低，似乎不愿意去干。\n");
  if (!ob->is_character() || ob->is_corpse())
    return notify_fail("看清楚一点，那并不是活物。\n");
  if (!environment(ob)->query("no_fight")) {
    message_vision(who->query("name") + "吱吱怪叫一声冲了出去.\n", me);
    command("say 嘿嘿,你认命吧，主人要我杀了你!");
    who->set_leader(ob);
    who->set_temp("kill_name", ob->query("id"));
    remove_call_out("kill_ob");
    call_out("kill_ob", 0, ob);
  }
  return 1;
}

int hit_ob(object me, object ob, int damage) {
  if ((string)ob->query("family/family_name") != "五毒教") {
    ob->apply_condition(query("poison"), query("poison_amount")
      +(int)ob->query_condition(query("poison")));
    tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR);
  }
}

void die() {
  object ob;
  message_vision("$N倒在地上，死了！\n", this_object());
  ob = new(__DIR__ "obj/" + query("die_ob"));
  ob->move(environment(this_object()));
  destruct(this_object());

  //      return 1;
  //	::die();
}

int do_guard(string arg)            //160
{
  object who = this_object();
  int i;
  object me, ob;
  object *enemy;
  me = this_player();
  if (me->query("id") != (who->query("host_id")))
    return notify_fail(who->query("name") + "连理都不理你！\n");
  if (!arg)
    ob = this_player();
  if (arg) {
    if (!userp(present(arg, environment(me))))
      return notify_fail("你要" + who->query("name") + "保护谁？\n");
  }
  if (arg)
    ob = present(arg, environment(me));
  who->set_temp("guard_ob", ob->query("id"));
  message("vision",
    name() + "发出轻微的吱叫声，开始绕着" + ob->name() + "四处游走！\n" NOR, environment(), this_object());
  enemy = ob->query_enemy();
  i = sizeof(enemy);
  while (i--) {
    if (enemy[i] && living(enemy[i])) {
      kill_ob(enemy[i]);
      if (userp(enemy[i])) enemy[i]->fight_ob(this_object());
      else enemy[i]->kill_ob(this_object());
    }
  }
  ob->remove_all_killer();
  who->set_leader(ob);
  return 1;
}
int do_hit(string arg) {
  object ob = this_object();
  object me = this_player();

  if (!arg) return 0;
  if (arg != ob->query_temp("guard_ob")) return 0;
  message_vision("$N一声怪叫忽然挡在了" + me->name() + "的面前。\n", this_object());
  remove_call_out("kill_ob");
  call_out("kill_ob", 0, me);
  return 1;
}
