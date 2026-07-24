// greet.h for all player
void init()
{
        object me,ob;
        me = this_object () ;
        ob = this_player () ;

        ::init();


        if (interactive(this_player()) && this_player()->query_temp("fighting"))
        {
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
                this_player()->add_temp("beat_count", 1);
        }       
        if( interactive(ob) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me, ob);
        }
}
void greeting(object me, object ob)
{
        if ( environment(ob) != environment(me) ) return;
        if ( ob->query("score") > me->query("score"))
        {
                message_vision("$N對$n躬身行禮，說道：在下"+me->query("title")+me->query("name")
                        +"，參見"+ob->query("title")+ob->query("name")+"！\n", me, ob );
        }

}
