// qizong.h

int permit_recruit(object ob)
{
	

	if (ob->query("detach/浣花剑派") ||
	    ob->query("betrayer/浣花剑派"))
	{
		command("say 浣花剑派自今未成收过破门弟子！");
		return 0;
	}

	if (ob->query("betrayer/times"))
	{
		command("say 浣花剑派讲究的就是信义，你这判师之人焉能理解？");
		return 0;
	}

	if (ob->query("family/family_name") &&
	    ob->query("family/family_name") != "浣花剑派")
	{
		command("say 你既有了名师指点，还何必来我们浣花剑派！");
		return 0;
	}

	return 1;
}
