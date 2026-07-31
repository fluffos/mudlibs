// check recruit

int permit_recruit(object ob)
{
	if (ob->query("detach/雪山寺") || ob->query("betrayer/雪山寺"))
	{
		command("say 你离开了雪山寺们，雪山寺已经不认你了！");
		return 0;
	}

	if (ob->query("betrayer/times"))
	{
		command("say 我们雪山寺最恨判师之徒，你还不快滚？");
		return 0;
	}

	if (ob->query("family/family_name") &&
	    ob->query("family/family_name") != "雪山寺")
	{
		command("say 你有师傅指点，当循序渐进，怎可贸然判师？");
		return 0;
	}

	return 1;
}
