// 汴京   soldier.h
void kill_player(object me);
void init()
{
    ::init();
    if( interactive(this_player()) && !is_fighting() ) {
        remove_call_out("greeting");
        call_out("greeting", 1);
    }
}
void greeting()
{      
    object me = this_player();

    if( me->query_condition("kill_capital") || me->query_condition("
kill_soldier") || me->query_condition("kill_government") )
    {
        message_vision( name()+"对着$N大喝一声：“杀人放火的刁民，快快受死吧！！！” \n", me );
        kill_ob(me);
        me->fight_ob(this_object());
    }
}
int accept_bihua(object me)
{
    return accept_fight( me );
}

int accept_fight(object me)
{
    if ( me->query( "class" ) == "soldier" || me->query( "class" ) == "government" )
    {
        set("factor" , query("force_factor"));
        set("force_factor",0);
/*        if ( ob = query_temp("weapon") )
         {
            command("say ok");
            set_temp("my_weapon" , ob->id() );
            command("unwield " + ob->id() );
         } */
        message_vision( name() + "看了看$N，笑着说：”你这么苦练，就能升官发财啦？官场上可不\n"+"是这么简单的呦！！好吧，我就陪你练练！\n", me );
        return 1;
    }
    if ( random(5) == 0 )
    {
        command("say 军爷我今天心情好，别烦我，滚！！！！\n");
        return 0;   
    }    
    kill_player(me);
    return 1;
}

int refuse_killing(object me)
{
    kill_player(me);
    return 0;
}
string call_others(object who)
{   
    object this;
    this = this_object();
    who = this_player();  
    message_vision("$N喝道：来人哪，有反贼！\n",this);
    return "";
}
void kill_player(object me)
{                             
    object *all;
    int i;

    command("say 我看你今天是活得不耐烦了,"+ RANK_D->query_rude(me)+",去死吧！\n"); 
    CRIME_D->set_crime( me , "capital" );
    CRIME_D->set_crime( me , "soldier" );
//    if( ob = query_temp( "my_weapon" ) )
//        command("wield " + ob );
    if ( i = query( "factor" ) )
        set("force_factor", i );
    all = all_inventory(environment(me));
    for ( i = 0; i < sizeof( all ); i ++ )
    {
        if ( all[ i ]->query("class") == "soldier"  )
        {
//            if( ob = all[ i ]->query_temp("my_weapon" ) )
//                command("wield "+ ob);
              if( all[ i ]->query("factor") )
                  all[ i ]->set("force_factor", all[ i ]->query("factor") );
            all[ i ] -> kill_ob(me); 
            me->fight_ob(all[i]);
        }
    }
    return ;
}   
