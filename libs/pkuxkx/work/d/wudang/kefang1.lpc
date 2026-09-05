// kefang1.c 客房
// by llin

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", 
"这里是武当派接待远来的进香客和拜山的客人的地方，桌\n"
"上摆着一桌素宴，几个香客和一身江湖打扮的人正在狼吞虎咽，\n"
"山野之处也不输了待客之道，武当不愧为江湖名门大派。\n"
	);
	set("exits", ([
		"east" : __DIR__"zuodian",
	]));
	set("objects",([
		__DIR__"obj/baicai" : 1,
		__DIR__"obj/zhou" : 2,
		__DIR__"obj/shanyao" : 1,
	]));
	setup();
	replace_program(ROOM);
}
