// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

void create()
{
  set_name(HIR "红玫瑰" NOR, ({ "rose" }));
  set_weight(100);
  set("long","一朵色彩艳丽的"+query("name")+"，适合女士戴着，男士么，只好闻闻就算了，戴着会让人笑话的。\n");
  set("unit", "朵");
  set("value",100000);
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 10);
  setup();
}

int init ()
{
  add_action ("do_wear", "wear");
  add_action ("do_wear", "dai");
  add_action ("do_remove", "remove");
  add_action ("do_smell", "smell");
  add_action ("do_smell", "wen");
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "rose")
    return 0;
    
  if (me->query("gender") == "男性")
  {
        tell_object(me,"你一个大老爷们戴什么花啊！也不怕人笑话！\n");
   return 1;
  }
  if (me->query("gift/rose"))
  {
        tell_object(me,"戴太多花对身体不好，我老婆说的！\n");
         return 1;
  }     

  switch (random(9))
  {
    case 0:
      { msg = "$N戴上一朵"+name+"，不禁想起年少时曾经的梦中人。\n"; break; }
    case 1:
      { msg = "$N戴上"+name+"，沉默几许……低首往事如烟。\n"; break; }
    case 2:
      { msg = "$N拿起"+name+"插在发际，婉尔一笑。\n"; break; }
    case 3:
      { msg = "$N将一朵"+name+"别在胸前，禁不住泪如雨下。\n"; break; }
    case 4:
      { msg = "$N将"+name+"别在胸前，那个熟悉的名字脱口而出。\n"; break; }
    case 5:
      { msg = "$N将"+name+"插在胸前，心里不禁一热。\n"; break; }
    case 6:
      { msg = "$N将"+name+"拿起来，忘情地一吻，然后插在胸前。\n"; break; }
    case 7:
      { msg = "$N小心地把"+name+"别在发鬏上。\n"; break; }
    case 8:
      { msg = "$N将长发轻轻一甩，将"+name+"别在上面。\n"; break; }
  }
   message_vision (msg,me);
  flower->set("wear_msg",msg);
  me->set("gift/rose",1);
  tell_object(me,"你的容貌增加了5点！\n");
  me->add("per",5);
   destruct(flower);
   return 1;
}

int do_remove (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "rose")
    return 0;

  msg = "$N将"+name+"轻轻地摘下来……\n"; 
  //message_vision (msg,me);
  flower->set("unequip_msg",msg);
  return 0;
}

int do_smell (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "rose")
    return 0;

  switch (random(9))
  {
    case 0:
      { msg = "$N闻了闻"+name+"，想起当年那好熟悉的清香味。\n"; break; }
    case 1:
      { msg = "$N低头嗅了一下"+name+"，扭过头去打了一个香香喷。\n"; break; }
    case 2:
      { msg = "$N捧着"+name+"一嗅，泪水滴在花瓣上。\n"; break; }
    case 3:
      { msg = "$N将一朵"+name+"放在鼻子下，想啊想啊……\n"; break; }
    case 4:
      { msg = "$N捧着"+name+"闻了一下：唉，今夕是何夕。\n"; break; }
    case 5:
      { msg = "$N将"+name+"捧起闻了闻，又惦记起昨天的故人。\n"; break; }
    case 6:
      { msg = "$N不禁将"+name+"轻轻一闻，思绪绵绵如窗外的细雨。\n"; break; }
    case 7:
      { msg = "$N闻了闻"+name+"，痴痴地听着窗外飘过的小雨。\n"; break; }
    case 8:
      { msg = "$N将"+name+"轻轻一嗅，不禁念道：明日天涯何处……\n"; break; }
  }
  message_vision (msg,me);
  if (me->query("gender") == "男性")
  {
        if (me->query("gift/rose"))
          tell_object(me,"闻来闻去你也不怕熏得头疼！\n");
        else
        {
          me->add("kar",3);
          tell_object(me,"你的福缘增加了三点！\n");
          me->set("gift/rose",1);
   destruct(flower);
        }
  }
  return 1;
}


