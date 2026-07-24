// du.h for apprentice.
//Hop 1997.01.23

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	name = ob->query("name");

	if ( ob->query("betrayer") >= 2)
	{
		command("say " + RANK_D->query_respect(ob) + "判師次數太多了，我不能收你。");
		return;
	}

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "與本派素無來往，不知此話從何談起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺內學藝。");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，貧僧哪里敢當 !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麼跑到我這兒來了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if (ob->query("family/generation") == 37)
	{
		if ((int)ob->query_skill("dodge", 1) < 120 ||
		    (int)ob->query_skill("parry", 1) < 120 ||
		    (int)ob->query_skill("force", 1) < 120 ||
		    (int)ob->query_skill("buddhism", 1) < 120 ||
		    (int)ob->query_skill("hunyuan-yiqi", 1) < 120 ||
		    (int)ob->query_skill("shaolin-shenfa", 1) < 120) {
			command("say " + "你是否還應該在各項技能上多下點功夫？");
			return;
		}

		command("chat 哈哈哈哈！！！！");
		command("chat 想不到老納在垂死之年，又覓得一個可塑之才，真是可喜可賀。");
		command("recruit " + ob->query("id"));
	
		command("say 是" + ob_fam["master_name"] + "叫你來找我的吧，哈哈哈 !");
		command("say 貧僧又得一可塑之才，真是可喜可賀 !");

		name = ob->query("name");
		new_name = "玄" + name[2..3];
		ob->set("name", new_name);
		ob->set("family/generation",36);
/*
		ob->add("str",1);
		ob->add("int",1);
		ob->add("con",1);
		ob->add("dex",1);
		ob->add("max_neili",100);
*/	
		command("say 從今以后你的法名叫做" + new_name + "，恭喜你榮升為少林派玄字輩弟子 !");
		command("recruit " + ob->query("id"));
	}


}

