
inherit ITEM;

void create()
{
   set_name("大树", ({ "tree" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "棵");
     set("long","这是一棵大树，上面好象有个鹰巢。\n");
   }
   
   setup();
}

int is_get_of(object ob,object obj)
{
   return notify_fail("请爱护树木！\n");
}

void init()
{
  object ob;
  
  add_action("do_claw","pa");
  
  ob=previous_object();
  
  if(!ob->query("bai_dun_quest_obj")) return;
  if(!query("no_hawk")){
    set("no_hawk",1);
    remove_call_out("hawk_come");
    call_out("hawk_come",15,ob);
  }
}

void hawk_come(object ob)
{
  if(!ob) return;
  
  tell_object(environment(this_object()),"只听一声清啸，一只鹰从树上飞下，将"+ob->name()+"叼走飞了！\n");
  destruct(ob);
  set("hawk_fly",1);
}

int do_claw()
{
   object ob;
   
   ob=this_player();
   
   if(!query("hawk_fly"))
   return notify_fail("树上有只鹰，你爬上去会啄你的！\n");
   
   message_vision("$N朝树上爬去！\n",ob);
   
   ob->move(__DIR__"shuding");
   return 1;
}