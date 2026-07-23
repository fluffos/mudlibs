void attempt_apprentice(object ob)
{
        object me,obb;
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
/*
            if ( (int)ob->query("shen") < -2000)
	{
                command("say 血河派的武功尽在一个“杀”字，你的杀气太低了，我不能收你！");
		return;
	}
*/
        if (ob->query("combat_exp")<80000)
	{
		command("say 学武应该扎扎实实，你功夫不够，拜我为师有害无益，还是算了吧。");
		return;
	}
        if((int)ob->query_skill("yiqiguan-riyue",1)< 50){
                command("say 你对本门内功心法领悟的不够。");
		return ;
	}
        if((int)ob->query("max_neili")< 300){
		command("say 你的内力太差了。");
		return ;
	}
        	command("say 好吧，我就收下你了。");
             if ((my_fam && my_fam["generation"]>14) || (me->query("cloth")=="/d/longmen/xuehepai/obj/cloth1")){
                command("say 这件一道金的血衣你收好，它代表你在本派的地位。");
                obb=new("/d/xuehepai/obj/cloth2");
                obb->move(ob);
				ob->set("cloth","/d/xuehepai/obj/cloth2");
                 }
               command("recruit " + ob->query("id"));
		return ;
}


