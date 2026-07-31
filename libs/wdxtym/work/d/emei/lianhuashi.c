//Room: lianhuashi.c 莲花石
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","莲花石");
      set("long",@LONG
这是莲花石。此处岩石纹理纵横，形似莲花，颜如芙蓉，仿佛萼瓣层叠，
细蕊欲绽。上有一庵，叫「莲花社」。由此往西上直达洗象池，东下左通华严
顶，右通九老洞。
LONG);
      set("objects", ([
	   CLASS_D("emei") + "/su" : 1,
	   CLASS_D("emei") + "/ling" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
	  "southeast" : __DIR__"jldongkou",
	  "eastdown"  : __DIR__"huayanding",
	  "westup"    : __DIR__"ztpo1",  
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
