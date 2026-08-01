// dao.h for fight and get letter from Dao

int accept_object(object ob, object obj) {
  object me = this_object();
  mapping my_fam = me->query("family");
  mapping ob_fam = ob->query("family");

  if (ob->query_temp("have_letter") && present("tuijian xin2", ob)) {
    command("say 怎么样，你拿我的推荐信去拜师了吗？");
    return 0;
  }

  if (obj->id("damo ling")
    && ob_fam["generation"] == my_fam["generation"] + 1
    && !ob->query_temp("have_letter")) {
    ob->set_temp("fight_ok2", 1);
    command("say 好，既然已得到方丈的许可，我们就来验证一下武功。");
    remove_call_out("destroying");
    call_out("destroying", 1, obj);
    return 1;
  }

  if (obj->id("tuijian xin1")
    && ob->query_temp("have_letter")) {
    ob->set_temp("apprentice_ok", 1);
    command("say 好，" + ob->query("name") + "，你愿意拜我为师吗？");
    remove_call_out("destroying");
    call_out("destroying", 1, obj);
    return 1;
  }

  command("smile");
  command("say 这东西给我可没有什么用。");
  return 0;
}

void destroying(object obj) {
  if (obj)
    destruct(obj);
}

int accept_fight(object ob) {
  if (!ob->query_temp("fight_ok2"))
    return ::accept_fight(ob);

  if (query("eff_qi") < query("max_qi") ||
    query("qi") < query("eff_qi") ||
    query("neili") < query("max_neili")
    || is_busy()) {
    command("say 唉呀，我现在身体感觉不太好，你等一会儿再来吧。");
    return 0;
  }
  remove_call_out("checking");
  call_out("checking", 1, ob);

  ob->delete_temp("fight_ok2");

  return 1;
}

void checking(object ob) {
  object obj;
  int my_max_qi, his_max_qi;

  if (!ob) return;
  my_max_qi = query("max_qi");
  his_max_qi = ob->query("max_qi");

  if (is_fighting()) {
    call_out("checking", 1, ob);
    return;
  }

  if (!present(ob)) return;

  if (query_temp("last_lost_to") == ob) {
    if (query_temp("last_damage_from") == ob) {
      command("say 青出于蓝而胜于蓝，" + RANK_D->query_respect(ob) + "不愧是少林寺的佳弟子！恭喜你了！");
      message_vision("$N交给$n一封推荐信。\n", this_object(), ob);
      ob->set_temp("have_letter", 1);
      obj = new("/d/shaolin/obj/tuijianxin-2");
      obj->move(ob);
      return;
    }
    command("say 少林出了你们这样喜欢作弊的弟子，真是羞耻啊！");
    return;
  }

  command("say 看来" + RANK_D->query_respect(ob) +
    "还得多加练习，方能在少林诸多弟子中出人头地！");
}

void attempt_apprentice(object ob) {
  object me = this_object();
  mapping ob_fam;
  mapping my_fam = me->query("family");

  string name, new_name;

  name = ob->query("name");

  if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派") {
    command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
    return;
  }

  if (ob->query("class") != "bonze" && ob_fam["family_name"] == "少林派") {
    command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
    return;
  }

  if (ob_fam["generation"] == 0) {
    command("say 阿弥陀佛！贫僧就收下你做我的弟子了。");
    command("recruit " + ob->query("id"));
    return;
  }

  if (ob_fam["generation"] <= my_fam["generation"]) {
    command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当！");
    return;
  }

  if (ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "清") {
    command("say " + ob_fam["master_name"] + "的徒弟怎么跑到我这儿来了，哈哈哈！");
    command("recruit " + ob->query("id"));
    return;
  }

  if (ob_fam["generation"] == (my_fam["generation"] + 2)) {
    if (ob->query_temp("apprentice_ok")) {
      ob->delete_temp("have_letter");
      ob->delete_temp("apprentice_ok");

      command("say 是" + ob_fam["master_name"] + "叫你来找我的吧，哈哈哈！");
      command("say 贫僧又得一可塑之才，真是可喜可贺！");

      new_name = "清" + name[2..3];
      ob->set("name", new_name);

      command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派清字辈弟子！");
      command("recruit " + ob->query("id"));
    } else
      command("say " + RANK_D->query_respect(ob) + "，你没有推荐信，不能越级拜师。");
  }
}
