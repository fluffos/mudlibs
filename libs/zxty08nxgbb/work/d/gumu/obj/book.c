#include <ansi.h>
inherit ITEM;

void create()
{
     set_name(HIB"玉女心经  进阶篇"NOR, ({
              "yunu jing",
              "book"
             }));
     set_weight(200);
     if (clonep())
     set_default_object(__FILE__);
     else {
     set("unit", "张");
     set("long", 
     "这是一张薄薄的丝绢，上面描绘了些文字和图象，是用来修习玉女
心经的古墓秘芨。\n");
     set("value", 600);
     set("material", "paper");
     setup();
}
}
void init()
{
   add_action("do_xiuxi", "xiuxi");
}

int do_xiuxi(string arg)
{
   object me = this_player();

   if (arg && id(arg))
{  if ((int)me->query("qi") < 30)
   return notify_fail("你需要休息一会，等会再研习吧。\n");
   message_vision("$N对着薄薄的丝绢开始研习古墓内功心法。\n", me);
   if (me->query_skill("yunu-xinjing", 1) < 30)
   return notify_fail("玉女素心经的初级篇你还未研习通透，无法领悟更上层的武功。\n");
   if (me->query_skill("yunu-xinjing", 1) > 100)
   return notify_fail("你的玉女心经精进一层，可以双人合修玉女神功了。\n");
   me->improve_skill("yunu-xinjing", (int)((me->query_int())/(1+random(1))));
   me->receive_damage("jing", 40);
   me->receive_damage("jingli", 15);
   return 1;
}
   write("你要研习什么? \n");
   return 1;
}

