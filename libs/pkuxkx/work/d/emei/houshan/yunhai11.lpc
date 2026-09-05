// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "云海");
set("outdoors","emei");
	set("long", @LONG
这里就是峨嵋著名的云海了，放眼望去，漫山遍野都
是云雾，根本就弄不清自己身在何出，四周都是出路，什
么都看不清楚。
LONG   );
  
	setup();
	
}

void init()
{
  object me = this_object();
  me->set("exits/east",__DIR__"yunhai12");
  me->set("exits/west",__DIR__"yunhai1"+random(3));
  me->set("exits/north",__DIR__"yunhai1"+random(3));
  me->set("exits/south",__DIR__"yunhai1"+random(3));
}
