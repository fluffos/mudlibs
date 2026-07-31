// /d/taiyuan/road6.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "双塔寺");
	set("long", @LONG
双塔寺在太原东南郊郝庄村南。明万历三十六年(1608年)高僧福登奉敕建造。
寺内主要建筑，全为砖构。八角十三级，高54.7米。塔内有阶梯踏道，可登顶层，
凭窗远眺，太原风光历历在目。人们出入太原，双塔首先映入眼帘，成为太原的
标志。寺内牡丹遍地，传为明代所植。
LONG );
	set("exits", ([
	       "north" : "/d/mayi/xiaolu2",
		"southwest" : __DIR__"road5",
                "southeast" : __DIR__"road7",
	]));

	set("outdoors", "taiyuan");
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



