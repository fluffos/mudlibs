//mixin Zine Nov 11 2010
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIW"特赦信"NOR , ({"teshe xin","letter", "xin"}));
  set_weight(500);

  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "张");
    set("value", 0);
    set("long","这是一张官府开出的特赦信，使用后(yong)可以消除通缉状态。\n");
    set("no_store", 1);
    set("no_sell", 1);
    set("no_pawn",1);
    set("no_put",1);
    set("is_map",1);
  }
  setup();
  call_out("dest",200);
}

int dest()
{
	if (this_object())
    {
	    destruct(this_object());
    }
	return 1;
}


void init()
{
   int i,count=0;
   object* all=all_inventory(environment());
   add_action("do_yong","yong");
   for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("id")=="teshe xin")
        {
            count=count+1;
            if (count==2)
            {
                if (all[i]!=this_object())
                {
                    destruct(all[i]);
                    count=count-1;
                }
            }
        }
    }
    
    return;
}

int do_yong()
{
    object me=this_player();
    object ob=this_object();
    me->apply_condition("killer",1);
    tell_object(me,"官府特赦信已经送达各处，再过一会你就不会被通缉了。\n");
    destruct(ob);
    return 1;
}