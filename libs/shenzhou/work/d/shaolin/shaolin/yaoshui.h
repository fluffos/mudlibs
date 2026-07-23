//少林工作
#include <ansi.h>
void init()
{       add_action("do_yao", "yao");
}
int do_yao(string arg)
{
  int water_filled, full, aa;
  object ob;
  object me = this_player();
  aa = random(50);
  if ( arg != "shui" )
     return notify_fail("你要干什么？\n");
  if( !(ob=present("shui piao", me)) )
     return notify_fail("没有水瓢，你怎么打水？\n");  
  if ( arg = "shui" )  
{if (me->is_busy())
     return notify_fail("你正忙着呢！\n");
  if (ob->query("water_filled"))
          return notify_fail("水瓢里已经有水了。\n");
     message_vision("$N从河中舀起一瓢清澈的河水。\n",me);
     me->receive_damage("jingli", (10+ random(5)));
     ob->set("full", 1);
     ob->set("water_filled", 1);  
     me->start_busy(2+ random(2));
return 1;}
}



