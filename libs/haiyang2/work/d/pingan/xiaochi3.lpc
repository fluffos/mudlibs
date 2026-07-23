// Room: /d/pingan/chufang

#include <ansi.h>
inherit ROOM;
int do_zuo(string arg);

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG
这儿是小吃店的厨房，干净整齐，墙边的柜子里放着整整齐齐的餐具。
厨房有很多的厨具你可以在这里（zuocai）些什么。
LONG);

  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan",1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaochi2",
]));

  setup();
}

void init()
{
        add_action("do_zuo","zuocai");
}

int do_zuo(string arg)
{
        object me=this_player(); 
        object ob,ob1;
        if (!me->query_temp("gongzuo/zuocai"))
           return notify_fail("你还是先去给大师傅打个招呼吧。\n");

        if (!arg || arg != "各种各样的菜")
           return notify_fail("你要做什么？\n");

        if (!(ob = present("cai", this_player())))
                return notify_fail("你身上没有菜，怎么能做呢？。\n");

        if ( (int)me->query("jing")<20)
           return notify_fail("你太累了，歇息下吧。\n");

        if (me->query_temp("gongzuo/zuocai")==6)
           return notify_fail("菜做好了！送回管事那儿吧。\n");
   
  message_vision("$N拿起厨具，开始做起菜来。\n",me);
      me->add("jing",-(10+random(10)));
      me->add_temp("gongzuo/zuocai",1);
  if ( (int)me->query_temp("gongzuo/zuocai")==6)
 {
  message_vision(CYN"$N做了良久，终于将做出了一盘好菜。\n"NOR,me);
        ob->set_name( "做好的菜" , ({"goodcai"}));
        ob->set("long","一盘刚做好的菜。\n");
//      destruct(ob);
//      ob1=new("/d/pingan/npc/obj/panzi");
//      ob1->move(me);
 }
      return 1;
} 
