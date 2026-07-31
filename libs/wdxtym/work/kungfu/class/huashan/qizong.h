// qizong.h

int permit_recruit(object ob)
{
	if (ob->query("family/family_name") == "华山剑宗1" &&
	    query("family/generation") > 12)
	{
		command("say 道不同，不相与谋，你还是学"
			"你们剑宗的武功吧。");
		return 0;
	}

	if (ob->query("detach/华山派") ||
	    ob->query("betrayer/华山派"))
	{
		command("say 华山派自今未成收过破门弟子！");
		return 0;
	}

	if (ob->query("betrayer/times"))
	{
		command("say 华山派讲究的就是信义，你这判师之人焉能理解？");
		return 0;
	}

	if (ob->query("family/family_name") &&
	    ob->query("family/family_name") != "华山派" &&
	    ob->query("family/family_name") != "华山剑宗")
	{
		command("say 你既有了名师指点，还何必来我们华山派！");
		return 0;
	}

	return 1;
}
