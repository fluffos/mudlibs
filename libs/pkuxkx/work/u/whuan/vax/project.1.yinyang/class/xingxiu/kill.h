void init()
{
        object ob;
        mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                if ((ob=this_player())->query("shen") >= 10000
                        ) {
                        remove_call_out("do_killing");
                        call_out("do_killing",2,ob);
                        message_vision("白道小丑，也敢来我星宿撒野，小心你的狗头!!\n", this_player());
                }
        }
}

void do_killing(object ob)
{
	if (!ob || environment(ob) != environment()||environment(ob)->query("no_fight"))
                return;
        this_object()->kill_ob(ob);
}


