//qinyun.c
//by hehe
//2003.3.6

inherit ROOM;

void create()
{
	set("short", "琴韵小居");
	set("long", @LONG
小舍匾额上写着"琴韵"两字,笔致颇为潇洒。厅内放着三四张藤椅，
房间并不是很大，但很别致，处处透出江南水乡的意味。一个老仆来回
端着茶具殷勤送茶。
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
		"north" : __DIR__"qroad3",
		"west" : __DIR__"qxiufang",
		]));
	set("objects", ([
		"/d/murong/npc/abi" : 1,
		]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

