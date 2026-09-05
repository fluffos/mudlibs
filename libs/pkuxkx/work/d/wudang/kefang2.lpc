// kefang2.c 客房
// by Xiang

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", 
"这里是武当派招待远来客人暂时休息的地方。屋子里很暗，\n"
"只能依稀看见一张大床，床上东倒西歪的睡着几个人，让人顿\n"
"时觉得睡意朦胧，只想躺下好好的睡他一觉。\n"
	);
	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"youdian",
	]));
	set("objects",([
		CLASS_D("wudang") +"/daotong" : 1,
		]));
	setup();
	set("no_fight",1);
}
