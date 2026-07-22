//snowman 28/02/98
#include <ansi.h>
inherit ITEM;

mapping *dest = ({
([ "name":"yilihe",
           "context": ({
		"/d/xingxiu/yili/yili","/d/xingxiu/shanjiao","/d/xingxiu/silk9","/d/xingxiu/silk8","/d/xingxiu/silk7",
		"/d/xingxiu/silk6","/d/xingxiu/silk5","/d/xingxiu/silk4","/d/xingxiu/silk3","/d/xingxiu/silk2",
		"/d/xingxiu/silk1","/d/xingxiu/silk",
})]),

([ "name":"jygw",
           "context": ({
		"/d/xingxiu/silk","/d/xingxiu/silk1","/d/xingxiu/silk2","/d/xingxiu/silk3","/d/xingxiu/silk4",
		"/d/xingxiu/silk5","/d/xingxiu/silk6","/d/xingxiu/silk7","/d/xingxiu/silk8","/d/xingxiu/silk9",
		"/d/xingxiu/shanjiao","/d/xingxiu/yili/yili",
})]),
([ "name":"silk",
           "context": ({
		"/d/xingxiu/silk1","/d/xingxiu/silk2","/d/xingxiu/silk3","/d/xingxiu/silk4","/d/xingxiu/silk5a",
		"/d/xingxiu/silk7a","/d/xingxiu/silk7","/d/xingxiu/silk8","/d/xingxiu/silk9","/d/xingxiu/shanjiao",
		"/d/xingxiu/yili/yili",
})]),
([ "name":"silk1b",
           "context": ({
		"/d/xingxiu/silk1","/d/xingxiu/silk2","/d/xingxiu/silk3","/d/xingxiu/silk3a","/d/xingxiu/silk3b",
		"/d/xingxiu/silk3c","/d/xingxiu/silk7a","/d/xingxiu/silk7","/d/xingxiu/silk8","/d/xingxiu/silk10",
		"/d/xingxiu/yili/yili",
})]),
([ "name":"yili",
           "context": ({
		"/d/xingxiu/silk10","/d/xingxiu/silk8","/d/xingxiu/silk7","/d/xingxiu/silk7a","/d/xingxiu/silk5a",
		"/d/xingxiu/silk4","/d/xingxiu/silk3","/d/xingxiu/silk2","/d/xingxiu/silk1","/d/xingxiu/silk1a",
		"/d/xingxiu/silk1b","/d/xingxiu/silk",
})]),
([ "name":"shanjiao",
           "context": ({
		"/d/xingxiu/silk9","/d/xingxiu/silk8","/d/xingxiu/silk7","/d/xingxiu/silk7a","/d/xingxiu/silk3c",
		"/d/xingxiu/silk3b","/d/xingxiu/silk3a","/d/xingxiu/silk3","/d/xingxiu/silk2","/d/xingxiu/silk1",
		"/d/xingxiu/silk",
})]),
([ "name":"silk5b",
           "context": ({
		"/d/xingxiu/silk5","/d/xingxiu/silk5a","/d/xingxiu/silk7a","/d/xingxiu/silk3c","/d/xingxiu/silk3b",
		"/d/xingxiu/silk3a","/d/xingxiu/silk3","/d/xingxiu/silk2","/d/xingxiu/silk1","/d/xingxiu/silk1a",
		"/d/xingxiu/silk1b","/d/xingxiu/silk",
})]),
([ "name":"silk3a",
           "context": ({
		"/d/xingxiu/silk3b","/d/xingxiu/silk3c","/d/xingxiu/silk7a","/d/xingxiu/silk5a","/d/xingxiu/silk5",
		"/d/xingxiu/silk6","/d/xingxiu/silk7","/d/xingxiu/silk8","/d/xingxiu/silk9","/d/xingxiu/shanjiao",
		"/d/xingxiu/yili/yili",
})]),
([ "name":"silk8",
           "context": ({
		"/d/xingxiu/silk7","/d/xingxiu/silk6","/d/xingxiu/silk5","/d/xingxiu/silk5a","/d/xingxiu/silk7a",
		"/d/xingxiu/silk3c","/d/xingxiu/silk3b","/d/xingxiu/silk3a","/d/xingxiu/silk3","/d/xingxiu/silk2",
		"/d/xingxiu/silk1","/d/xingxiu/silk",
})]),
});

void create()
{
	set_name("骆驼商队", ({ "shangdui"}));
	set("unit", "只");
	set("location", 1);
	set_weight(900000);
	set("long", "一只远道而来的骆驼商队，骆驼背上堆满了货物。\n"+
			"商人们手中提着一些布袋，看来是比较重要的东西。。。\n");
	set("no_get", 1);
	set("no_drop", 1);
}

void init()
{
  	call_out("destroying", 20, this_object());  
  	add_action("do_rob", "qiang");
}

int do_rob()
{
   	object me, ob;   
   	string arg;
   	int stage, i;
   	
   	me = this_player();
   	ob = this_object();
   	stage = 0;
   	i = sizeof(dest);
   	arg = query("arg");

   	if(!living(me)) return 0;
   	
	if( query_temp("robber") != me ) 
		return notify_fail("你这奸贼，竟敢光天化日之下拦截商队，不怕被打入天牢吗？\n");

	if( objectp(present("hubiao biaoshi", environment(me))) )
		return notify_fail("护镖镖师看来武功不弱，你还是先打发了面前这个再说吧！\n");  

	message_vision(HIY"$N对着$n大吼一声：星宿"+me->name()+"在此！留下你们的钱财来！\n"NOR, me, ob);
	me->set_temp("xx_rob", 1);
	if(!ob->query("going")){
		while (i--) if (arg == dest[i]["name"]) break;
		remove_call_out("go_stage");
		ob->set("f", 6 * (me->query_temp("xx2/j")+1));
		call_out("go_stage", 1, ob, stage, i, sizeof(dest[i]["context"]), me);   
		ob->set("going", 1);
	}
	remove_call_out("make_bs");
	call_out("make_bs", 1, me, ob); 
	return 1;     
}

void make_bs(object me, object ob)
{
   	object obj, obj1;
    	int j;
   	j = me->query_temp("xx2/j");
   	if(j>0){        
         	obj = new(__DIR__"biaoshi");
         	obj->move(environment(me));
         	obj->do_copy(me);
         	obj1 = new(__DIR__"biaoshi");
         	obj1->move(environment(me));
         	obj1->do_copy(me);
         	me->add_temp("xx2/j", -1);
         	return;      
        }
        
   	else{
       		message_vision(HIW"$N见已经无人保护，在$n的威胁下，只得停了下来，将所带的财物乖乖地献上！\n"NOR, ob, me);    
       		obj=new("/d/xingxiu/obj/red");
       		obj->move(me);
       		obj->set("owner", me->query("id"));
       		me->add("shen", -(me->query("combat_exp")/20));
       		me->delete_temp("xx_rob");
       		message_vision("$N带着骆驼，转过几个小山丘就不见了。\n", ob);
       		destruct(ob);
       }       
}

void go_stage(object me, int stage, int i, int size, object player)
{
   	object where;
   	int f = me->query("f");
   	
   	if(stage < size && objectp(player)) {
     		message_vision(HIY"$N匆匆忙忙地向有驻军的关口方向逃去。\n"NOR, me);
     		me->move(dest[i]["context"][stage]);
     		message_vision(HIY"$N匆匆忙忙地奔了过来。\n"NOR, me);
     		where = environment(me); 
     		tell_object(player, HIM+me->query("name")+"好象逃往了"+(string)where->query("short")+HIM"一带。\n"NOR);
     		call_out("go_stage", f, me, ++stage, i, size, player);
     	}
   	else {    
   		if(objectp(player)){
     			tell_object(player, HIM+me->query("name")+HIM"成功地逃进了城镇。\n"NOR);
     			player->delete_temp("xx2");
     			player->delete_temp("xx_rob");
     		}
     		
     		message_vision(MAG"\n$N转进关中，在官兵的护送下离开了。\n"NOR,me);      
     		destruct(me);
     	}
}

void destroying(object me, int i)
{
	if( i ){
		message_vision("$N带着骆驼，转过几个小山丘就不见了。\n", me);       
       		destruct(me);
       		return;
       	}
       	
   	if(!me->query("going")){
       		message_vision("$N带着骆驼，转过几个小山丘就不见了。\n", me);       
       		destruct(me);
       		return;
       	}
  	else call_out("destroying", 450, me, 1);
}
