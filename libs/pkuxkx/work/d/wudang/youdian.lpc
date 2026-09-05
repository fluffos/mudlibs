// youdian.c 右配殿
// by Xiang

inherit ROOM;

void create()
{
	set("short", "右配殿");
	set("long", 
"这是一间颇大的殿房，但是光线很暗，神台上贡着几个不\n"
"知名的天尊。一群小道士盘腿坐着，嘴里念念有词。也不知是\n"
"读的什么经书，东边是一扇门。听不到有什么动静，也不知有\n"
"什么人在里面。\n"
	);

	set("exits", ([
		"east" : __DIR__"kefang2",
		"west" : __DIR__"sanqing",
	]));
	set("objects",([
		CLASS_D("wudang") +"/daotong" : 1,
		]));
	setup();
	replace_program(ROOM);
}

