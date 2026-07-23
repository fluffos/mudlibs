// gun.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_fly","flyup");
}

void create()
{
       set_name("飞行包", ({ "fly bag", "flybag", "bag" }) );
       set_weight(10);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "个");
               set("long", "这是一个给新手用的飞行包,你可以用fly来快速飞行。\n");
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
 }
       setup();
}

int do_fly( )
{
  object ob, myenv, where;
  ob = this_player ( ) ;
  if (ob->is_busy())
  return notify_fail("你现在正忙着呢。\n");
  if (ob->is_fighting() )
  return notify_fail("你无法在战斗中使用飞行包！\n");

  seteuid(getuid());
  where = environment(ob);
  if( ! environment(ob)->query("no_fight") )
		return notify_fail("这里不安全，不能飞。\n");

  if (ob->query("age") < 16 && environment(ob)->query("no_fight"))
  {
        message_vision("你发动了飞行包,你飞了起来。\n",ob);
        message_vision("你飞啊飞,飞了很长时间终于飞到了高空......\n", ob);
        ob->add("jing",-10);
        ob->add("qi",-10);
        myenv = environment (ob) ;
        ob->move (__DIR__"tian");
      	return 1;
  }
  else  
  message_vision("你以经这么大了,还想用飞行包??\n"
                 "飞行包是给新手跑地图用的。不是给你用来加exp的!!!\n"
                 ,ob);
  return 1;
}
