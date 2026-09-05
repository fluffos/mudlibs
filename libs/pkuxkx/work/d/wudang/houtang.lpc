// houtang.c 后堂
// by llin

inherit ROOM;

void create()
{
	set("short", "后堂");
	set("long", 
"这里已经是武当的内院了，进进出出都是武当门下的弟子，\n"
"一般客人没有许可是不能进来的。左面两个小道童垂手侍立，\n"
"旁边站着一位神色严肃的中年人。用敏锐的目光打量着你，使\n"
"你不由的有些顾虑，脚步也放轻了些。\n"
	);
	set("exits", ([
		"south" : __DIR__"sanqing",
		"west"  : __DIR__"xiaodao",
		"north" : __DIR__"qianyuan",
		"east"  : __DIR__"shanfang",
	]));
	set("objects",([
		CLASS_D("wudang") +"/xi" : 1,
		]));
	setup();
	replace_program(ROOM);
}

