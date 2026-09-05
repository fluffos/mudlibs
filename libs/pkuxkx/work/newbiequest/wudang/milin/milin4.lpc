// milin4.c 密林
// seagate@pkuxkx 路径动态更新

inherit ROOM;

void create()
{
	set("short", "山涧");
	set("long", 
"林中的一片碎石滩上从远处流淌下来的山泉叮叮咚咚得响\n"
"着，给静寂的丛林带来了一片生机。\n"
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