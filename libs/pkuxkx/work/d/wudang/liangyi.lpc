// liangyi.c 两仪殿
// by Marz 

inherit ROOM;

void create()
{
	set("short", "两仪殿");
	set("long", 
"殿内贡有三清圣像，四处环列着铁铸灵官像，形态各自不\n"
"同却都栩栩如生。殿内有不少香客在叩头礼拜，此处传说为真\n"
"武显圣赐福之地，因此香火十分旺盛，散到很远处。\n"
	);

	set("exits", ([
		"southdown" : __DIR__"nanyan",
		"north" : __DIR__"houdian",
		"westup" : __DIR__"feisheng",
	]));
	setup();
	replace_program(ROOM);
}

