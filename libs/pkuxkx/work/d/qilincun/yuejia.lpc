// zhx 2006/12/27
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "岳飞家");
	set("long", @LONG
这里便是岳飞的家。那积雪下面露出来的茅顶，由于多年的雨淋日晒，大部
分已成了灰黑色。但是草铺得相当厚，上面还盖有一层半新的茅草，左右墙脚还
支住两根树桩。只管墙上土色新旧不同，好似修补过多次，比其他人家却较干净
一些。
LONG);
	set("exits", ([
		"east" : __DIR__"xiaolu3",
	]));
	set("objects", ([
		__DIR__"npc/yuemu": 1,
	]));

	setup();
	replace_program(ROOM);
}