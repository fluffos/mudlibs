// for this dir "hj_npc_tarder.lpc", "hj_npc_zhujian.lpc", "hj_npc_lianmo.lpc"
// #include .  by naihe 2:16 03-11-5

int me_ok(object me) {
  if (!me || me->query_temp("huanjing") != "start"
    || me->query_temp("hj_hp") < 1
    || !me->query_temp("this_time_mark")
    || !environment(me) || !environment(me)->query("room_mark"))
    return 0;
  return 1;
}

int ob_ok() {
  object ob = this_object(), env;

  if (!living(ob)) return 0;
  env = environment(ob);
  if (!env || env->query("room_mark") != MY_ROOM_MARK)
    return 0;
  return 1;
}
