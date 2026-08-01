string ask_for_join() {
  object me = this_player();
  if (me->query_temp("tls_chujia"))
    if (me->query("tls") && (string)me->query("class") == "bonze")
      return "阿弥陀佛！大师已是天龙寺内出家之人，何故跟贫僧开这等玩笑？\n";
  if ((string)me->query("gender") == "女性")
    return "阿弥陀佛！崇圣寺乃是寺院，女施主若真心皈依我佛，可去峨嵋庵里受戒。\n";
  if (me->query_temp("tls_app")) {
    me->delete_temp("tls_app");
    me->set_temp("tls_chujia", 1);
    me->delete_temp("tls_app");
    me->set_temp("tls_chujia", 1);
    return "阿弥陀佛！善哉！善哉！施主既是今上所举，自可入我天龙寺出家，你就拜师(bai)吧。\n";
  }
  return "阿弥陀佛！善哉！善哉！本寺僧侣已满，施主还是请回吧。\n";
}

void attempt_apprentice(object me) {
  object ob;
  mapping ob_fam, fam;
  string name, new_name, *prename;
  ob = this_object();
  prename = ({ "心", "明", "月" });
  ob_fam = ob->query("family");
  fam = me->query("family");

  if (me->query("gender") != "男性") {
    command("say 阿弥陀佛！" + RANK_D->query_respect(me) + "，贫僧可不敢开这等玩笑啊。");
    return;
  }
  if (!fam || fam["family_name"] != "天龙寺") {
    command("say " + RANK_D->query_respect(me) + "与本寺素无来往，不知此话从何谈起？");
    return;
  }

  if (me->query("tls") && fam["generation"] <= ob_fam["generation"]) {
    command("say " + RANK_D->query_respect(me) + "，贫僧哪里敢当！");
    return;
  }

  if (me->query("tls") && fam["generation"] == (ob_fam["generation"] + 1)) {
    command("say " + fam["master_name"] + "最近功课繁忙，你就过来跟着我学习吧。");
    command("recruit " + me->query("id"));
    return;
  }

  if (me->query_temp("tls_chujia")) {
    command("nod");
    command("say 阿弥陀佛，善哉！善哉！");
    message_vision("$N双手合十，恭恭敬敬地跪了下来。\n\n"
      "$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n",
      me, ob);
    name = me->query("name");
    new_name = prename[random(sizeof(prename))] + name[0..1];

    command("chat " + me->query("title") + name +
      "于今日" + NATURE_D->game_time() + "在天龙寺剃度出家，取法名" + new_name + "！\n");
    command("say 从今以后你的法名叫做" + new_name + "。");
    me->set("name", new_name);
    me->set("class", "bonze");
    me->set("shen", 0);
    me->delete_temp("tls_chujia");
    me->set("tls", 1);
    command("recruit " + me->query("id"));
    return;
  } else {
    if (!me->query("tls")) {
      command("say 阿弥陀佛！本寺僧侣已满，施主还是请回吧。");
      return;
    }
  }
}
