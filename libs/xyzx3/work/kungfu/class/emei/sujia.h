// sujia.h
// create by host jan,8 1998

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 0) {
		command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
		command("say 我看" + RANK_D->query_respect(ob) +
			"邪气太重了，德行方面是否还做得不够？");
		return;
	}
        command("say 好吧，就收下你了。");
	command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");
}
