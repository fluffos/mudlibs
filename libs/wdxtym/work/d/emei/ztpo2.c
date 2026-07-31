//Room: ztpo2.c 钻天坡
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","钻天坡");
      set("long",@LONG
莲花石与洗象池之间，道路陡绝，石栈若齿，直上蓝天，石蹬达一千三百
多级，是在陡峭山壁上开凿出来的坡道。人行其上，前后顶踵相接，一如登天。
这段路叫「鹁鸽钻天」，这段陡坡也因此而叫「钻天坡」。这里西上坡顶便到
洗象池，东下可达莲花石。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
	  "eastdown"  : __DIR__"ztpo1",
	  "westup"    : __DIR__"xixiangchi",  
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
