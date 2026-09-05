// This is a room made by roommaker.
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "小广场");
	set("long", @LONG
这里是麒麟村中的一个小广场，场地中依稀还有过年时遗下的鞭炮屑，诉说
着逝去的繁华。西边是一个小小的土地庙，早已破败不堪，南北各是一条小路，
而东边便是出村的路了。
LONG);
	set("exits", ([
		"east"  : __DIR__"xiaolu4",
		"west"  : __DIR__"tudimiao",
		"south" : __DIR__"xiaolu3",
		"north" : __DIR__"xiaolu2",
	]));

	setup();
	replace_program(ROOM);
}