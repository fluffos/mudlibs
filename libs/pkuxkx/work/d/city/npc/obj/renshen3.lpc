#include <ansi.h>

inherit ITEM;

void create()
{
              set_name(HIG"千年人参"NOR, ({"qiannian renshen", "renshen", "shen", }));
              set_weight(20);
              if (clonep())
                set_default_object(__FILE__);
              else {
                set("unit", "棵");
                set("long", "产自长白山的千年人参，甘、微寒、无毒，大补元气，复脉固脱。\n");
              set("value", 0);
              }
			  set("drugcode",39);
              setup();
}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

int do_eat(string arg)
{
              object me=this_player();
              if(!id(arg))
                return 0;
              if (me->is_busy())
              	{
              		tell_object(me,"你忙着呢，根本腾不开手。\n");
              		return 1;
              	}                 
              if (base_name(environment(me))[0..10] == "/d/xiakedao")
                return notify_fail("什么？\n");  
              if (time()-me->query_temp("last_eat_renshen")<180)
              {
               tell_object(me,"等等，你上次吃的人参效果还没有完全发挥呢。\n");
               return 1;
               }
              me->set_temp("last_eat_renshen",time());                              
          if( me->query("max_neili")<5000)
              me->set("neili", me->query("max_neili")+random(50));
          else
              me->set("neili", 5000+random(50));   
              message_vision("$N服下一棵$n，经脉各处内息充盈多了。\n", me, this_object());
        
              destruct(this_object());
              return 1;
}
