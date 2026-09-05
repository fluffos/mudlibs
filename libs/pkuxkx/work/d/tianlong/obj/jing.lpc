#include "/d/tianlong/bonus.h"

inherit ITEM;
void create()
{
        set_name("佛经", ({ "fo jing", "jing" }));
        set_weight(600);
        set("bonus",2+random(3));
        set("is_fo_jing",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", " 这是一本佛经，要被送给捐了一笔钱给天龙寺的居士。\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name": "buddhism",
                        "exp_required": 10000,
                        "jing_cost":    50,
                        "difficulty":   30,
                        "max_skill": 20

                ]) );
            }
        
  }

  void init()
  {
      add_action("do_song","song");
  }

  int do_song(string arg)
  {
      object me=this_player();
      object env=environment(me);
      object target;
      if (me->is_busy()||me->is_fighting())
      {
          tell_object(me,"你正忙着呢。\n");
          return 1;
      }
      if (!me->query_temp("tlnewbiejob/adv1/pin"))
      {
          tell_object(me,"拾金不昧才是好孩子。\n");
          return 1;
      }
      if (!arg)
      {
          tell_object(me,"你要送给谁啊？\n");
          return 1;
      }
      if (!present(arg,env))
      {
          tell_object(me,"你要送给谁啊？\n");
          return 1;
      }
      target=present(arg,env);
      if (target->query("pin")!=me->query_temp("tlnewbiejob/adv1/pin"))
      {
          tell_object(me,"这不是你要送佛经的居士。\n");
          return 1;
      }
      message_vision("$N恭恭敬敬地把一卷"+this_object()->query("name")+"送给了"+target->name()+"。\n",me);
      bonus(me);
      destruct(this_object());
      return 1;
  }

