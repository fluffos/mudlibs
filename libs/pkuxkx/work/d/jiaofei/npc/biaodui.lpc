//Created by whuan@pkuxkx
//投名状任务之镖队

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("镖队", ({ "biao dui","biaodui"}));
        set("unit", "支");
        set_weight(900);
        set("long", "一只远道而来的镖队，上面堆满了货物。\n"
        +"中间插着一面镖旗，似乎写着“福威镖局”四个大字。。。\n");
        set("value",1);
        set("no_get", 1);
        set("no_drop", 1);
        set("no_put",1);
}

void init()
{ 
			  add_action("do_rob", "rob");
}

int do_rob(string arg)
{
		    object me, ob;   
		    int stage, i;
		    me = this_player();
		    ob = this_object();
		    stage = 0;
		    
		    if(!living(me)) return 0;
		    if(!arg && arg!="biao dui" && arg !="biaodui")
		    	return notify_fail("你想干什么？\n"); 	
		    if(me->query("id")!=ob->query("owner")) 
		        return notify_fail("你胆子不小，竟敢在福威镖局头上打主意？\n");
		    if(objectp(present("biao shi", environment(me))))
		        return notify_fail("护镖镖师看来武功不弱，你还是先打发了面前这个再说吧！\n");  
		    
		    message_vision(HIY"$N对着$n大吼一声："+me->name()+"在此！留下你们的钱财来！\n"NOR, me, ob);
		    remove_call_out("make_bs");
		    call_out("make_bs", 1, me, ob); 
		    return 1;     
}
void make_bs(object me, object ob)
{
       object obj, obj1;
       int bsnum = 1 + me->query("jiaofei/tmz/lianxu")/3;

       if(me->query("combat_exp") < 1000000) bsnum = 1;
       
       if (!ob->query_temp("be_robbed"))
       {
         message_vision(HIW"只听有人大喝一声：大胆！居然敢在太岁头上动土！"
         +"\n从镖队里跳出"+chinese_number(bsnum)+"个镖师，对$N发起了攻击。\n"NOR, me);       	
         for(int i=0;i<bsnum;i++)
         {
              obj = new(__DIR__"biaoshi");
              obj->move(environment(me));
              obj->do_copy(me);
              obj->kill_ob(me);
         }
          ob->add_temp("be_robbed",1);   
       }
			 else 
			 {
       message_vision(HIW"$N见已经无人保护，将所带的财物全都拿在怀里，顺手将镖车砸了个稀巴烂！\n"NOR, me);    
       obj=new(__DIR__"prize");
       obj->set("owner", me->query("id"));       
       obj->move(me);
       destruct(ob);
       }
}
void destme()
{
		    remove_call_out("dest");
			  call_out("dest", 120, this_object());  
}
void dest(object me)
{
       message_vision("$N转过几个小山丘就不见了。\n",me);       
       destruct(me);
       return;
}
