// milin2.c 密林
// seagate@pkuxkx 路径动态更新

inherit ROOM;

void create()
{
	set("short", "倒下的巨树");
	set("long", 
"树林中巨大的柏树从中间断了一截，斜靠在旁边古老的榆树\n"
"叉上，桥下似乎有一条小路通向未知的丛林。\n"
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