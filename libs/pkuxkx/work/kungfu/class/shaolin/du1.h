// dao.h for fight and get letter from Dao

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

        
        if (obj->query("id") == "tuijian xin5"
	&& ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say 好，" + ob->query("name") + "，你愿意拜我为师吗？");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
	return 0;

}

void destroying(object me, object obj)
{
	destruct(obj);
        return;
}
