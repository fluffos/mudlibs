// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里便是沥泉山上崎岖不平的山路。行到此处，已是半山腰，东首一个小平
台上茂林里，两扇柴扉掩着一座小庵，在这荒山野岭之间显得超然尘世之间，看
来内中应是得道高僧。不如进去拜访一下，小坐片刻罢。
LONG);
	set("outdoors", "沥泉山");

	set("exits", ([
		"westdown" : __DIR__"shanlu5",
		"northup" : __DIR__"shanlu7",
		"east" : __DIR__"sengshe",
	]));

	setup();
	replace_program(ROOM);
}
