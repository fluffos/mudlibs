//Made by goodtaste

inherit ROOM;
void create()
{
        set("short", "杀手帮广场");
        set("long", @LONG
这里是杀手帮的广场，每年重阳帮主和帮中头领都要在此检阅弟子，声势甚为浩大
LONG
        );
        set("outdoors", "pker");
        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"shijie3",
                "north" : __DIR__"zhonglou",
                "west":__DIR__"dadao21",
                "east":__DIR__"dadao11",
                ]));
          set("objects", ([
             __DIR__"npc/dizi" : 4,
           ]));
        setup();
	"/clone/board/pker_b"->foo();
       
}


void init()
{
   object me;
   me=this_player();
   if((me->query("score")<2000)&&(me->query("max_neili")<500)&&(me->query("shaqi")>100))
  {
      message("vision","你突然觉得心中有一种很郁闷的感觉，好象自己以前作过很多对不起
兄弟，朋友，亲人，爱人，师傅，同门的事情，你越想越怕，血气上涌，
渐渐的失去了知觉.....\n",me);
      me->start_busy(3);
      me->set_temp("unconcious",1);
      me->move(__DIR__"prison");
      message("vision",
		"有个昏迷的家伙被看守丢了进来!\n", environment(me));

   }
}


