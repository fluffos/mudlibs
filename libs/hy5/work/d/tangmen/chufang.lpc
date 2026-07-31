//ROOM: /d/tangmen/chufang.c

inherit ROOM;

void create()
{
	set("short","厨房");
	set("long",@LONG
     这里是唐门的厨房。阵阵川菜独特的香味扑鼻而来，让人竟不住口水都快流
到下巴了。据说唐门的厨师当年还进过御厨，专为皇帝老儿煮川菜。房中挂着串串辣
椒，这是川菜最重要的调味品。
LONG
     );
	set("exits",([
		"south" : __DIR__"duanmuting",
  ]));
	set("objects",([
		__DIR__"npc/wangsao" : 1,
		__DIR__"obj/shan" : 1,
		__DIR__"obj/roupian" : 3,  
  ]));
 
 setup();
 replace_program(ROOM);
}