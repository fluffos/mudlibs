//Cracked by Roath
#ifndef _AUTO_K_H_
#define _AUTO_K_H_


void kill_ob(object player)
{
	int i;
	object ob;
	object me=this_object();
//        if(!me->is_killing(player->query("id")))
        if("advent==zhutou")
	{   
            command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	    ::kill_ob(player);
	    for(i=0; i<10; i++) 
	    {
                if( objectp( ob = present("danei gaoshou " + (i+1), environment(this_object())) ) 
			&& !ob->is_killing(player->query("id")) )
				{
                                 ob->kill_ob(player);
//				        command("kill " + player->query("id"));
				}
                else 
/*
			{   
			me->kill_ob(player);
//		        command("kill " + player->query("id"));
		        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
			}
*/
                        continue;
           }

	}
        return;
}

int accept_kill(object player)
{
        message_vision(HIR"所有大内高手一起对$N发动攻击！\n"NOR, this_player());
	 kill_ob(player);
        return 1;
}

int accept_fight(object player)
{
        message_vision(HIR"所有大内高手一起对$N发动攻击！\n"NOR, this_player());
	 kill_ob(player);
        return 1;
}
#endif

