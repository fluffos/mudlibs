void check_player();

void init()
{
        check_player();
}

void check_player()
{
        object *oUser ;
        int i ;
  //      if ( !"/cmds/usr/pkgame"->query_pk() ) return;
        oUser = users();
	message( "system", HIR"【 CS 大赛】： 这里到了。\n" NOR, users() );
        for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
        {
        	if ( (oUser[i]->query_temp("pkgame")) && (environment(oUser[i])->query("no_fight")) && (environment(oUser[i])->query("short") != HIR"CS休息室"NOR) && (!wizardp(oUser[i])) )
        	{
        		oUser[i]->add("eff_kee",oUser[i]->query("max_kee")/10);
                	oUser[i]->add("eff_sen",oUser[i]->query("max_sen")/10);
                	oUser[i]->add("kee",oUser[i]->query("max_kee")/10);
                	oUser[i]->add("sen",oUser[i]->query("max_sen")/10);
                	oUser[i]->add("force",oUser[i]->query("max_force")/10);
                	oUser[i]->add("mana",oUser[i]->query("max_mana")/10);
			write(HIW"\n【 CS 大赛】由于你在比赛期间躲在安全区，你的精神，气血，内力和法力都有所下降。你还是尽快离开安全区吧！\n\n"NOR);
		}
	}
	call_out("check_player",5);
}


	        
