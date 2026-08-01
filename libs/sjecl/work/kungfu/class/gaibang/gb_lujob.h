//By Spiderii@ty 暂时关闭smy.exp分配弄不太好
// gb_lujob.h
// Lklv 2001.9.28 update change gb_job.c -> gb_lujob.h and rebuild it

string gb_job1() {
  object me = this_player();

  if (me->query_temp("gb_job1"))
    return "你上次的任务还没有完成，我怎么放心再让你办事。";
  command("say 刚才我接到本帮弟子易大彪飞鸽传书，西夏国主起大军十万，欲侵我大宋。");
  new(__DIR__ "obj/gaoji-wenshu")->move(me);
  message_vision("$N给$n一张告急文书。\n", this_object(), me);
  me->set_temp("gb_job1", 1);
  return "你速将这份告急文书交给边关守将侯君集，请他早做防备。";
}

string gb_job2() {
  object me = this_player(), ob = this_object();
  mixed *ob_list;
  int max, i;
  object obj1;

  if (me->query_temp("gb_job2"))
    return "你不是已经接过任务了吗？";

  ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
  max = sizeof(ob_list);
  for (i = 0; i < max; i++) {
    obj1 = ob_list[i];
    if (obj1->query_temp("gb_job2"))
      return "这个任务我已经交给" + obj1->query("name") + "(" + capitalize(obj1->query("id")) + ")" + "去做了。";
  }

  if (ob->query_temp("gb_job2"))
    return "我这里现在没有什么任务可以给你。";

  if (me->query("job_name") == "火烧草料场")
    return "您上次任务辛苦了，还是先休息一下再说吧。";

  set_temp("gb_job2", 1);
  me->set_temp("gb_job2", 1);
  me->apply_condition("gb_job2", 40);
  me->apply_condition("job_busy", 10);

  command("say 蒙古大军侵我大宋襄阳城，每次都以南阳为囤粮之所。\n");
  command("say 郭靖郭大侠多次派人偷袭，均因守将防守严密而失败。\n");
  command("say 前几天本帮弟子打探到南阳城北有一处断崖，地势险峻，蒙古兵防守空虚。\n");
  return "你从该处爬上去，伺机烧掉蒙古粮仓，以解我襄阳之围。";
}

string gb_job3() {
  object me = this_player(), ob = this_object();
  mixed *ob_list;
  int max, i, j;
  object obj1;

  if (me->query_temp("gb_job3"))
    return "你不是已经接过任务了吗？";

  if (me->query("job_name") == "刺杀敌元帅")
    return "您上次任务辛苦了，还是先休息一下再说吧。";

  if (!wizardp(me) && me->query_condition("job_busy"))
    return "您上次任务辛苦了，还是先休息一下再说吧。";

  ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
  max = sizeof(ob_list);
  for (i = 0; i < max; i++) {
    obj1 = ob_list[i];
    if (obj1->query_temp("gb_job3"))
      return "这个任务我已经交给" + obj1->query("name") + "(" + capitalize(obj1->query("id")) + ")" + "去做了。";
  }

  for (j = 1; j < 6; j++)
    load_object("/d/gb/zhongjun" + j);
  j = sizeof(children("/d/gb/npc/yuanbing-shiwei"));

  if (j < 6)
    return "蒙古大汗暂时没找到踪迹，等会再来吧。";

  if (ob->query_temp("gb_job3"))
    return "我这里现在没有什么任务可以给你。";

  GIFT_D->check_count(me, this_object(), "刺杀");

  command("say 蒙古大汗蒙哥令大将粘而帖率精兵数十万，兵分两路，企图犯我襄阳。\n");
  command("say 为今之计，只有寻机刺杀蒙古大将，才能迫使蒙古大军撤围襄阳。\n");

  set_temp("gb_job3", 1);
  me->set_temp("gb_job3", 1);
  me->apply_condition("gb_job3", 50);
  me->apply_condition("job_busy", 10);
  command("say 我丐帮弟子易大彪已经潜入蒙古军中，你可去襄阳北门等他。\n");
  return "由他带你混进蒙古大营，伺机刺杀蒙古大汗。";
}

#define DEBUG_MODE 0

string smy_job() {
  object me = this_player(), ob = this_object();
  int max, i;
  object obj1;
  object *ob_list;
  object ob2;
  //	if (!wizardp(me))	
  //              return "暂时关闭,开放日期另行通知!";
  if (me->query_temp("smy_job"))
    return "你不是已经接过任务了吗？";

  ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
  max = sizeof(ob_list);
  for (i = 0; i < max; i++) {
    obj1 = ob_list[i];
    if (obj1->query_temp("smy_job"))
      return "这个任务我已经交给" + obj1->query("name") + "(" + capitalize(obj1->query("id")) + ")" + "去做了。";
  }
  //调试
  if (!wizardp(me) && !DEBUG_MODE) {
    if (me->query_condition("job_busy") || me->query_condition("gb_job_busy"))
      return "您上次任务辛苦了，还是先休息一下再说吧。";

    if (me->query("job_name") == "抗敌颂摩崖")
      return "您上次任务辛苦了，还是先休息一下再说吧。";

    if (ob->query_temp("smy_job"))
      return "我这里现在没有什么任务可以给你。";
    //调试
  }

  ob2 = new("/clone/npc/zhong-shentong");
  if (ob2) {
    destruct(ob2);
  }

  //GIFT_D->check_count(me,this_object(),"颂摩崖");

  command("say 我刚才接到本帮弟子易大彪飞鸽传书，西夏一品堂派遣大批高手东来。\n");

  set_temp("smy_job", 1);

  // 调试信息
  me->set_temp("smy_job/asked", 1);
  me->apply_condition("job_busy", 30);
  command("say 颂摩崖是西夏武士东来的必经之地，你速带几名弟子埋伏在那里截杀。\n");

  if (wizardp(me)) {
    me->apply_condition("smy_job", 6);
    me->set("neili", me->query("max_neili") * 2);
    me->move("/d/xingxiu/silk3");
  } else
    me->apply_condition("smy_job", 10);

  return "这批武士中不乏高手，你多带弟子，布下阵法，以策万全，切记切记。";
}
