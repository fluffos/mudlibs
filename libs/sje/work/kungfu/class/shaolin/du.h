string ask_master() {
  object ob;
  mapping fam;
  ob = this_player();
  if (!(fam = ob->query("family")) || fam["family_name"] != "少林派") {
    this_object()->kill_ob(ob);
    return "小子竟敢偷窥我门派之秘，待老衲超渡于你。\n";
  }

  if (fam["generation"] > 36)
    return "你在寺中的日子还浅，日后自会告诉你的。\n";

  if (fam["generation"] <= 35)
    return "你已经是他老人家的弟子了，怎么还来问我们？";

  if ((int)ob->query_skill("yijin-jing", 1) < 160) {
    command("say 我少林派乃内家武功，最重视内功心法。");
    return RANK_D->query_respect(ob) + "是否还应该在易筋经上多下点功夫？";
  }
  if ((int)ob->query_skill("buddhism", 1) < 150) {
    command("say 出家之人，禅义为先，功夫的高低倒还在其次，未练武，要先学佛。");
    return "在禅宗心法方面，" + RANK_D->query_respect(ob) + "是否还做得不够？";

  }
  if ((int)ob->query_skill("dodge", 1) < 150) {
    return "在基本轻功方面，" + RANK_D->query_respect(ob) + "是否还做得不够？";

  }
  if ((int)ob->query_skill("shaolin-shenfa", 1) < 160) {

    return "少林身法是本派独得之秘，" + RANK_D->query_respect(ob) + "是否还做得不够？";
  }
  if ((int)ob->query_skill("force", 1) < 150) {
    return "在基本内功方面，" + RANK_D->query_respect(ob) + "是否还做得不够？";
  }
  if ((int)ob->query_skill("parry", 1) < 150) {
    return "在基本招架方面，" + RANK_D->query_respect(ob) + "是否还做得不够？";
  }
  /*	if (ob->query_MKS() > 0 ) {
		command("say 万事都讲一个缘字。");
		command("say " + RANK_D->query_respect(ob) + "与佛无缘，还是请回吧。");
		return;
	}*/
  ob->set_temp("prepare_fight", 1);
  command("say 无名神僧是本派不世出的高僧大德，一直隐迹于藏经阁,我们师兄弟就是他老人家早年的弟子。\n");
  return "恩师近年来已近仙佛之境界，我等自不能以俗质庸才打扰他老人家清修。你要见我恩师，需胜过我们三种粗浅的功夫。\n";
}
