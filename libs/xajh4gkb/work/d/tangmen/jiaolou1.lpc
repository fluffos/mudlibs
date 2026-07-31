//room: /d/tangmen/jiaolou1.c
// by HEM 
inherit ROOM;

void create()
{
  set("short","西北角楼");
  set("long",
      "这是唐家堡的了望角楼。唐门虽声名显赫，势力庞大，但是也树敌不少。\n"
      "为防外敌突袭，所以四周都有这样的角楼。有一队武士在这儿巡逻。\n"
     );

  set("exits",([
       
	"eastdown" : __DIR__"huayuan4",
	
	]));
	set("objects", ([
		__DIR__"npc/longzuwushi" : 4,
	]));

 setup();
 replace_program(ROOM);
}
