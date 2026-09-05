// Room: /d/diaoyudao/youzhang.c 右帐
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "右帐");
	set("long", @LONG
你走进右帐，里面炊烟缭绕，蒸汽腾腾，香味扑鼻而来。帐边砌
着一个灶台，灶上放着一个蒸笼(steampot)。锅子及蒸笼正冒著阵阵
的热气以及香气, 你忍不住想打开来看看。一个老头正忙着劈柴运薪，
灶下炉火熊熊。
LONG
	);
	
	set("exits", ([
                 "west" : __DIR__"dazhang",
		 "east": __DIR__"zhangout",
	]));
	set("objects", ([
                __DIR__"npc/yufu" : 1,
        ]));

	set("item_desc", ([
             "steampot": "一个竹藤编成的蒸笼, 阵阵的香味使你想打开(open)来瞧一瞧。\n"
	]) );

	setup();
}

void init()
{
   add_action("do_open", ({"open"}) );
   add_action("do_take", ({"take"}) );
}

int do_open(string arg)
{
   if (!arg||arg!="steampot")
      return notify_fail("你要打开什么？\n");
   if (!present("cook bonze"))
      {
       message_vision("$N打开蒸笼的盖子, 一股热气冒向$N的脸上。\n"
                      "$N仔细一看, 只见蒸笼里排著一粒粒的糯米团子(tuanzi)。\n",this_player());
       return 1;
      }
   else{
       message_vision("老头道:请勿动手动脚, 妨碍我煮饭。\n",this_player());
       return 1;
      }
}

int do_take(string str)
{
   object ob;
   if (!str||str!="tuanzi")
       return notify_fail("你要拿什么？\n");
   if (!present("cook bonze"))
      {
       if ((int)query("maintal_trigger")>=5)
          {
           return notify_fail("拿那么多不嫌烫手呀!!\n");
          }
       else
          {
           message_vision("$N从蒸笼里拿出一粒热乎乎的糯米团子。\n",this_player());
           ob=new(__DIR__"npc/obj/tuanzi");
           ob->move(this_player());
           add("maintal_trigger",1);
           return 1;
          }
      }
   else
      {
       message_vision("老头道: 施主偷东西是不好的行为哦!!!\n",this_player());
       return 1;
      }
}

void reset()
{
        ::reset();
        delete("maintal_trigger");
}

