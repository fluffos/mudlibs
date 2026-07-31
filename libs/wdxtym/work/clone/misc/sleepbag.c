// sleepbag.c
inherit ITEM;
protected void wakeup(object me,object where);
protected void del_sleeped(object me);
#include <ansi.h>
void create()
{
	set_name("帐篷",({"sleepbag"}));
	set_weight(7000);
	set_max_encumbrance(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"一个帐篷，江湖人士用来在野外睡觉用的。\n");
		set("unit","顶");
		set("value", 1000);
	}
}
int is_container() { return 1; }
void init()
{
	if (environment()==this_player())
				add_action("do_sleep","sleep",1);
}
int do_sleep(string arg)
{
	int rnd;
	object me = this_player();
		object where = environment(me);
	if (arg) return 0;
		if( where->query("sleep_room") || where->query("freeze"))		 return 0;
	if( where->query("no_sleep_room"))  return 0;
		if ( me->query("family/family_name") == "丐帮") return 0;
		if (me->is_busy())
			  { write("你上一个动作未完成！\n"); return 1;}
		if( me->is_fighting() )
			  { write("战斗中睡觉？挨宰呀？\n"); return 1;}
		if (me->query_temp("sleeped"))
			  { write("你刚睡过一觉, 多睡对身体有害无益! \n");return 1;}
	message_vision("$N展开一个帐篷，钻了进去，不一会就进入了梦乡！\n",me);
	rnd=random(100/me->query_con()+10);
	where->add_temp("sleeping_person", 1);
	me->set_temp("block_msg/all",1);
	me->set_temp("sleeped",1);
	me->disable_player("<休息中>");
	if ( rnd < 1 ) rnd = 0;
	call_out("wakeup", rnd + 10, me, where);
	return 1;
}
protected void wakeup(object me,object where)
{
		while( environment(me)->is_character() )
				me->move(environment(environment(me)));
		me->enable_player();
	me->set_temp("block_msg/all",1);
	me->move(environment(me));
		me->delete_temp("block_msg");
	if ( userp(me) && (!me->query("food") || !me->query("water")) ){
				message("vision",me->name()+"一觉醒来，整个人懒洋洋的，没有半点精神。\n",environment(me),({me}));
				write("你一觉醒来，整个人懒洋洋的，没有半点精神。看来先要去找点吃的了！\n");
		}else{
				message("vision",me->name()+"一觉醒来，精力充沛地活动了一下筋骨。\n",environment(me),({me}));
				write("你一觉醒来，只觉精力充沛。该活动一下了。\n");
				me->set("qi",	me->query("eff_qi"));
				me->set("jing",  me->query("eff_jing"));
		}  
		 call_out("del_sleeped",10+random(5),me);
	if (where)
				where->add_temp("sleeping_person", -1);
		me->delete("no_get");   
		me->delete("no_get_from");	  
 
}
protected void del_sleeped(object me)
{
		if (objectp(me))
				me->delete_temp("sleeped");
}

