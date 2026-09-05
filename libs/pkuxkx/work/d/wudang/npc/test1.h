string *five=({
	"李莫愁","王五","霍都","张三","黑老板",
});

void die()
{	int i;
        object corpse;
	object ob=this_object();
        object killer=this_object()->get_damage_origin_object();
	if ((int)killer->query("test/0")<5 && !(int)killer->query((string)ob->query("name") + "/killed"))
	    {	killer->set((string)ob->query("name") + "/killed",1);
		killer->add("test/0",1);
	    }
	if ((int)killer->query("test/0")==5 && !(int)killer->query((string)ob->query("name") + "/killed"))	
	    {	killer->set("finish_task",1);
		killer->delete("test/0");
		for (i=0;i<5;i++)
			killer->delete(five[i] + "/killed");
	    }
	message_vision("$N死了。\n",this_object());
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        destruct(this_object());
        return;
}
