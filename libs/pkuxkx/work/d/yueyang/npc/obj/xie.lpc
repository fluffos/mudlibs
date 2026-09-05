//newmap Zine Nov 11 2010
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "李保长的一只鞋" , ({"xie","shoe"}));
  set_weight(500);

  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("value", 0);
    set("long","这是李保长的一只鞋，他希望你能在城里找到(zhao)他的另一只鞋。\n");
    set("no_store", 1);
    set("no_sell", 1);
    set("no_pawn",1);
    set("no_put",1);
  }
  setup();
}

void init()
{
   add_action("do_zhao","zhao");
}


int do_zhao()
{
    object me=this_player();
    object ob=this_object();
    object room=environment(me);
    object xie;
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
    }
    if(query("owner") != me->query("id"))
    {
    	return notify_fail("你捧着别人的臭鞋干嘛？。\n");
    }
    if (room->query("shoesearch")!=me->query("id"))
    {
        tell_object(me,"你仔细找了半天，却没有发现李保长的另一只鞋！\n");
        me->add_busy(2);
        return 1;
    }
    else
    {
        xie=new("/d/yueyang/npc/obj/xie2");
        xie->set("owner",me->query("id"));
        xie->move(me);
        tell_object(me,"你眼前一亮，发现了一双一模一样的鞋，正好凑成一对。\n");
        tell_object(me,"赶紧把它送还给李保长吧。\n");
        destruct(this_object());
        return 1;
        
    }
    
}