// milin5.c 密林
// seagate@pkuxkx 路径动态更新

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", 
"林中阴森森的，除了几声鸟叫外再没有其他的声音，四周\n"
"都是参天大树，遮天蔽日。脚下是厚厚的落叶，看不出有什么\n"
"人迹，显得格外怕人。\n"
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