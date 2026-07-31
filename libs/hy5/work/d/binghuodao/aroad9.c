// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void init();
int kan(string);
void create()
{
        set("short", "山坡");
        set("long", @LONG
北去山势益发陡,树木(wood)丛生.
去路,被阻.
LONG );
set("exits", ([
                  "southdown" : __DIR__"aroad4",
                 // "north" : __DIR__"aroad4",        
                // "east" : __DIR__"aroad",
                // "west"  : __DIR__"road6",
        ]));
set("objects", ([
                __DIR__"npc/deer" : 2,
                        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
 set("item_desc", ([
      "pai" : "保护树林  适量砍伐\n",
      "wood" :"一片可砍伐的树林。\n",
      ]) );
        setup();
//        replace_program(ROOM);
}
void init()
{
 add_action("do_kan","kan");
}

int do_kan(string arg)
{
 object me=this_player();
 object ob;
 if (!arg||arg!="wood")
 {
tell_object(me,"你要砍什么？\n");
return 1;}


 if (!present("cai dao",me))
 {
 message_vision("没有刀怎么砍？\n",me);
return 1;
}

if (present("mu chai",me))
 {
 message_vision("你身上不是有了吗？\n",me);
return 1;
}

// if (query_temp("times")==0)
// {
// message_vision("请适量砍伐！\n",me);
//return 1;}
 if(me->query("qi")<20)
  {
message_vision("你的气太虚弱，不能砍！\n",me);
return 1;}

 ob=new(__DIR__"obj/chai");
 ob->move(me);
 me->add("qi",-20);
 add_temp("times",-1);
 message_vision("$N砍了一捆，累得够呛。\n" , me);
 return 1;
}
