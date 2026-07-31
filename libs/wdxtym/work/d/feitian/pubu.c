#include <room.h>
inherit ROOM;
#include <ansi.h>  
void create()
{
        set("short", "瀑布");
        set("long", @LONG
你穿过树林居然来到了瀑布边，震耳欲聋的水声从更高的山上咆哮而下，
一条条银练击打着岩石，溅起串串水珠，在阳光的照射下，分外吸引人。
据说剑心常在这里练剑。
LONG);
        set("exits", ([
		"west" : __DIR__"shulin2",
        ]));
        set("outdoors","feitian");
        setup();
}

void init()
{
        add_action("do_jump","jump");
    add_action("do_enter", "enter");
}

int do_jump(string arg)
{
          object ob;
        object me;

          me=this_player();
          if (!arg || arg!="pubu")
              return notify_fail("你要跳到哪里去？\n");
          message_vision("只见$N施展五行遁中的水遁，犹如一道银链穿瀑而过！\n",me);
          if ((me->query_skill("dodge",1)<101) || (me->query_skill("wuxing-dun",1)<101))
             {
          message_vision("只见$N施展轻功快要飞过去时，被瀑布强大的冲击力打了下去！\n",me);
                 message_vision("$N面色苍白失声尖叫起来.............................\n",me);
          this_player()->unconcious();
          return 0;
        }
          me->move(__DIR__"pingtai");
          message_vision("只见$N脚一点地，跳了进来！\n",me);
          return 1;
}

int do_enter ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="midao" ) 
       {
         tell_object(this_player() , "你要去哪儿？\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    if( ob->query("family/family_name") != "飞天御剑流")
{
     message_vision("$N这是飞天御剑流的密道,你不认识路!\n",  ob);
    return 1;
}

    if(!ob->query_temp("shirenok"))
{
     message_vision("$N你先去探一下树林中的情况吧!!\n",  ob);
    return 1;
}

    ob->move("/d/feitian/jiedao3") ;
    tell_object(ob, BLU "你看清了小路，直接走出了树林!\n" NOR ) ;
    return 1 ;
}