//清心散血丸
//by junhyun@SK
#include <ansi.h>

inherit ITEM;
int do_eat(string);
void create()
{
  set_name(HIC "清心散血丸" NOR, ({"qingxin wan", "wan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "枚");
    set("long", "一枚碧绿色的小药丸。\n");
    set("value",1000);
    set("no_sell", 1);
  }

  setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("你要吃什么？\n");

        message_vision("$N吃下一枚清心散血丸,顿时感觉一股清凉之气透心而出，舒畅无比。\n", me);  

        me->set("bellicosity", 0);
        if ((int)me->query("bellicosity") < 0 ) { 
         me->set("bellicosity", 0);
                         }
  destruct(this_object());
  return 1;
}

