void init()
{       
        object ob;

        if( interactive(ob=this_player()) && ob->query_temp("killwei") ) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

