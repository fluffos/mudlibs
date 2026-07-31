//Cracked by Roath
// Room: /d/murong/qing2
//arthurgu /1999.9

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
	set("exits", ([ 
        "south" : __DIR__"qing1",
        "north" : __DIR__"qing3",
                      ]));
	set("no_clean_up", 0);
        set("objects", ([
		"/d/murong/npc/abi" : 1,
		]));

	setup();
	replace_program(ROOM);
}
