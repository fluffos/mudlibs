// This is a room made by zhx.
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是麒麟村中的小路，村中只有十多户人家，多半都是败屋号风，颓垣不
掩。茅檐雪压，冷灶无烟，看去十分残破。而路两边的人家看来境况都还不错，
虽不奢华，却是颇为齐整。南边是一个小广场。
LONG);
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"xiaolu1",
		"east"  : __DIR__"tangyuanwaijia",
		"west"  : __DIR__"zhangyuanwaijia",
	]));

	setup();
	replace_program(ROOM);
}
