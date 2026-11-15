// yihua.h

int permit_recruit(object ob)
{
	object me;

	me = this_object();
	if( ob->query("detach/移花宫") ||
	    ob->query("betrayer/移花宫") )
	{
		command("say 你当年既然离开了移花宫，今天又何必回来？");
		return 0;
	}

	if( ob->query("family/family_name") &&
	    ob->query("family/family_name") != "移花宫" )
	{
		command("say 你已有名师指点，为何又来移花宫？"
			"莫非你要判师不成？");
		return 0;
	}

	return 1;
}
