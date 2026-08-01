void init() {
  object me;

  me = this_player();
  if (!userp(me)) return;
  if (!wizardp(me) && !me->query_temp("leitai")) {
    message_vision("比武擂台现场直播员一脚将$N从擂台给踢了出去！\n", me);
    me->move("/d/city/chmiao");
    message_vision("“啊。。。”的一声，$N被人从擂台给踢了出来。\n", me);
  }
  if (userp(me)) message_vision("$N急急忙忙地走进了擂台。\n", me);

  add_action("do_load", "login");
  add_action("do_full", "full");
  add_action("do_pk", "biwu");
  add_action("do_tui", "tui");
  add_action("do_leave", "leave");
  add_action("do_ok", "ok");
  add_action("do_action", ({ "dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
    "kill", "fight", "study", "practice", "exercise", "halt",
    "quit", "save", "throw" }));
}

int do_action(string arg) {
  write("擂台上只能比武，请不要做不相关的事！\n");
  return 1;
}

int do_pk(string str) {
  object ob1, ob2;
  string st1, st2;

  if (!str) return notify_fail("[topless]: 你想让谁和谁比武啊？\n");
  if (sscanf(str, "%s with %s", st1, st2) != 2)
    return notify_fail("biwu <player1> with <player2>\n");

  if (!ob1 = present(st1, this_object()))
    return notify_fail("找不到 " + st1 + " 这个生物。\n");

  if (!ob2 = present(st2, this_object()))
    return notify_fail("找不到 " + st2 + " 这个生物。\n");
  if (ob1 == ob2)
    return notify_fail("让他自己打自己？\n");
  if (!ob1->query_temp("leitai"))
    return notify_fail(ob1->name() + "不是通过正当途径进入擂台，不能参加比武。\n");
  if (!ob2->query_temp("leitai"))
    return notify_fail(ob2->name() + "不是通过正当途径进入擂台，不能参加比武。\n");
  if (ob1->query_temp("leitai") < 2)
    return notify_fail(ob1->name() + "还没准备好(ok)，请稍等片刻。\n");
  if (ob2->query_temp("leitai") < 2)
    return notify_fail(ob2->name() + "还没准备好(ok)，请稍等片刻。\n");
  if (wiz_level(this_player()) < 3)
    return notify_fail("只有 (wizard) 以上的巫师才能组织擂台比武！\n");

  message("leitai", HIY + "\n【" + this_object()->query("short") + "擂台】：各位江湖同道！\n"
    NOR + ob1->short(1) + HIY " 与\n"
    NOR + ob2->short(1) + HIY " 比武正式开始！\n\n" NOR, users());

  message_vision(HIR "只听一声锣响，$N和$n比武正式开始！\n" NOR, ob1, ob2);
  ob2->kill_ob(ob1);
  ob1->kill_ob(ob2);
  remove_call_out("observe");
  call_out("observe", 1, ob1, ob2);
  return 1;
}

int do_ok() {
  object me = this_player();

  if (!me->query_temp("leitai"))
    return notify_fail("此命令只有上台比武的选手可用。\n");

  if (me->query_temp("leitai") == 2)
    return notify_fail("你已经出言挑战了。\n");

  message_vision(YEL "$N做了个鞠：" + RANK_D->query_self(me) + "已经准备好了，愿接受任何挑战！\n" NOR, me);
  me->set_temp("leitai", 2);
  return 1;
}

void do_back(object ob) {
  object link_ob;

  if (!ob) return;
  link_ob = ob->query_temp("link_ob");
  ob->delete_temp("leitai");
  message_vision("$N退出擂台。\n", ob);
  if (link_ob) {
    exec(link_ob, ob);
    link_ob->setup();
    destruct(ob);
  } else ob->move("/d/city/chmiao");
}

object offensive_target(object me) {
  int sz;
  object *enemy;

  enemy = me->query_enemy();
  if (!enemy || !arrayp(enemy)) return 0;

  sz = sizeof(enemy);
  if (sz > 4) sz = 4;

  if (sz > 0) return enemy[random(sz)];
  else return 0;
}

int do_leave() {
  object ob, me;

  me = this_player();

  if (!me->query_temp("leitai"))
    return notify_fail("此命令只有上台比武的选手可用。\n");

  message_vision(HIW "\n$N深叹了一口气：" + RANK_D->query_self(me) + "技不如人，情愿认输！\n\n" NOR, me);
  if (ob = offensive_target(me)) {
    message("leitai", HIY + "\n【" + this_object()->query("short") + "擂台】比武已经决出胜负！\n"
      NOR + me->short(1) + HIY " 自动弃权，\n"
      NOR + ob->short(1) + HIY " 获胜！\n\n" NOR, users());
    log_file(
      "leitai",
      sprintf("%s(%s) 于擂台上击败 %s(%s)。", me->name(1), getuid(me), ob->name(1), getuid(ob))
    );
    do_back(me);
    do_back(ob);
  } else do_back(me);
  return 1;
}
void observe(object ob1, object ob2) {

  if (!ob1 && !ob2) return;

  else if (!ob1 && objectp(ob2)) {
    message("leitai", HIY + "\n【" + this_object()->query("short") + "擂台】比武暂时中断！\n\n", users());
    do_back(ob2);
    return;
  } else if (!ob2 && objectp(ob1)) {
    message("leitai", HIY + "\n【" + this_object()->query("short") + "擂台】比武暂时中断！\n\n", users());
    do_back(ob1);
    return;
  } else if (ob1->is_ghost()) {
    message("leitai", HIY + "\n【" + this_object()->query("short") + "擂台】比武已经决出胜负！\n"
      NOR + ob1->short(1) + HIY " 被\n"
      NOR + ob2->short(1) + HIY " 击败！\n\n" NOR, users());
    log_file(
      "leitai",
      sprintf("%s(%s) 于擂台上击败 %s(%s)。", ob2->name(1), getuid(ob2), ob1->name(1), getuid(ob1))
    );
    do_back(ob1);
    do_back(ob2);
    return;
  } else if (ob2->is_ghost()) {
    message("leitai", HIY + "\n【" + this_object()->query("short") + "擂台】比武已经决出胜负！\n"
      NOR + ob2->short(1) + HIY " 被\n"
      NOR + ob1->short(1) + HIY " 击败！\n\n" NOR, users());
    log_file(
      "leitai",
      sprintf("%s(%s) 于擂台上击败 %s(%s)。", ob1->name(1), getuid(ob1), ob2->name(1), getuid(ob2))
    );
    do_back(ob1);
    do_back(ob2);
    return;
  } else if (ob1->is_killing(ob2->query("id"))
    && ob2->is_killing(ob1->query("id"))) {
    call_out("observe", 1, ob1, ob2);
    return;
  }
  return;
}

int do_tui(string arg) {
  object ob;

  if (!arg) return notify_fail("你要推谁？\n");
  if (!ob = present(arg, this_object()))
    return notify_fail("找不到 " + arg + " 这个生物。\n");
  if (!ob->query_temp("leitai"))
    return notify_fail(ob->name() + "不是通过正当途径进入擂台，不能被推出擂台。\n");
  if (wiz_level(this_player()) < 3)
    return notify_fail("只有 (wizard) 以上的巫师才能将人推出擂台！\n");

  message_vision("$N耍了个太极，将$n一把推出了擂台。\n", this_player(), ob);
  do_back(ob);
  return 1;
}

int do_full(string str) {
  object me;

  if (!str) return notify_fail("你要恢复哪个玩家的状态？\n");
  if (wiz_level(this_player()) < 3)
    return notify_fail("只有 (wizard) 以上的巫师才能恢复玩家状态！\n");

  if (!geteuid()) seteuid(getuid());
  me = present(lower_case(str), environment(this_player()));
  if (!me) return notify_fail("对不起，这里没有 " + str + " 这个人。\n");
  me->reincarnate();
  me->clear_condition();
  message_vision(HIW "$N的状态恢复完毕。\n" NOR, me);
  return 1;
}

int do_load(string arg) {
  object me, user, ob;
  string arg1, arg2;

  if (!arg) return 0;
  if (sscanf(arg, "%s with %s", arg1, arg2) != 2)
    return notify_fail("命令格式: login <player name1> with <player name2>。\n");

  me = this_player();
  if (wiz_level(me) < 3)
    return notify_fail("只有 (wizard) 以上的巫师才能在擂台login其他player。\n");
  if (wiz_level(me) < wiz_level(arg1))
    return notify_fail("你不能装载巫师级别比你高的玩家。\n");

  ob = find_player(arg2);
  if (!ob) return notify_fail("让谁为代表进入擂台？\n");
  if (ob->query_temp("leitai"))
    return notify_fail(ob->name() + "正在别的擂台比武中。\n");

  seteuid(arg1);
  user = new("/clone/user/leitaiuser");   // 去掉了save()，擂台中的一切和本身无关。
  export_uid(user);
  user->set_name("", ({ arg1 }));
  if (!user->restore()) {
    destruct(user);
    return notify_fail("你想让哪个玩家的拷贝进入擂台？\n"); ;
  }
  if (!environment(ob)->query("no_fight"))
    ob->move("/d/city/chmiao");  // 防止比武时本身被杀
    user->setup();
  user->set_temp("leitai", 1);
  exec(user, ob);
  user->set_temp("link_ob", ob);
  user->move(this_object());
  user->clear_condition();
  user->reincarnate();
  tell_object(user, YEL "你代表" + user->name() + "进入擂台，目前处于最佳状态中。\n" NOR "
需要兵器请从物品架上拿 " YEL "NA" NOR " 。
如果你准备好了请打" YEL " OK " NOR "。
如果你要放弃比赛，请打" YEL " LEAVE " NOR "。\n\n");
  tell_room(
    environment(user),
    YEL + ob->query("name") + "代表" + user->name() + "进入比武擂台。\n\n" NOR,
    ({ user })
  );
  return 1;
}
