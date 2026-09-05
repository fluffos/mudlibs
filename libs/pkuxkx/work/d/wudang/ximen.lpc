// ximen.c 西侧门
// by llin

inherit ROOM;

void create()
{
	set("short", "西侧门");
	set("long", 
"一道圆形小门，出门便是一片幽静的松林，沿着林间小径\n"
"方向望去，隐约可见一座道观。\n"
	);

	set("exits", ([
		"west" : __DIR__"fuzhen",
                "east" : __DIR__"qianyuan",
	]));
	setup();
	replace_program(ROOM);
}

