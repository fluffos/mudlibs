#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "瞌睡虫" , ({"keshui chong", "chong"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("long", "一只灵巧的瞌睡虫，正闪着两只眼睛奇怪地盯着你。\n");
    set("value", 60000);
  }
  set("is_monitored",1);
  setup();
}

void init()
{
  add_action("do_apply", "apply");
  add_action("do_apply", "fang");
}

int do_apply(string arg)
{
  object me = this_player();
  object where = environment(me);
  object ob;

  if (! arg)
    return notify_fail ("你要拿瞌睡虫做什么？\n");

  ob = present (arg,where);
  if (! ob)
    return notify_fail ("你要拿瞌睡虫往谁身上放？\n");
  
    if (userp(ob))
    return notify_fail ("你要拿瞌睡虫往谁身上放？玩家可不行.\n");
  
  if (! living(ob))
    return notify_fail ("你要拿瞌睡虫往谁身上放？\n");
  
  if (me == ob)
    return notify_fail ("你要拿瞌睡虫往自己身上放？\n");
// 44    if ((userp(ob))&& (int)me->query("max_neili")<(int)ob->query("max_neili")*2)
  if (userp(ob))
    {
       return notify_fail ("瞌睡虫被对方的法力圈一逼，又飞了回来。\n");
    
    }

  // mon 4/11/98
  if(where->query("no_fight") && where->query("no_magic"))
      return notify_fail ("在安全区用瞌睡虫可不太好吧！\n");

  if (this_object()->query("is_climbing"))
    return notify_fail ("瞌睡虫正在爬呢。\n");

  message_vision ("$N静悄悄地拿出一只瞌睡虫，往$n身上一放。\n",me,ob);
  message_vision ("瞌睡虫迅速地爬进$N的鼻孔里。\n",ob);
  this_object()->move(ob);  
  this_object()->set("is_climbing",1);
  call_out("applying",1+random(10),ob);  
  return 1;
}

void applying (object ob)
{
  if (! ob)
    return;

//  message_vision ("$n迅速地爬进$N的鼻孔里。\n",ob,this_object());
  message_vision ("$N忍不住打了一个哈欠，满脸睡意。\n",ob);

  if ((userp(ob) || ob->query("can_sleep")) && random (2)==0) {
    //mon 12/18/97 to allow player sleep.
    ob->set_temp("force_sleep",1);
    if( !userp(ob)) ob->command_function("sleep");    
    if( !userp(ob)) ob->command("sleep");    
    if( !userp(ob)) ob->force_me("sleep");    
     ob->set("disable_type","<睡梦中>");
     ob->set_temp("disabled",1);
     message_vision ("$N一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",ob);
    call_out("wakeup",20, ob);
    ob->delete_temp("force_sleep");
  }
  
}


void wakeup(object me)
{
        if(!me) return;
        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
       me->delete("disable_type");
       me->delete_temp("disabled");




        message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
			me->set_leader(0);
        me->set_temp("block_msg/all", 0);

 destruct (this_object());

}