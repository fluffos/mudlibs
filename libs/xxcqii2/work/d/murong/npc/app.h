void attempt_apprentice(object ob)
{       
	if( ob->query("gender") == "无性")
	{
		command("say 老子最讨厌不男不女的人。");
		return;
	}
	if( ob->query("title") == "姑苏慕容第三代弟子")
	{
		command("say 你既然已经拜了公子为师何必又拜回我呢？");
		return;
	}
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
	command("recruit " + ob->query("id"));
	ob->set("title","姑苏慕容第四代弟子");          
	return;
}
