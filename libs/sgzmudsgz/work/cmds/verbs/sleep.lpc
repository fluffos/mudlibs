// sleep.c by fire on Jan 1999
inherit VERB_OB;

void wake(string p_id)
{
	object o=find_body(p_id);
	if(!objectp(o))
		return;
	o->simple_action("$N睡醒了，这一觉真舒服呀。\n");
	return;
}
void do_sleep()
{
   object env;
   int hp;
   int sleeptime=10+random(20);
   int food,drink;

   string p_id=this_body()->query_id()[0];
   env=environment(this_body());
   if(!env->is_bed())
   {
	   write("先找张床再睡。\n");
	   return;
   }
   food=this_body()->query_sg_food();
   drink=this_body()->query_sg_drink();
   if(!food)
   {
	   write("你太饿了，睡不着呀。\n");
	   return;
   }
   if(!drink)
   {
	   write("你口渴得利害，实在难以入睡。\n");
	   return;
   }

   hp=this_body()->query_cur_max_hp();
   this_body()->set_cur_hp(hp);
   hp=this_body()->query_cur_max_mp();
   this_body()->set_cur_mp(hp);

   this_body()->start_busy(sleeptime, "你正在梦乡中。\n");
   this_body()->simple_action("$N一头倒到床上，呼呼大睡起来。\n");
   call_out("wake",sleeptime+1,p_id);
}
mixed * query_verb_info()
{
    return ({ ({ ""}) });
}


