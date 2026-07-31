//Room: wannianan.c 万年庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","万年庵");
      set("long",@LONG
万年庵建在一座突起的山峰上，周围古木森森，清泉淙淙，闲步无坎，吟
游无坷，景色非常迷人。由此西上过十二盘可达华严顶，南下至白龙洞。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
	  "southdown" : __DIR__"bailongdong",
	  "westup"    : __DIR__"shierpan1",
	  "enter"     : __DIR__"wnadian",
      ]));
      setup();
}

int valid_leave(object me, string dir)
{
	int c_skill;

	me = this_player();
	if (dir == "westup")
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
