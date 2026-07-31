//room: ya.c
inherit ROOM;

void create()
{
  set("short","断魂崖");
  set("long",@LONG
这是通向[灵鹫宫]的必经之路，一条小道蜿蜒曲折地通向缥缈峰顶。
路的右侧是一条陡峭的山崖，一阵山风吹过，你似乎听见从下面传来几声
惨号，你心中一凛，不禁加快脚步赶紧离开这里。
LONG );
  set("outdoors", "lingjiu");
  set("exits",([
      "westup"   : __DIR__"yan",
      "eastdown" : __DIR__"shanjiao",
  ]));
  
	set("objects",([
		CLASS_D("lingjiu") + "/sang" : 1,
		CLASS_D("lingjiu") + "/zhuo" : 1,
		//CLASS_D("lingjiu") + "/zuo" : 1,		
		CLASS_D("lingjiu") + "/duanmu" : 1,			
	]));  
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
