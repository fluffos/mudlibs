inherit NPC;

void heart_beat()
{
        object me = this_object();
        string str;
        if( !environment() )  
                return;
        if( living(me) && !me->is_busy() )
	{
        	if( !me->is_fighting() )
        	{
                	if( query("eff_kee") < this_object()->query_maxkee()
                         || query("kee") < query("eff_kee") 
                         || query("sen") < query("eff_sen") 
                         || query("eff_sen") < this_object()->query_maxsen() )
                        	this_object()->clear_condition();       
        	}
        	else
        	{
        		if( query("eff_kee") < this_object()->query_maxkee() )
		                QUEST_D->addEffKee(me);
		        if( query("kee") < query("eff_kee") )
                		QUEST_D->addKee(me);
		        if( query("sen") < query("eff_sen") )
                		QUEST_D->addSen(me);
		        if( query("eff_sen") < this_object()->query_maxsen() )
                		QUEST_D->addEffSen(me);
			if( objectp(query_temp("weapon")) )
                		str = query_temp("weapon")->query("skill_type");
        		else	str = "unarmed";
        		switch(random(10))
        		{
		                case 9 :
                		case 8 :        
		                case 1 :
                		case 0 : 
		                        if( !query("no_cast") ) 
                		                QUEST_D->randomCast(this_object());
                        		break;
		                case 2 :
                		case 7 :
		                case 8 :
                		case 3 : 
		                        if( !query("no_pfm") ) 
                		                QUEST_D->randomPfm(this_object(),str);
                        		break;
		                default: 
                		        QUEST_D->randomPfm(this_object(),str);
        		}       
        	}
	}
	::heart_beat();	
}
