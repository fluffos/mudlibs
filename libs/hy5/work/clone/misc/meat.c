
//  meat.c
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("烤肉", ({ "fried meat", "meat" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一串香喷喷的烤肉\n");
                set("unit", "串");
                set("value", 3);
                set("food_remaining", 8);
                set("food_supply", 8);
                set("material", "bone");
                set("decayed",0);
        }
        setup();
}
void eat_decayed(object me)
{
   int waittime;
object obj=this_object();
if (!me) return;

this_object()->set("decayed",0);
this_object()->delete("decayed");
   waittime=10-me->query_con()/10;
   if (waittime<3) waittime=3;
   me->start_busy(waittime);
   me->add("jing",-me->query("jing")/10);
   me->add("qi",-me->query("qi")/10);
   me->add("eff_jing",-me->query("eff_jing")/10);
   me->add("eff_qi",-me->query("eff_qi")/10);

message_vision("$N将剩下的$n吃得干干净净。\n", me, obj);
   message_vision("$N忽然觉得肚子里咕嘟咕嘟直响，找了块干净地方就蹲了下来...\n呜，好臭！\n", me);
destruct(this_object());
   return;
}
void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   int foo;
object obj=this_object();
object me=this_player();
//   foo=::do_eat(arg);
//   if (!foo) return foo;
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");
   obj->set("value", 0);
    obj->add("food_remaining", -1);
me->add("food", obj->query("food_supply"));            
    if( !obj->query("food_remaining") 
    && !obj->query("decayed")) {
	     obj->delete_temp("apply/long");
	     if((string)obj->query("finish_msg"))
	           message_vision(obj->query("finish_msg"), me, obj);
	     else message_vision("$N将剩下的$n吃得干干净净。\n", me, obj);
		   destruct(obj);
	     } 
   if (query("decayed")<1)
       message_vision("$N觉得" + name() + "非常好吃，真想再来一串。\n", this_player());
   else
   {
     message_vision("$N觉得" + name() + "味道怪怪的。\n", this_player());
     call_out("eat_decayed",6,this_player());
   }
  return 1;
}
