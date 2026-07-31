// Room: /d/pingan/chufang

#include <ansi.h>
inherit ROOM;
int do_shou(string arg);

void create ()
{
  set ("short", "菜地");
  set ("long", @LONG
这儿是平安城的菜园,是小吃店的承包的。你可以
在这里买菜,你还可以在这里（shoucai）收菜。
LONG);

set("outdoors","pingan");
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan",1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bei2",
]));

        set("objects", ([
                __DIR__"npc/caifan" : 1,
	]));
  setup();
}

void init()
{
        add_action("do_shou","shoucai");
}

int do_shou(string arg)
{
        object me=this_player(); 
        object ob,ob1;

        if (!me->query_temp("gongzuo/zuocai"))
           return notify_fail("卖菜的说道,你还是先到小吃店打个招呼吧。\n");

        if ( (int)me->query("jing")<20)
           return notify_fail("你太累了，歇息下吧。\n");

        if (me->query_temp("gongzuo/zuocai")==6)
           return notify_fail("菜收好了！\n");
   
  message_vision("$N拿起农具，开始收割起菜来。\n",me);
      me->add("jing",-(10+random(10)));
      me->add_temp("gongzuo/shoucai",1);
  if ( (int)me->query_temp("gongzuo/shoucai")==6)
 {
  message_vision(CYN"$N干了良久，终于将收割出了一筐好菜。\n"NOR,me);
      ob1=new("/d/pingan/npc/obj/cai2");
      ob1->move(me);
      me->delete_temp("gongzuo/shoucai");
       }
      return 1;
} 
