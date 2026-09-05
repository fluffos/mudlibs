// zuodian.c 左配殿
// by Xiang

inherit ROOM;

void create()
{
	set("short", "左配殿");
	set("long", 
"这是一间颇大的殿房，但是光线很暗，神台上贡着几个不\n"
"知名的天尊。一群小道士盘腿坐着，嘴里念念有词。也不知是\n"
"读的什么经书，东边是三清殿，香火的烟气这里都能闻到。西\n"
"面不知是什么地方，隐约飘来一丝香气，嗯，肚子真饿呀。\n"
	);

	set("exits", ([
		"west" : __DIR__"kefang1",
		"east" : __DIR__"sanqing",
	]));
	set("objects",([
		CLASS_D("wudang") +"/daotong" : 1,
		]));
	setup();
	replace_program(ROOM);
}

