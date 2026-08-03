// emei sujia apprentice

void attempt_apprentice(object ob)
{
	if( (string)ob->query("class") == "bonze" )
	{	command ("say 我只收峨嵋『俗家弟子』。");
		return;
	}
	if( (string)ob->query("gender") == "中性" )
	{
		command ("say 我最讨厌的就是不男不女之人。");
		return;
	}
	command ("say 好吧！我就收下你做『俗家弟子』了。");
	command("recruit " + ob->query("id"));
	if( (string)ob->query("class")!="bonze" )
	{
		ob->set("title", "峨嵋派俗家弟子");
	}
}
