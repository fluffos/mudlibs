void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	me = this_object();
	my_fam = ob->query("family");
	ob_fam = me->query("family");
            if (my_fam) {
        if (my_fam["family_name"] != "血河派")
	{
                command("say " + RANK_D->query_respect(ob) +"和我们血河派向无来往，拜师又从何说起呢？");
		return;
	}
       }
/*        if ( (int)ob->query("shen") > -50000000)
	{
                command("say 血河派的武功尽在一个“杀”字，你的杀气太低了，我不能收你！");
		return;
	}*/
        if ( (my_fam) && ( ob_fam["generation"] == my_fam["generation"] ) )
	{
		command("say 你我乃同辈弟子，切磋切磋倒是可以，拜师却是从何说起？");
		return;
	}
	if (ob->query("combat_exp")<20000000)
	{
		command("say 学武应该扎扎实实，你功夫不够，拜我为师有害无益，还是算了吧。");
		return;
	}
        if((int)ob->query_skill("yiqiguan-riyue",1)< 1000){
                command("say 你对本门内功心法领悟的不够。");
		return ;
	}
        if((int)ob->query_skill("jieniu-dao",1)< 1000 || (int)ob->query_skill("yudi-bian",1)< 1000 || (int)ob->query_skill("youren-jian",1)< 1000)
		{
                command("say 血河车是我派之根本，看起来你对血河车中的武学研究的还不够深。");
                return ;
        }
	if((int)ob->query("max_neili")< 500000){
		command("say 你的内力太差了。");
		return ;
	}
        if((int)ob->query("con",1)< 30){
                command("say 你的根骨太差了，不适合入我血河派。");
                return ;
        }
        if((int)ob->query("int",1)< 30){
                command("say 你的悟性太差了，不适合入我血河派。");
                return ;
        }
        	command("say 好吧，我就收下你了。");
		command("recruit " + ob->query("id"));
		return ;
}


