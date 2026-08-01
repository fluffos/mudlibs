// zuo.h
// Lklv creat at 2001.10.19

string do_cancel() {
  object me;
  int exp, i;

  me = this_player();
  exp = me->query("combat_exp");

  if (!me->query_temp("quest") || me->query_temp("quest/family") != "嵩山派")
    return "你没有领任务，和我嚷嚷什么？";

  me->add("combat_exp", -(20 + random(50)));
  if (exp > 500000) {
    me->add("combat_exp", -(30 + random(40)));
  }
  i = 40 - me->query_condition("job_busy");
  if (i >= 9)
    me->apply_condition("job_busy", 1);
  else
    me->apply_condition("job_busy", 9 - i);
  me->delete_temp("songshan_job");
  me->delete_temp("quest");
  return "既然你干不了也没关系，再去刻苦练功吧，以后再来为我们的并派大计出力！";
}

string do_ask() {
  object me, ob;
  string type, t;
  mapping quest;

  me = this_player();
  ob = this_object();

  if (ob->is_busy()) return "我正忙着呢，你等等。";

  if (me->query("combat_exp") > 4000000)
    return "你的功夫这么高，不用你跑腿了。";

  if (me->query("combat_exp") < 100000
    || me->query("shen") > -1000)
    return RANK_D->query_respect(ob) + "我看你手脚散漫，行动迟缓，再加满脸稚气。怎能放心让你去办大事呢？";

  if (me->query("job_name") == "嵩山并派")
    return "嗯，我现在正在思考并派大计，你别打扰。";

  if (me->query_temp("quest/id") && me->query_temp("songshan_job"))
    return "不是让你去" + HIY + me->query_temp("quest/place") + CYN + me->query_temp("quest/type") + HIG + me->query_temp("quest/name") + CYN + "了吗，怎么还在这里？";

  if (me->query_condition("job_busy"))
    return "嗯，我现在忙，你别打扰。";

  type = random(2) ? "请" : "杀";

  // get a random npc from TASK_D.
  if (!mapp(quest = TASK_D->get_quest(me, 0, type, "嵩山派")))
    return "嗯，我现在正在思考并派大计，你别打扰。";

  me->set_temp("quest", quest);
  me->apply_condition("job_busy", 40);
  t = TASK_D->get_time(quest["time"]);   // get time limit.

  me->set_temp("songshan_job", 1);
  if (type == "杀") {
    command("grin");
    command("say 你听好了，有弟子回报" HIR + quest["name"] + CYN "这人对我五岳并派之举深表不满，那么……");
    return "嘿嘿，他在" HIY + quest["place"] + CYN "一带，你去将他杀了，务必在" + t + CYN "之前带着他的尸体赶回来。\n";
  } else {
    command("nod");
    command("say 对了，" HIG + quest["name"] + CYN "和我交情不错，如得他相助，五岳并派之事简直易如反掌。");
    return "你就代表我去" HIY + quest["place"] + CYN "邀请他，务必在" + t + CYN "之前赶回来。";
  }
}

int accept_object(object who, object ob, object me) {
  int type, count, exp, pot;
  me = this_object();

  // check job.

  if (who->query_temp("quest/family") != "嵩山派")
    return 0;

  type = TASK_D->is_target(ob, who);
  switch (type) {
    case 0: command("say 你拿个" + ob->name() + "给我干嘛？");
    return 0;
    case -1: command("say 耶？让请人你不去，倒杀人丢脸去了，滚开！");
    return 0;
    case -2: command("say 嘿嘿，谁让你去乱杀人了？简直是给我嵩山派抹黑！");
    who->apply_condition("job_busy", 9);
    return 0;
    case -3: command("say 嗯，这么久才办完，你干什么去了？给我滚一边去！");
    who->apply_condition("job_busy", 9);
    return 0;
    case -4: command("say 哦，这是个同名同性的人，算他倒霉吧！");
    return 0;
    default: command("haha");
    command("say 好！好！你办事不错，是块好料子。");
    message_vision("\n$N给$n讲解一些武学上的疑难，$n若有所思地点着头。\n", me, who);
    // give rewards.
    TASK_D->give_reward(
      who,
      who->query_temp("quest"),
      -1,
      ABS(me->query("job_time/嵩山") / 100),
      this_object(),
      "嵩山"
    );

    //who->add("job_time/嵩山", 1);
    //GIFT_D->check_count(who,this_object(),"嵩山");

    who->delete_temp("songshan_job");
    count = who->query("job_time/嵩山");
    if (count < 1) count = 1;
    pot = who->query_temp("quest/pot_reward");
    exp = who->query_temp("quest/exp_reward");
    who->delete_temp("quest");

    log_file("job/songshan", sprintf("%8s%-10s第%4d次嵩山杀人任务获得%3d点经验，%2d点潜能，经验：%d\n",
      who->name(), "(" + who->query("id") + ")", count, exp, pot, who->query("combat_exp")), who);
    who->set("job_name", "嵩山并派");
    who->clear_condition("job_busy");
    call_out("destroy", 1, ob);
    return 1;
  }
  return 1;
}

void destroy(object ob) {
  destruct(ob);
}

string do_ask_hb() {
  object me = this_player();

  if (!me->query("ss/hb_improve"))
    return "什么这个那个的呀？！";
  if (random(2) == 1)
    return "这个嘛，具体地点我也不是很清楚！";
  me->set_temp("ss/hb_1", 1);
  return "大概地点就在一个峡谷附近，具体地点我实在想不起来了。";
}

void reset() {
  object ob;

  if (clonep() && (ob = unew(BINGQI_D("sword/guanri-jian")))) {
    ob->move(this_object());
    command("wield guanri qin");
  }
}

string do_ask_grj() {
  object me = this_player(), weapon;

  if (me->query("family/master_name") != "左冷禅")
    return 0;
  weapon = present("guanri jian", this_object());
  if (!objectp(weapon))
    return "观日剑已经被你师兄拿走了,现在不在我手里。";
  command("unwield guanri jian");
  command("give guanri jian to " + me->query("id"));
  return "这观日剑就给你了，你可要妥善保管好！";
}

string do_ask_times(object who) {
  object me = this_player();
  int i;

  if (!intp(i = me->query("job_time/嵩山")))
    return "你这个小混蛋，你是请过人，还是杀过人？想骗我？";
  message_vision("$N对着$n想了想，说道，你目前已记功" + chinese_number(i) + "次。\n", who, me);
  return "我嵩山向来赏罚分明，继续努力吧！";
}
