void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	me = this_object();
	my_fam = ob->query("family");
	ob_fam = me->query("family");
            if (my_fam) {
	if (my_fam["family_name"] != "发梦二党")
	{
		command("say " + RANK_D->query_respect(ob) +"和我们发梦二党向无来往，拜师又从何说起呢？");
		return;
	}
       }
        if ( ((int)ob->query("shen") <= (-1000)) && (my_fam) )
	{
		command("say 你身为发梦弟子却不主张正义，甘入魔道,我不能留你！");
		command("kaichu "+ob->query("id"));
		return;
	}
        if ( (my_fam) && ( ob_fam["generation"] == my_fam["generation"] ) )
	{
		command("say 你我乃同辈弟子，切磋切磋倒是可以，拜师却是从何说起？");
		return;
	}
	if (ob->query("combat_exp")<200000)
	{
		command("say 学武应该扎扎实实，你功夫不够，拜我为师有害无益，还是算了吧。");
		return;
	}
	if((int)ob->query_skill("bairen-shengong",1)< 100){
		command("say 你的百忍神功太差了。");
		return ;
	}
	if((int)ob->query_skill("cuff",1)< 100){
		command("say 你的拳法功底太差了。");
		return ;
	}
	if((int)ob->query_skill("yiye-zhiqiu",1)< 100){
		command("say 一叶知秋乃本门绝技，应该好好钻研。");
		return ;
		}
	if((int)ob->query("max_neili")< 500){
		command("say 你的内力太差了。");
		return ;
	}
        	command("say 好吧，我就收下你了。");
        	command("say 以后一定更不能做坏事。");
		command("recruit " + ob->query("id"));
		return ;
}


