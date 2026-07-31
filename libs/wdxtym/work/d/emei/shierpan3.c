//Room: shierpan3.c 十二盘
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","十二盘");
      set("long",@LONG
这里石阶陡折多弯，号称「十二盘」。你见路边有个八音池，有人正在向
池中击掌(clap)。由此西上可达华严顶，东下则到万年庵。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
	  "eastdown"  : __DIR__"shierpan2",
	  "southwest" : __DIR__"shierpan4",
      ]));
      set("no_clean_up", 0);
      setup();
}
void init()
{
      add_action("do_clap", "clap");
}

int do_clap()
{
      message_vision("池内忽然有蛙大鸣一声，接着群蛙次"
		     "第相合，最后又是一蛙大鸣，群蛙便嘎然\n"
		     "而止，其数正好为八。\n", this_player());
      return 1;
}

int valid_leave(object me, string dir)
{
	int c_skill;

	me = this_player();
	if (dir == "southwest")
	{
		c_skill = me->query_skill("dodge", 1);
		if (me->query("qi") > 40)
		{
			me->receive_damage("qi", 20 + random(20));
			if (me->can_improve_skill("dodge") && c_skill < 100)
			   me->improve_skill("dodge", 1 + me->query_skill("dodge", 1) / 15);
			tell_object(me,"你爬上八十四盘，有些累了。\n");
		} else
		{
			me->set("qi", 0);
			tell_object(me, "你太累了，再也走不动了。\n");
			return -1;
		}
      }
      return 1;
}
