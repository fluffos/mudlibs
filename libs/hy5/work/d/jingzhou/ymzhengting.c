// Room: /jingzhou/yamenzhengting
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "衙门正厅");
	set("long", @LONG
堂上东西有两根楹住，挂着一幅对联，但是你无心细看。正墙上悬挂一个横匾，上
书“明镜高悬”四个金光闪闪的大字。知府正坐在文案后批阅文书，师爷随侍在后。
LONG
	);

	set("exits", ([
		"north" : __DIR__"jzyamen",
		"south" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/jing" : 1,
		
	]));

	setup();
	replace_program(ROOM);
}

