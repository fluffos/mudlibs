//tingxiang.c
//by hehe
//2003.3.5

inherit ROOM;

void create()
{
	set("short", "听香水榭");
	set("long", @LONG
小舍匾额上写着"听香水榭"四字,笔致颇为潇洒。厅内放着三四张藤椅，
房间并不是很大，但很别致，处处透出江南水乡的意味。一个老仆来回
端着茶具殷勤送茶。
LONG
	);

	set("outdoors", "murong");
	set("exits", ([ 
        "south" : __DIR__"tchufang",
		"east" : __DIR__"troad6",
		]));

	set("objects", ([
                CLASS_D("murong/azhu"): 1,
		]));

	set("no_clean_up", 0);
	set("outdoors", "murong");

	setup();
	replace_program(ROOM);
}
