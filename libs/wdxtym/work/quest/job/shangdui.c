//snowman 28/02/98
#include <ansi.h>
inherit ITEM;
int j=3;
void create()
{
        set_name("长风镖队", ({ "changfeng"}));
        set("unit", "只");
        set_weight(90000000);
        set("long", "
一只远道而来的镖队，上面堆满了货物。中间插
着一面镖旗，似乎写着“长风镖局”四个大字。。。\n");
        set("no_get", 1);
        set("no_drop", 1);
	 set("no_put",1);
}

void init()
{ remove_call_out("aaa");
  call_out("aaa", 120, this_object());  
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
   arg = query("arg");

   if(!living(me)) return 0;
   if(!me->query_temp("rob_start")) 
       return notify_fail("你胆子不小，竟敢在长风镖局头上打注意？\n");
   if(objectp(present("biaoshi", environment(me))))
       return notify_fail("护镖镖师看来武功不弱，你还是先打发了面前这个再说吧！\n");  

   message_vision(HIY"$N对着$n大吼一声："+me->name()+"在此！留下你们的钱财来！\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
   me->start_busy(3);
   remove_call_out("make_bs");
   call_out("make_bs", 1, me, ob); 
   return 1;     
}
void make_bs(object me, object ob)
{
   object obj, obj1;
	if (j>0){
	  obj = new(__DIR__"biaoshi");
         obj->move(environment(me));
	  obj->do_copy(me);
         obj1 = new(__DIR__"biaoshi");
         obj1->move(environment(me));
 	  obj1->do_copy(me);
          j=j-1;     }
else {
       message_vision(HIW"$N见已经无人保护，将所带的财物全都拿在怀里！\n"NOR, me);    
       obj=new(__DIR__"red");
       obj->move(me);
       obj->set("owner", me->query("id"));
       me->add("combat_exp", 100);
       me->add("shen", -100);
	tell_object(me,"你被奖励了\n一百点修为值。\n");
       me->delete_temp("rob_start");
       me->delete_temp("xx_rob");
       me->delete_temp("rob_job");
       me->delete_temp("j");       
       message_vision("$N转过几个小山丘就不见了。\n",ob);
       destruct(ob);
    }
}

void aaa(object me)
{
       message_vision("$N转过几个小山丘就不见了。\n",me);       
       destruct(me);
       return;
}

