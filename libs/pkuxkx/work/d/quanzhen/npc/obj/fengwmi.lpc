//feng wang mi.c
//made by kiss

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void init()
{
   add_action("do_eat","eat");
 }
 
void create()
{
  set_name("蜂王蜜",({"feng wang mi","mi"}));
  set_weight(100);
  if( clonep() )
      set_default_object(__FILE__);
   else 
  {
    set("unit","瓶");
    set("long","这是一瓶新鲜的蜂王蜜.\n");
    set("value",1000);
    setup();
  }
}

int do_eat(string arg)
 {  
    object me;
    me = this_player();
    if(!id(arg))
    return notify_fail("你要吃什么？\n");
    if ( me->query("family/family_name") != "全真派" )
      return notify_fail("蜂王蜜只能由全真弟子享用。\n");
    if (me->query("mud_age")<86400||me->query("combat_exp")<5000)
      return notify_fail("你年纪还小,吃这等宝物恐怕也纳用不了.\n");
   this_player()->add("max_neili",1);
   this_player()->add("max_jingli",1);
  message_vision("$N喝下一瓶蜂王蜜，只感觉全身好象脱胎换股，精神为之一振!\n",this_player());
    destruct(this_object());
   return 1;
  }
