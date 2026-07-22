#include <ansi.h>
inherit ITEM;
void to_rob();
void create()
{
        set_name("镖货", ({ "prize"}) );
        set_weight(3000);
        set("no_get", 1);
       set("unit", "份");
	set("long", "一个包裹，上面画着长风镖局的镖旗。\n");
	set("value", 0);
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
	set("no_steal",1);
    
}
void init()
{
	add_action("do_finish","finish");
	remove_call_out("go");
	call_out("go",10);	
}
int do_finish()
{
	object me,ob,where;
	int exp,pot;
	me=this_player();
	ob=this_object();
       where = environment(me);
	if(file_name(where) == me->query_temp("end_place"))
	 {  if(objectp(present("biaoshi", environment(me))))
		{ remove_call_out("aaa");
		call_out("aaa",3,ob);
		exp=random(200)+100;
		destruct(present("biaoshi",environment(me)));
		destruct(present("biaoshi",environment(me)));
		  pot=exp/7;
		  me->add("combat_exp",exp);
		  me->add("potential",pot);
		  me->add("shen",100);
	message_vision(HIC"突然从暗处走出一人朝$N走来，$N问道：万重千险.\n那人答 道：长风破浪。\n$N见对方对上了暗号，便把手中的镖货交给了对方。\n"NOR,me);	
	tell_object(me,"你被奖励了\n"+chinese_number(exp)+"点实战经验\n"
				+chinese_number(pot)+"点潜能\n");
	me->delete_temp("on_biao");
	me->delete_temp("end_place");
	me->delete_temp("biao_place");
		} else {remove_call_out("aaa");
		call_out("aaa",3,ob);
		exp=random(100)+100;
		  pot=exp/7;
		  me->add("combat_exp",exp);
		  me->add("potential",pot);
		  me->add("shen",100);
	message_vision(HIC"突然从暗处走出一人朝$N走来，$N问道：万重千险.\n那人答 道：长风破浪。\n$N见对方对上了暗号，便把手中的镖货交给了对方。\n"NOR,me);	
	tell_object(me,"你被奖励了\n"+chinese_number(exp)+"点实战经验\n"
				+chinese_number(pot)+"点潜能\n");
	me->delete_temp("on_biao");
	me->delete_temp("end_place");
	me->delete_temp("biao_place");

	}}
	return 1;
}
void go()
{	
		if (random(100)<15&& !environment(this_object())->query("no_fight") )
	{	if (this_object()->query_temp("tufei")<3)
		{to_rob();
		this_object()->add_temp("tufei",1);
		call_out("go",30);}
		return;
	}call_out("go",10);
}
void to_rob()
{
	int i;
	object robber;
	
	message_vision(HIR"忽然间跳出一群劫匪！\n"NOR,this_object());
	for (i=0;i<=random(5)+1;i++)
	{
		robber=new(__DIR__"tufei");
		robber->move(environment(this_player()));
		robber->set_leader(this_player());
		 if(objectp(present("biaoshi", environment(this_player()))))
		{	robber->kill_ob(present("biaoshi",environment(this_player())));
			present("biaoshi",environment(this_player()))->kill_ob(robber);}
		robber->kill_ob(this_player());
		this_player()->kill_ob(robber);
	}
	
}
void aaa(object ob)
{ destruct(ob);}