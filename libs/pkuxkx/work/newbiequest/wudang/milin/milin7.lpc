// milin7.c 密林
// seagate@pkuxkx 路径动态更新

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", 
"林中阴森森的，除了几声鸟叫外再没有其他的声音，四周\n"
"都是参天大树，遮天蔽日。脚下是厚厚的落叶，仿佛可以辨出\n"
"北边有一条被枯枝落叶掩盖的小路，歪歪曲曲的不知通向何处。\n"
	);
	set("exits", ([
		"south"  : __DIR__"milin1",
		"north"  : "/d/wudang/feng",
	]));
  set("outdoors", "wudang");
	set("dynroom/static_exits", ({"north"}));  //如果存在固定方向则配置此属性
	set("dynroom/type",1);                     //1为动态房间，0为固定房间
	set("no_clean_up",1);
	
	setup();
}

void reset()
{
	::reset();
	set("no_clean_up",1);
}