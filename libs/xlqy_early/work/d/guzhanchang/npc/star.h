#include <ansi.h>

void powerup();
void full_me(object me);

void remove_killer()
{
	
	delete_temp("my_killer");	
	
}
void kill_ob(object ob)
{
  if(!query_temp("my_killer"))
  	{
       if(ob->query("9sky/number")>8) {message_vision(HIM"过了就快点离开吧～\n"NOR,ob);ob->remove_all_enemy();return 0;}
                set_temp("my_killer",ob);
          if(!wizardp(ob)) powerup();;
  		 call_out("remove_killer",900);
  	}
  else
  {
 	 if(query_temp("my_killer")!=ob)
 	 	full_me(this_object());	
  	
  }
  remove_call_out("check2");
  call_out("check2",1);
  ::kill_ob(ob);
}
void check2()
{
        object me = this_object();
        int i;
				object *emery=me->query_enemy();

        if( sizeof(emery)==0 )
        {
        remove_call_out("check2");
        full_me(me);
        return ;
        }

        if( !me->is_fighting() )
        {
        full_me(me);
        remove_call_out("check2");
        return ;
        }
				if(sizeof(emery) > 1)
				    full_me(me);
       
        remove_call_out("check2");
        call_out("check2",1);
        return;
}
void unconcious()
{
	die();
}

void powerup()
{
        object me = this_object();
        random(2)?
        me->command_function("chat 守卫九重天是我们的责任！\n"):
        me->command_function("chat 要过去要先打败我！\n");
        me->set("kee",query("max_kee"));
        me->set("eff_kee",query("max_kee"));
        me->set("sen",query("max_sen"));
        me->set("eff_sen",query("max_sen"));
        me->set("force",2*query("max_force"));
        me->set("mana",2*query("max_mana"));
        me->clean_condition();
        return;
}

void full_me(object me)
{
        me = this_object();
        me->set("kee",query("max_kee"));
        me->set("eff_kee",query("max_kee"));
        me->set("sen",query("max_sen"));
        me->set("eff_sen",query("max_sen"));
        me->set("force",2*query("max_force"));
        me->set("mana",2*query("max_mana"));
        me->clean_condition();
        return;
}

