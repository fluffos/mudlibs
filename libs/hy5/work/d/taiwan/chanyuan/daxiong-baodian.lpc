
#include <ansi.h>
inherit ROOM;

int do_ketou();
void create ()
{
  set ("short",HIY"大雄宝殿"NOR);
  set ("long", @LONG
这里是净念禅院的大雄宝殿，正中央供奉着如来佛组，佛像巨大，
浑身闪着金色的光芒。宝殿的两旁排列着罗汉象，形态各异。这里香气
缭绕，给人一重静谧的感觉。旁边有几个僧人在念经，还有几个人烧香
拜佛。
LONG);

  set("exits", ([ 
	  "westdown":__DIR__"shijie3",
	  "eastdown":__DIR__"shilu3",
	  "northup":__DIR__"changlang2",
          "south":__DIR__"changlang4",
         ]));
  set("objects",([
    __DIR__"npc/foxiang":1,
    ]));
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_ketou","ketou");
}

int do_ketou()
{
    object me;
    me=this_player();
    if(me->is_fighting())
    return notify_fail("你先打完仗再说吧！\n");
    if(me->is_busy())
    return notify_fail("你正忙着呢！\n");
    message_vision("$N看着佛像，口中念念有词，跪下身去，磕了一个头。\n",me);
    me->add("bellicosity",-20);
    if(me->query("bellicosity")<0)
    me->set("bellicosity",0);
    me->add("sen",-10-random(10));
    me->start_busy(2);
    return 1;
}
