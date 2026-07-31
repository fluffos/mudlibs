// sl_lunzhi.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object ob;

        seteuid(getuid());
        if (duration < 1)
	{
		tell_object(me,HIY"你轮值的时间已到，快回去复命(lunzhi ok)吧！\n" NOR);
                return 0;
        }
	if (!duration) return 0;
		
		
		tell_object(me,HIY"你正在轮值，警惕的看着周围！好像有点动静！\n" NOR);
  	 if( duration%2==0 
                 && environment(me)->query("short")!="渡船"
		 &&!environment(me)->query("no_fight")
		 && !me->is_fighting())
       {  me->start_busy(2);
       			tell_object(me,HIY"你正在轮值，警惕的看着周围！好像有点动静！\n" NOR);
          call_out("zuji", 0, me);    
     
	 }		
		
	me->apply_condition("sl_lunzhi", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
void zuji(object me)
{   
	object obj; 
	int maxpot;
	int maxexp;
	int maxskill;
        if (!me) return;
	maxskill=me->query_skill("force");
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp");
        if (maxskill<5)
        maxskill=5;
   	if(random(10)>6)
	{obj=new("/quest/menpaijob/lingxiao/wudang2"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"武当派弟子"NOR);     
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N狂笑道：今天我要见识见识你们南少林有什么厉害?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
	}
	else
		{
obj=new("/quest/menpaijob/lingxiao/emei2"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIG"峨嵋派弟子"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N狂笑道：今天我要见识见识你们南少林有什么厉害?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
	obj->kill_ob(me);

}
}

