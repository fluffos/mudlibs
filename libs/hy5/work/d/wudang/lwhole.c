// Room: lwhole.c

#include <ansi.h>;

inherit ROOM;

void create()
{
     set("short", "石壁岩洞");
     set("long", @LONG
这是一天然石洞，不是很深，当太阳升起时能直射全洞。象是有人在
此住过，正面有一石床，左边放有一些石碗，右面的石壁(wall)十分平整。
LONG
        );
     set("exits", ([
         "out" : __DIR__"wanniansong",
             ]));    
     set("item_desc", ([
          "wall" : HIW "  ......彼之力方碍我之皮毛，我之意已入彼骨里。双手支撑，一气贯通。
左重则左虚，而右已去，右重则右虚，而左已去......\n"NOR,
             ]));
     set("no_fight", 1);
     setup();
}

void init()
{
     add_action("do_study", "study");
}

int do_study(string arg)
{
     object me;
     me = this_player();

     if ( !living(me) ) return 0;

     if ((int)me->query_skill("literate", 1) < 10)
      {  write("你字也不认识几个,如何研读无上心法。\n");
        return 0;
      }
     if ( arg =="wall" )
  {
     if( !SKILL_D("taiji-shengong")->valid_learn(me) ) {
	write("依你目前的能力，没有办法学习这种技能。\n");
	return 1;
     }
     message_vision("$N开始面壁琢磨。\n", me);
     if ( (int)me->query("jing")<50) 
      { write("你太累了，还是歇会再研读吧！\n");
        return 1;
      }
     if ((int)me->query_skill("taiji-shengong", 1) >= 101)
     {write("你对着石壁研习一会，只觉所述早已尽藏心胸。\n");
      return 1;
     }
     write("你静心研习石壁上的秘籍，对内功心法有些领悟。\n");

     me->receive_damage("jing", 40);
     me->improve_skill("taiji-shengong", (int)me->query("int"));
     return 1;
   }

     return 0;
  }
