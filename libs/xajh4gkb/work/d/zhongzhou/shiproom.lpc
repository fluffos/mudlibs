#ifndef SHIPDIR
#define SHIPDIR __DIR__"NODEFINE"
#endif

#ifndef FROM
#define FROM __DIR__"NODEFINE"
#endif

#ifndef TO
#define TO __DIR__"NODEFINE"
#endif

#include <ansi.h>


void init()
{
	object here;
	
	add_action("do_yell","yell");
	
	here = load_object(FROM);
	if(strsrch(here->query("short"),"江")!=-1)
		add_action("do_du","dujiang");
	else
		add_action("do_du","duhe");
}

int do_yell(string arg)
{
	object ship,here,me;
	int force;
	
	ship=find_object(SHIPDIR);
	ship=load_object(SHIPDIR);
	me=this_player();
	here=environment(me);
	force=me->query("neili");
	
	if(!arg||arg!="boat") return notify_fail("你要喊叫什么?\n");
	if(force<=500) message_vision("\n$N使足了力气喊道：「船家～～～!」\n",me);
	else if(force<=1000) message_vision("\n$N用力喊道：「船家～～～!」声音远远传了出去。\n",me);
	else if(force<=2000) message_vision("\n$N鼓足中气用力喊道：「船家～～～!」声音远远传了出去。\n",me);
	else message_vision("\n$N高声喊道：「船家～～～!」声音悠扬,经久不息。\n",me);
	if(!ship)
		return notify_fail("你发现船不见了，快报告巫师吧！\n");
	if(ship->query("yell"))
		if(ship->query("exits/out")==FROM)
			return notify_fail("快上来吧,船马上就开了!\n");
	else return notify_fail("\n艄公喊道：「等等啊～～～一会就来了～～～～」\n\n");
	ship->set("yell",1);
	ship->set("exits/out",FROM);
	here->set("exits/enter",SHIPDIR);
	tell_object(here,"\n艄公说道：「客官,让您久等了,快请上船吧!」\n");
	tell_object(here,"艄公放下舢板，搭在了岸边（enter）。\n\n");
	call_out("on_board",10,me,ship,here);
	return 1;
}

void on_board(object me,object ship,object here)
{
   tell_object(ship,"艄公喊道：「各位客官坐好,开船了～～～～」\n");
   tell_object(here,"艄公喊道：「各位客官坐好,开船了～～～～」\n");
   ship->delete("exits");
   here->delete("exits/enter");
   call_out("leave_ship",30,me,ship);
   remove_call_out("on_board");
}

void leave_ship(object me,object ship)
{
	object here;
	
	ship->set("exits/out",TO);
    here=load_object(TO);
	tell_object(ship,"艄公说道：「客官,到岸了,下船吧!」\n");
	
	call_out("no_ship",1,ship,here);
	remove_call_out("leave_ship");
}

void no_ship(object ship,object here)
{
   object *ob;int i;
   ob=all_inventory(ship);
   for(i=0;i<sizeof(ob);i++)
   {
	   if(living(ob[i])){
	   	   message_vision("\n$N听了艄公的话，走下了船。\n",ob[i]);
	   	   tell_object(here,ob[i]->name()+"从船上走了下来。\n");
		   ob[i]->move(here);
	   }
	   else
	   {
		   tell_object(ship,"艄公一脚把"+ob[i]->name()+"踹下船!\n");
		   tell_object(here,"艄公一脚把"+ob[i]->name()+"踹下船!\n");
		   ob[i]->move(here);
	   }
   }
   ship->delete("exits");
   ship->delete("yell");
   //here->delete("exits/enter");
   remove_call_out("no_ship");
}

int do_du()
{
	object ob;object where;
  	ob=this_player();
  
  	if(environment(ob)->query("no_duhe"))
  		return 0;
  
  	if(ob->is_busy())
  		return notify_fail("你正忙着呢，等会吧！\n");
 	if(ob->query_temp("track"))
 		return notify_fail("你正赶着盐车，现在无法渡江。\n");
  	if(ob->query("max_neili")<2000)
  		return notify_fail("你的内力不足以使用这种轻功！\n");
  	if(ob->query("neili")<200)
  		return notify_fail("你的内力不足以使用这种轻功！\n");
  	if(environment(ob)->query("exits/enter"))
  		return notify_fail("有船不做，扮什么COOL啊！\n");
  	if(ob->query("neili")<210)
  		message_vision(HIW"$N"+HIW+"身形轻轻一晃，向对岸纵去！\n"NOR,ob);
  	else 
  	if(ob->query("neili")<250)
  		message_vision(HIG"$N"+HIW+"身形宛如行云流水，向对岸轻飘过去！\n"NOR,ob);
  	else 
  		message_vision(HIC"$N"+HIC+"身形微微一晃，清烟般地朝对岸飘了过去！\n"NOR,ob);
  	ob->add("neili",-200);
  	where=load_object(SHIPDIR);
  	ob->move(where);
  	message_vision(HIG"$N"+HIG+"脚轻轻一踏船头，借力又向前纵去！\n"NOR,ob);
  	where=load_object(TO);
  	ob->move(TO);
  	message_vision(HIG"$N"+HIG+"飘然落地，轻轻地嘘出了一口真气。\n"NOR,ob);
  	ob->start_busy(1);
  	return 1;
}