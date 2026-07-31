// Room: guanmiao.c
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "关圣庙");
	set("long", @LONG
相传关老爷子旧年曾在这里和周仓争关庙首席之位，周仓说道：“你我谁先跑
到庙里，谁就为大。”关公说：“NOD！”待周仓跑到门口大叫：“别占我的门旮旮”周
仓本是你说不，我偏要之人，往门旮旮一站，关公也就到前面去了。这些不表，且看这
庙里，香火缭绕，长年不断，来进香的人络绎不绝，也可知关二爷在当地人心中是多英
雄的人物。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xidajie2",
		"north" :__DIR__"houdian",
	]));

	setup();
	replace_program(ROOM);
}

