// Room: /chengdu/wuchi.c
// oooc: 1998/06/25 

inherit ROOM;

void create()
{
        set("short", "武侯祠");
	set("long", @LONG
这里就是闻名天下的武侯祠。埋葬着三国时代的一代贤臣诸葛
武侯的地方。四周参天大树环绕着巨大陵墓，环境十分幽静，偶尔
能听到几声鸟鸣，平时很少有人来打扰一代英魂的清宁。
LONG
	);
        set("no_fight", 1);

	set("exits", ([
                "east" : __DIR__"beijie",
	]));

	setup();
	replace_program(ROOM);
}

