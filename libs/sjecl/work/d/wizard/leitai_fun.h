// leitai_fun.h
// modified by augx@sj  10/29/2001

string look_leitai() {
  object me, room;

  me = this_player();
  if (me->is_busy()) return "你正忙着呢。\n";
  me->start_busy(2);

  room = load_object(query("leitai"));
  if (!room)
    return "比武擂台没有准备好，请通知巫师。\n";
  message_vision("$N挤到擂台边，伸长了脖子向上望去。\n", me);
  "/cmds/std/look.lpc"->look_room(me, room);

  return "";
}

int valid_leave(object me, string dir) {
  object room;
  int i;

  if (dir != "out" && !wizardp(me)) {
    room = load_object(query("exits/" + dir));

    i = room->query_temp("num");
    if (i > 15) {
      me->start_busy(1);
      return notify_fail(room->query("short") + "已经人满为患，你挤不进去！\n");
    }
  }

  if (userp(me) && !wizardp(me))
    add_temp("num", -1);
  return ::valid_leave(me, dir);
}

int do_action(string arg) {
  object me = this_player();

  if (me->is_busy())
    return 1;
  me->start_busy(2);
  write("\n你正要有所动作，突然身旁有人将你一拍：好好看比武，别乱动！\n");
  return 1;
}

int do_biwu() {
  object me, ob;
  mapping mp;

  me = this_player();

  if (me->query("combat_exp") < 100000)
    return notify_fail("要想上台比武，你的资格还差了些，先去练练吧。\n");
  if (mapp(mp = me->query_conditions_by_type("poison")) && sizeof(mp) > 0)
    return notify_fail("你还是先治好你的病再来比武吧。\n");
  if (mapp(mp = me->query_conditions_by_type("killer")) && sizeof(mp) > 0)
    return notify_fail("你还是先解决了你的个人恩怨再来比武吧。\n");

  if (!(ob = find_object(query("leitai"))))
    ob = load_object(query("leitai"));
  if (!ob)
    return notify_fail("比武擂台没有准备好，请通知巫师。\n");
  if (ob->query_temp("leitai") > 1)
    return notify_fail("这里正在比武呢，你先等他们分出胜负再说吧。\n");

  message_vision("\n$N拔开人群，大声说道：" + RANK_D->query_self(me) + "来打擂，说完便往台上跳去！\n", me);
  return ob->load_user(me);
}
