#include <ansi.h>
#include <login.h>
#include <dbase.h>
#include <move.h>

void create()
{
}
int die(object me)
{
  object corpse, killer,guai;
	object fan,xiang,bian;
	int dead;
	object *inv;
	int i,times;
	string last_fainted_from, str;
  /////////////////////
  ///////////////////////
	if (environment(me) && environment(me)->query("alternative_die")) {
	  environment(me)->alternative_die(me);
	  return 0;
	}
	
        if (me->query_temp("last_fainted_from")) 
	   last_fainted_from=me->query_temp("last_fainted_from");

	if( !living(me) ) me->revive(1);
	if( wizardp(me) && me->query("env/immortal") ) return 0;

	if (last_fainted_from) 
	  me->set_temp("last_fainted_from",last_fainted_from);

    	COMBAT_D->announce(me, "dead");
 
	if (me->query("dajiu_busy") > time())
	    {
			 guai = me->query_temp("last_damage_from");
			
		        if (guai&&guai->query("mark") == me->query_temp("dajiu/mark") )
		        {
		               times = me->query_temp("dajiu/count")+3;
			      if(me->query_temp("dajiu/die") < times)
		        	{
				        message_vision(BLINK+YEL"突然天空中散出一道圣光，笼罩住$N全身。\n"NOR,me);
				        me->set("eff_kee",me->query("max_kee"));
				        me->set("eff_sen",me->query("max_sen"));
				        me->set("kee",me->query("max_kee"));
				        me->set("sen",me->query("max_sen"));
				        me->set("force",2*me->query("max_force"));
				        me->set("mana",2*me->query("max_mana"));
                                       //add by dianel for high expER low lose 2006.09.14
                                       if((me->query("combat_exp")/6666>5000)&&(me->query("daoxing")/6666>5000)) 
                                       {
                                           me->add("dajiu/exp",-5000);
                                           me->add("dajiu/dx",-5000);
                                           me->add("combat_exp",-5000);
                                           me->add("daoxing",-5000);
                                       }
                                       else if(me->query("combat_exp")/6666>5000) 
                                       {
                                           me->add("dajiu/exp",-5000);
                                        me->add("dajiu/dx",-me->query("daoxing")/6666);
                                           me->add("combat_exp",-5000);
                                        me->add("daoxing",-me->query("daoxing")/6666);  
                                       }
                                       else if(me->query("daoxing")/6666>5000)
                                       {
                                        me->add("dajiu/exp",-me->query("combat_exp")/6666);
                                           me->add("dajiu/dx",-5000);
                                        me->add("combat_exp",-me->query("combat_exp")/6666);
                                           me->add("daoxing",-5000);
                                       }
                                       else {
				        me->add("dajiu/exp",-me->query("combat_exp")/6666);
				        me->add("dajiu/dx",-me->query("daoxing")/6666);
				        me->add("combat_exp",-me->query("combat_exp")/6666);
				        me->add("daoxing",-me->query("daoxing")/6666);	
	        
                                       }
				        me->start_busy(1);
				        me->add("dajiu/die",1);
				         me->add_temp("dajiu/die",1);
			        }
			        else
			        {
				        fan=present("dingyao fan",me);
					xiang=present("baibao xiang",me);
					bian=present("dashen bian",me);
				        message_vision(HIY" 突然半空中一只大手一把抓住$N,一下子就不见了\n"NOR,me);
				        me->clear_condition();
       					me->delete("dajiu_busy");
				        me->unconcious();
				        me->set("eff_kee",me->query("max_kee"));
				        me->set("eff_sen",me->query("max_sen"));
				        me->set("kee",me->query("max_kee")/3);
				        me->set("sen",me->query("max_sen")/3);
				        me->add("dajiu/exp",-me->query("combat_exp")/2100);
				        me->add("dajiu/dx",-me->query("daoxing")/2100);
				        me->add("combat_exp",-me->query("combat_exp")/2100);
				        me->add("daoxing",-me->query("daoxing")/2100);	
				        me->add("dajiu/die",1);
				        me->delete_temp("dajiu");
				        me->remove_ride();
				        me->move("/d/wiz/entrance");
				        message_vision(HIY"姜子牙盯着$N,摇了摇头说:看来你的修行不够,不可担当大任。说完伸手在$N顶门一拍\n"NOR,me);
				       if(fan) 
				      	 destruct(fan);
				        if(xiang) 
				      	 destruct(xiang);
				      	if(bian) 
				      	 destruct(bian);
						
			
			        }
			       	return 0;
			}
		}

	if ( me->query("xian/get")+900 > time() )
	    {
			guai = me->query("xian/guai");        
	        if ( guai && (guai == me->query_temp("last_damage_from") || guai == me->query_temp("last_opponent")) )
	        {
		        message_vision(HIY" 突然半空中一只大手一把抓住$N,一下子就不见了\n"NOR,me);
		        me->set("eff_kee",me->query("max_kee"));
		        me->set("eff_sen",me->query("max_sen"));
		        me->set("kee",me->query("max_kee")/3);
		        me->set("sen",me->query("max_sen")/3);
		        me->add("combat_exp",-me->query("combat_exp")/1600);
		        me->add("daoxing",-me->query("daoxing")/1600);	// alading  2002-6-2
		        me->add("xian_log/die",1);
		        me->delete("xian/get");
		        me->set("xian/fail",1);
		        me->remove_ride();
		        me->move("/d/quest/yuxugong");
		        message_vision(HIY"原始天尊盯着$N,摇了摇头说:看来你的修行不够,不可担当大任。说完伸手在$N顶门一拍\n"NOR,me);
		         me->clear_condition();
			me->unconcious();
			return 0;
			}
		}
	
if ( me->query("yao/get") + 900 > time() )
           {
               	guai = me->query("yao/guai");        
                	if ( guai && (guai == me->query_temp("last_damage_from") 
               	|| guai == me->query_temp("last_opponent")) )
                	     {
                                message_vision(HIY" 突然半空中一只大手一把抓住$N,一下子就不见了\n"NOR,me);
                	     	me->set("eff_kee",me->query("max_kee"));
                	     	me->set("eff_sen",me->query("max_sen"));
                	     	me->set("kee",me->query("max_kee")/3);
                	     	me->set("sen",me->query("max_sen")/3);
                                me->add("combat_exp",-me->query("combat_exp")/1600);
                                me->add("daoxing",-me->query("daoxing")/1600);
                                me->add("yao_log/die",1);
                                me->delete("yao/get");
                                me->set("yao/fail",1);
                                me->remove_ride();
                                me->move("/d/quest/bixiaogong");
                   message_vision(HIY"通天教主盯着$N,狠狠的说:没用的东西,不可担当大任。说完伸手在$N顶门一拍\n"NOR,me);
		                me->clear_condition();
		                me->unconcious();
		                return 0;
		              }
		 }
	
	
	me->clear_condition();

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if( inv[i]->query("owner_id") == getuid(me) )
		{
        tell_object(me, HIB+"你看到" + inv[i]->query("name") +
			HIB + "破空而去，慢慢消失在天际．．．\n"+NOR);
            destruct( inv[i] );
         }
    }

        if( (int)me->query("max_gin") > 0 && 
	    (int)me->query("max_kee") > 0 &&
            (int)me->query("max_sen") > 0 ) {
	    //no damage to self_purged people.

	if( objectp(killer = me->query_temp("last_damage_from")) ) {
		me->set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, me);
		if(userp(me))
		  log_file("death",sprintf("[%s] %s is killed by %s.\n",
		    ctime(time()),me->query("id"),
		    killer->query("id")));
	} else {    //no obvious killer. by mon 8/17/97
	            //for example, by poison.
          if(userp(me)) {
            COMBAT_D->victim_penalty(me);
	    if(str=me->query_temp("death_msg"))  
	         //can set customized death message to death_msg.
	      str=me->name(1)+str;
	    else  str=me->name(1)+"莫名其妙地死了。\n";
            COMBAT_D->announce(me, "death_rumor", str);
	    log_file("death",sprintf("[%s] %s is killed: %s.\n",
		  ctime(time()),me->query("id"),
		  str));
          }
	}
        }

	me->remove_ride();

	if( objectp(corpse = CHAR_D->make_corpse(me, killer)) )
		corpse->move(environment(me));

	me->remove_all_killer();
	all_inventory(environment(me))->remove_killer(me);

	me->dismiss_team();
 	if (me->self_purge()) return 0;

	if( userp(me) ) {
		me->set("gin", 1);	me->set("eff_gin", 1);
		me->set("kee", 1);	me->set("eff_kee", 1);
		me->set("sen", 1);	me->set("eff_sen", 1);
		me->add("life/death_num",1);
		//here is a good point to decrease life time...weiqi,98/12/31
		if( !me->query("life/life_time") ) me->set("life/life_time", 60);
		if( !me->query("life/no_death_decrease") )
			me->set("life/life_time", (int)me->query("life/life_time")-1);
		//now we check if gameover.
		if( me->check_gameover() ) return 0;
		me->delete_temp("last_damage_from");
		me->delete_temp("last_fainted_from");
		me->delete_temp("death_msg");
		//bugbug,2002-5-14,delete all flags
		me->move(DEATH_ROOM);
		DEATH_ROOM->start_death(me);
		
	} else
		destruct(me);
		return 1;
}
