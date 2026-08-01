int do_next(object toone, object totwo) {
  object me = this_object();

  toone->delete_temp("hostage/doone");
  totwo->delete_temp("hostage/dotwo");
  toone->apply_condition("hostage/hostage_3", 50);
  totwo->apply_condition("hostage/hostage_3", 50);

  me->set_temp("hostage/gived", 1);
  me->set_temp("hostage/player1", toone->query("id"));
  me->set_temp("hostage/player2", totwo->query("id"));

  toone->set_temp("hostage/toone", 1);
  message_vision("$N低下头来，想了一会。\n", me);
  command("whisper " + toone->query("id") + " 你现在去监狱杀掉看守，准备救" + me->query_temp("hostage/name") + "。");

  totwo->set_temp("hostage/totwo", 1);
  command("whisper " + totwo->query("id") + " 你现在从这里去杨莲亭的书房找钥匙。");
  command("say 好了，现在大家出发吧，我等着你们的好消息。");
  call_out("do_fail", 400, me, toone, totwo);
  return 1;
}
