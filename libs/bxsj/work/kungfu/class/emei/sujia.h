// emei sujia apprentice
// Lklv 2001.10.18 update

void attempt_apprentice(object ob)
{
	if ((string)ob->query("class") == "bonze" ){
		command ("say 我只收俗家弟子。");
		return;
	}
	if( (string)ob->query("gender") != "女性" ){
		command ("blush");
		command ("say 我只收俗家女弟子。");
		return;
	}
	command ("say 好吧！我就收下你做峨嵋派俗家弟子。");
	command("recruit " + ob->query("id"));
	if( (string)ob->query("class")!="bonze" ){
		ob->set("title", "峨嵋派俗家弟子");
//		ob->set("class","emsujia");
	}
}
