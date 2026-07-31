#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED+"中秋月饼"+NOR, ({"cake",}));
    set_weight(20000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "一块小小的中秋月饼，香喷喷的让人直流口水，你恨不得马上吃(eat)下去。\n");
    set("value", 1);
    set("no_drop", "这样的好东西你也到处乱扔？！\n");
    set("no_get", "注意点饮食卫生，不要随处捡东西吃。\n");
  }
    setup();
}
void init()
{
    add_action("do_chi", "eat");
}
int do_chi(string arg)
{
    object me = this_player();
    
  if (!id(arg))  return notify_fail("你要吃什么？\n");
  if (me->query("m_cake")) 
   message_vision(HIC "$N毛手毛脚就把小月饼往嘴里送，心里美滋滋的正想好好品尝品尝，不料手一颤，小月饼\n掉到地上，摔碎了（怎么这么不小心啊！该打）\n" NOR,me);
  else { 
   me->add("max_neili", 100);
   message_vision(HIC "$N毛手毛脚就把小月饼往嘴里送，心里美滋滋的正想好好品尝品尝，不料咕噜一声居然囫\n囵吞了下去，噎得$N好不容易才缓过气来，引得大家哄堂大笑。\n" NOR, me);
   me->set("m_cake", 1);
  }
   destruct(this_object());
   return 1;
}
void owner_is_killed() { destruct(this_object()); }
