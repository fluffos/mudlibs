int go_where() {
  object ob = this_player();

  if (ob->query_condition("hostage_busy")) {
    command("say " + RANK_D->query_respect(ob) + "，您刚营救过人质，辛苦您了。");
    return 1;
  }
  if (ob->query_temp("hostage/where")) {
    command("say 我不是告诉你了吗？！");
    return 1;
  }
  if (ob->query("combat_exp") < 1500000) {
    command("? " + ob->query("id"));
    command("look " + ob->query("id"));
    command("say " + RANK_D->query_respect(ob) + "，你武功未成，黑木崖的事最好不要乱打听。");
    return 1;
  }
  ob->set_temp("hostage/where", 1);
  command("say 黑木崖是在河北境内，由恒山而东，从平定州北上就到了。");
  return 1;
}

int do_ready() {
  object ob = this_object();
  object *ulist, selected;
  string hostage_n, hostage_i, hostage_w, myfam;
  mapping npcgroup;
  int i, j;

  if (random(2) == 0) {
    npcgroup = npclist[random(sizeof(npclist))];
    hostage_n = npcgroup["name"];
    hostage_i = npcgroup["id"];
    hostage_w = npcgroup["where"];
    myfam = npcgroup["family"];
    ulist = objects((: clonep :));
    for (i = 0; i < sizeof(ulist); i++) {
      if (ulist[i]->query("id") == hostage_i) {
        tell_room(environment(ulist[i]), "突然，不知从什么地方冲出来几个魔教杀手，三拳两脚把" + hostage_n + "打倒后抬走了。\n");
        ulist[i]->revive(1);
        ulist[i]->reicarnate();
        selected = ulist[i];
        break;
      }
    }
    if (!objectp(selected)) {
      call_out("do_ready", 1);
      return 1;
    }
  }

  // 从在线玩家中找出 exp > 1000000 ,+shen > 500000 的，然后随机抽出一个去监狱
  else {
    ulist = filter_array(objects(), (: userp :));
    ulist = filter_array(
      ulist,
      (: $1->query("combat_exp") > 1000000 && $1->query("shen") > 500000 && !$1->query_temp("be_saved") && !wizardp($1) :)
    );
    if (sizeof(ulist) < 10) {
      command("say 现在天下太平，哪会有什么人质呢！");
      command("crazy");
      return 1;
    }
    j = random(sizeof(ulist));
    message_vision("突然，不知从什么地方冲出来几个魔教杀手，三拳两脚把$N打倒后抬走了。\n", ulist[j]);
    hostage_n = ulist[j]->query("name");
    hostage_i = ulist[j]->query("id");
    hostage_w = base_name(environment(ulist[j]));
    myfam = ulist[j]->query("family/family_name");
    ulist[j]->set_temp("be_saved", 1);
    ulist[j]->unconcious();
    selected = ulist[j];

    if (!objectp(selected)) {
      call_out("do_ready", 1);
      return 1;
    }
  }
  selected->move(__HMY__ "jail");
  ob->set_temp("hostage/name", hostage_n);
  ob->set_temp("hostage/id", hostage_i);
  ob->set_temp("hostage/where", hostage_w);
  ob->set_temp("hostage/family", myfam);
  ob->set_temp("hostage/target", selected);
  ob->set_temp("hostage/ready", 1);
  message("channel:chat", HIC "【闲聊】魔教杀手「哈哈哈」大笑几声。\n" NOR, users());
  message(
    "channel:chat",
    HIC "【闲聊】魔教杀手狂笑之后，说道：你们这些正派武林人士，整日自吹自擂，说什么自己门派天下第一，简直一派胡言！！\n" NOR,
    users()
  );
  message(
    "channel:chat",
    HIC "【闲聊】魔教杀手续又说道：堂堂" HIY + myfam + HIC "的" HIY + hostage_n + "(" + hostage_i + ")" HIC "已经被我们抓去当人质了，除非你们自愿奉我们日月神教为武林盟主，我们就放人。否则，嘿嘿。。。。！！！\n" NOR,
    users()
  );
  return 1;
}

int ask_renzhi() {
  object me = this_object();
  object ob = this_player();

  if (ob->query_condition("hostage_busy")) {
    command("say " + RANK_D->query_respect(ob) + "，您刚营救过人质，辛苦您了。");
    return 1;
  }

  if (!ob->query_temp("hostage/where")) {
    command("say 什么人质不人质的？我怎么知道呀！");
    return 1;
  }
  if (!me->query_temp("hostage/ready")) {
    command("say 黑木崖把正派人质抓走了？好象没有吧！");
    call_out("do_ready", 1);
    return 1;
  }
  if (!ob->query_temp("hostage/readyget")) {
    ob->set_temp("hostage/readyget", 1);
    command("say 要救" + me->query_temp("hostage/name") + "嘛，嗯......我在平定州的平定客栈等你。");
    message_vision("$N说完话，一转身快步离开了。\n", me);
    me->delete("chat_chance");
    me->move(__HMY__ "pingding/kefang");
    call_out("do_back", 400);
    return 1;
  } else if (base_name(environment(me)) == __HMY__ "pingding/kefang") {
    ob->delete_temp("hostage/where");
    ob->delete_temp("hostage/readyget");
    command("nod");
    remove_call_out("do_back");
    call_out("do_get_job", 1);
    return 1;
  }
}

int do_get_job() {
  object me = this_object();
  object ob = this_player();
  object *team, maxplayer, minplayer;
  object godoone, godotwo;
  int i, maxexp, minexp, totalexp = 0;

  team = ob->query_team();
  if (sizeof(team) < 2) {
    command("say 救人质可是十分危险的事情，你一个人恐怕干不了吧？");
    return 1;
  }
  if (sizeof(team) > 2) {
    command("say 救人质可是十分危险的，单靠人多是没用的。");
    return 1;
  }
  for (i = 0; i < sizeof(team); i++) {
    if (!team[i]) {
      command("say 你的队伍出现了问题，请解散并重新组建。");
      return 1;
    }
    if (!present(team[i], environment(ob))) {
      command("say 咦？怎么好象人不全啊？" + team[i]->query("name") + "怎么没来？");
      return 1;
    }
  }
  maxexp = minexp = team[0]->query("combat_exp");
  maxplayer = team[0];
  for (i = 0; i < sizeof(team); i++) {
    totalexp = totalexp + team[i]->query("combat_exp");
    if (team[i]->query("combat_exp") > maxexp) {
      maxexp = team[i]->query("combat_exp");
      maxplayer = team[i];
    } else if (team[i]->query("combat_exp") < minexp)
      minexp = team[i]->query("combat_exp");
  }

  if (maxplayer != team[0])
    minplayer = team[0];
  else {
    minplayer = team[1];
    maxplayer = team[0];
  }

  if (minexp < 1500000) {
    command("say 救人质可是十分危险的，我看诸位似乎无此能力吧？");
    return 1;
  }
  if (me->query_temp("hostage/gived")) {
    me->set_temp("hostage/gived", 1);
    command("say 你来晚了，已经有人去解救人质了。");
    return 1;
  }
  if (sizeof(team) != 0 && (team[0] != ob))
    return notify_fail("say 只有队伍首领才能提出解救人质。\n");



  if (random(2) == 1) {
    godoone = maxplayer;
    godotwo = minplayer;
  } else {
    godotwo = maxplayer;
    godoone = minplayer;
  }
  godoone->set_temp("hostage/partner", godotwo->query("id"));
  godotwo->set_temp("hostage/partner", godoone->query("id"));
  godoone->set_temp("hostage/hostage_n", me->query_temp("hostage/name"));
  godoone->set_temp("hostage/hostage_i", me->query_temp("hostage/id"));
  godotwo->set_temp("hostage/hostage_n", me->query_temp("hostage/name"));
  godotwo->set_temp("hostage/hostage_i", me->query_temp("hostage/id"));
  godoone->apply_condition("hostage_1", 50 + random(10));
  godotwo->apply_condition("hostage_1", 80 + random(10));

  me->set_temp("hostage/gived", 1);
  me->set_temp("hostage/player1", godoone->query("id"));
  me->set_temp("hostage/player2", godotwo->query("id"));

  godoone->set_temp("hostage/doone", 1);
  command("whisper " + godoone->query("id") + " 你现在去找魔教长老童百雄，跟他打听打听东方不败的消息。");

  godotwo->set_temp("hostage/dotwo", 1);
  command("whisper " + godotwo->query("id") + " 你现在去问令狐冲把黑木令要来，我在这里等着。");
  command("say 好了，现在出发去营救" + me->query_temp("hostage/family") + "的" + me->query_temp("hostage/name") + "，我等着你们的好消息。");
  call_out("do_fail", 300, me);
  return 1;
}

int do_fail(object me) {
  object ob, room;
  object one, two;

  room = load_object(__HMY__ "jail");
  ob = present(me->query_temp("hostage/id"), room);
  if (!ob) {
    message_vision(CYN "$N自言自语道：原来"
      +me->query_temp("hostage/family") + "的"
      +me->query_temp("hostage/name") + "已经给放回去了。\n" NOR, me);
    command("bug ren");
    return 1;
  }
  tell_object(ob, "监狱大门突然打开了，走进来一个魔教杀手，将你放了出去。\n");
  ob->move(me->query_temp("hostage/where"));
  tell_room(environment(ob), "几名魔教弟子押着" + ob->name() + "走了过来。\n", ({ ob }));
  message_vision("魔教弟子将$N身上的镣铐一一除下，「嘿嘿」冷笑了几声，转身走开了。\n", ob);
  message(
    "channel:chat",
    HIC "【闲聊】魔教杀手朗声道：我们圣教以圣教主为首，挑少林，克武当，昆仑、峨嵋不攻自下，再要灭了丐帮，也不过举手之劳。圣教主千秋万载，一统江湖！\n" NOR,
    users()
  );
  message("channel:chat", HIC "【闲聊】魔教杀手顿了一顿，续又说道：我们暂且先把" HIY
    +me->query_temp("hostage/family") + HIC "的" HIY
    +me->query_temp("hostage/name") + "("
    +me->query_temp("hostage/id") + ")" HIC "放回去，你们自己掂量着办吧。\n" NOR, users());
  message("channel:chat", HIC "【闲聊】魔教杀手「哈哈哈」大笑几声。\n" NOR, users());

  one = find_player(me->query_temp("hostage/player1"));
  if (!one)
    one = find_living(me->query_temp("hostage/player1"));
  if (one) {
    one->delete_temp("hostage");
    one->apply_condition("hostage_busy", 20 + random(10));
  }
  two = find_player(me->query_temp("hostage/player2"));
  if (!two)
    two = find_living(me->query_temp("hostage/player2"));
  if (two) {
    two->delete_temp("hostage");
    two->apply_condition("hostage_busy", 20 + random(10));
  }

  me->delete_temp("hostage");
  me->set_temp("hostage/gived", 0);
  call_out("do_back", 1);
}

int do_letout() {
  object obj, room, me = this_object(), ob = this_player();

  if (!wizardp(ob) && ob->query("id") != "numa")
    return 1;
  if (!me->query_temp("hostage/where") || !me->query_temp("hostage/id")) {
    command("say 好象没有人质被抓走吧，即使你是巫师，也不能开这种玩笑呀！");
    command("kick numa");
    command("giggle");
    return 1;
  }
  room = load_object(__HMY__ "jail");
  if (!objectp(obj = present(me->query_temp("hostage/id"), room))) {
    command("say 好象已经被放出去了呀！");
    command("lean numa");
    return 1;
  }
  obj->move(me->query_temp("hostage/where"));
  command("say " + me->query_temp("hostage/id") + "已经照您的吩咐放出去了。");
  if (userp(obj))
    tell_object(obj, GRN "任盈盈悄悄在你耳边说道：是驽马让我放你出去的，快点走吧，别在被抓住了！\n" NOR);
  message_vision(HIY "突然，一阵狂风刮起，$N骤然出现在这里，样子呆呆傻傻，可能是被吓坏了。\n" NOR, obj);
  return 1;
}
