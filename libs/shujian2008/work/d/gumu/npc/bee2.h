// bee2.h
// By River 98.08.29

#include <ansi.h>
void init()
{
	object me,ob,name1;
	ob = this_player();
	me = this_object();
	name1 = ob->query("id");
	::init();
	if (interactive(ob) 
	 && !environment(ob)->query("no_fight")
	 && !(me->query_temp("gm/caimi") != name1)){
		me->set_temp("apply/attack",  random(30));
		me->set_temp("apply/dodge",  random(30)); 
		if (!me->query_temp("skillset1")){
			ob->start_busy(1);
			remove_call_out("dest");
			call_out("dest",240);
			me->set_leader(ob);
			remove_call_out("do_clone");
			call_out("do_clone", 0, me, ob);
		}
		else {
			ob->start_busy(1);
			me->set_leader(ob);
			remove_call_out("dest");
			call_out("dest",240);
			remove_call_out("kill_ob");
			call_out("kill_ob", 0, ob); 
		}
	} 
}       

int do_clone(object me, object ob)
{
	int k_qi,k_jing;
	k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
        
	me->set("max_qi",k_qi*3/5);
	me->set("eff_qi",k_qi*3/5);
	me->set("qi",k_qi*3/5);
	me->set("max_jing",k_jing*3/5);
	me->set("eff_jing",k_jing*3/5);
	me->set("jing",k_jing*3/5);
	me->set_name("玉蜂", ({ ob->query("id")+"'s bee","yu feng", "bee","feng" }) );

	me->set_temp("skillset1",1);   
	me->set_leader(ob);
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, ob); 
	return 1;
}

void dest()
{
	object me;
	me = this_object();
	write("\n"+me->query("name")+"拍拍翅膀，转身飞走了。\n",me);
	destruct(this_object());
}
