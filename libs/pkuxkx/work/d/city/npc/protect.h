init()
{
        object ob;
        mapping myfam;
        
        ::init();
        if (interactive(ob)) {
                if (ob->query("id") == "tiger")
                {
                        remove_call_out("do_killing");
                        call_out("do_killing",2,ob);
                        message_vision("大胆畜生，这是你乱闯的地方吗!!!");
                }
        }
}

void do_killing(object ob)
{
	if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}


