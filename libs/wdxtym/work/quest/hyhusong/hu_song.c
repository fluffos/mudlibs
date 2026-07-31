#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
     if (!duration) return 0;
  	 if( duration%2==0 
		 //&& 
		 //interactive(me) 
		 &&!environment(me)->query("no_fight")
		 && !me->is_fighting())
       {  me->start_busy(4);
          call_out("zuji", 0, me);    
     
	 }
        me->apply_condition("hu_song", duration - 1);
        return 1;
}


void zuji(object me)
{   
	object obj; 
	int maxpot;
	maxpot=me->query_temp("maxpot");
   	if(random(20)>17)
	{obj=new(__DIR__"skiller"+sprintf("%d",random(3)+1));
	 maxpot=maxpot+10+random(10);
	 obj->set("title",HIR"天字一号"NOR);
	}
	else
	{ obj=new(__DIR__"killer");
	  maxpot=maxpot-random(10);
	 }
	obj->do_copy(maxpot);
	obj->move(environment(me));
	message_vision(HIR"\n$N对着$n发出一阵阴笑声，令$n全身上下的寒毛根根竖起，不寒而栗。\n"NOR,obj,me); 
//	 if(objectp(present("gong zi", environment(me))))
//	{	obj->kill_ob(present("gong zi",environment(me)));
// 	present("gong zi",environment(this_player()))->kill_ob(obj);}

	obj->kill_ob(me);
}

string query_type(object me)
{
	return "job";
}
