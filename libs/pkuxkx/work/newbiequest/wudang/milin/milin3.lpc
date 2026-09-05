// milin3.c 密林
// seagate@pkuxkx 路径动态更新

inherit ROOM;

void create()
{
	set("short", "林间空地");
	set("long", 
"四周都是参天的大树，连阳光都射不进来，林间的空间上\n"
"洒落星星点点的午间阳光，吸引附近的鸟雀在这里聚集。\n"
	);
	set("exits", ([
		"north"  : __DIR__"milin2",
		"west"   : __DIR__"milin1",
		"east"   : __DIR__"milin1",
	]));
  set("outdoors", "wudang");
	set("dynroom/type",1);                     //1为动态房间，0为固定房间
	set("no_clean_up",1);
	
	setup();
}

void reset()
{
	::reset();
	set("no_clean_up",1);
}