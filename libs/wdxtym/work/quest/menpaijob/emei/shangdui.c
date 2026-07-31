//snowman 28/02/98
#include <ansi.h>
inherit ITEM;
int j=3;
void create()
{
        set_name("明教队伍", ({ "changfeng"}));
        set("unit", "只");
        set_weight(90000000);
        set("long", "
一只远道而来的明教弟子，看来有不少高手。中间插
着一面大旗，似乎写着“明教”二个大字。。。\n");
        set("no_get", 1);
        set("no_drop", 1);
	 set("no_put",1);
}

void init()
{ remove_call_out("aaa");
  call_out("aaa", 380, this_object());  
  add_action("do_rob", "xiaomie");
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
       return notify_fail("你胆子不小，竟敢在明教做对？\n");
   if(objectp(present("mingjiaodizi", environment(me))))
       return notify_fail("明教弟子看来武功不弱，你还是先打发了面前这个再说吧！\n");  

   message_vision(HIY"$N对着$n大吼一声："+me->name()+"在此！你们这些魔教弟子,纳命来！\n"NOR, me, ob);
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
       message_vision(HIW"$N见已经无活人，将明教首领身上的令牌拿在怀里！！\n"NOR, me);    
       ;    
       obj=new(__DIR__"red");
       obj->move(me);
       obj->set("owner", me->query("id"));
       me->add("combat_exp", 200);
       me->add("shen", 100);
	tell_object(me,"你被奖励了\n二百点修为值。\n");
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

