// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "新手教导处");
	set("long", "这里是啸天会元老向弟子面授机宜的地方，屋子里有不少
书架。架子上放着帮中前辈所留下的手札，里面记着他们练功
的心得。这儿向北就是冷月堂大厅。\n");

	set("exits", ([
                "west" : __DIR__"xs2",
                "north" : __DIR__"yt1",
	]));
	setup();
	replace_program(ROOM);
}

