void attempt_apprentice(object ob)
{
         object me,obb;
	mapping my_fam, ob_fam;
	me = this_object();
	my_fam = ob->query("family");
	ob_fam = me->query("family");
        	command("say 好吧，我就收下你了。");
           command("say 这件血衣是本派弟子行走江湖的标志，千万别弄丢了。");
         obb=new("/d/xuehepai/obj/cloth1");
         obb->move(ob);
       ob->set("cloth","/d/xuehepai/obj/cloth1");
		command("recruit " + ob->query("id"));
		return ;
}


