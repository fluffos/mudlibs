int valid_leave(object me, string dir) {
  object ob;
  if (me->query_temp("wait_target") && objectp(present("anran zi", environment(me))))
    return notify_fail("黯然子闪身拦在你面前，喝道：临阵想溜？给我滚回来！\n");

  if (me->query_temp("xx_rob") && objectp(present("hubiao biaoshi", environment(me))))
    return notify_fail("护镖镖师闪身拦住你的去路，看来是想把你给废了！\n");

  if (me->query_temp("xx_rob") && objectp(present("shangdui", environment(me))))
    return notify_fail("商队在这里呢，快抢(qiang)啊！\n");
  if (dir == "southwest") {
    if (me->query("can_ride")) {
      return 0;

    }

    if (me->query_temp("ride_horse"))
      return notify_fail("你刚想骑马进去，但见里面鸟兽成群，不由止住了脚步。\n");
  }



  return ::valid_leave(me, dir);
}
