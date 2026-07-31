// sanjie wujiang0.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "乌江边");
  set ("long", @LONG

		枭		乌
		雄		江
		项		自
		羽		刎
	
滚滚乌江东逝水，浪花淘尽英雄，几番成败转头空，都付于
笑谈中。一代枭雄项羽就是自刎在此，后人为了纪念他，还
特意做了一个石像。
LONG);

  set("exits", ([
  "east" : __DIR__"wujiang1",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_swim", "swim");
        add_action("do_koujian", "koujian");
}

int do_swim()
{
        object  me, horse;
	me = this_player();

message_vision(HIY "$N纵身一跃，跳入海中。只见$N使足了全身力气，手足并用，不一会儿就游到了对岸。\n" NOR, me);
        me->move("/d/changan/eastseashore");
        message_vision(HIY "只见$N浑身湿漉漉地从海里爬了上来。\n" NOR, me);
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}

int do_koujian (string arg)
{
  object me = this_player();
  object xiangyu = present("xiang yu",environment(me));

  if (arg != "xiangyu")
  {
    message_vision("只见$N伏下身去……\n",me);
    tell_object(me,"你想叩见谁？\n");
    return 1;
  }  

  message_vision("只见$N伏下身去喊道："+
                 RANK_D->query_self(me)+
                 "叩见项羽先公！\n",me);

  if (xiangyu)
    message_vision("$N伸手一把将$n小鸡似的拎起来：不必不必。\n",xiangyu,me);
  else
  {
    message_vision(MAG"石碑隐隐地泛出一些紫色云雾。\n"NOR,me);
    call_out("xiangyu_appear",10+random(10),me);
  }
  return 1;
}

void xiangyu_appear(object me)
{
  object xiangyu;

  if (environment(me) != this_object())
    return;

  if (present("xiang yu",environment(me)))
    return;

  me->start_busy(10);
  xiangyu = new (__DIR__"npc/xiangyu");
  xiangyu->move(environment(me));
  message_vision(MAG"一阵紫色云雾聚在一起，慢慢凝做$N。\n"NOR,xiangyu);
}
